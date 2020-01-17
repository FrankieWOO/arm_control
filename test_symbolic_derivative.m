robot = Mccpvd1Dof();

B = robot.B;
C = robot.C;
A0 = 0.099; % C - B
Ks = 394; %231 % spring constant
r = 0.015;
Dm = 0.0339;

% q, qdot, th1, th2, th3
syms F(x1,x2,x3,x4,x5)

F(x1,x2,x3,x4,x5) = Ks*B*C*sin(x3-x1)*(1+ (r*x4 - A0)/sqrt(B^2+C^2-2*B*C*cos(x3-x1)) ) - Dm*x5*x2;

%%
df1 = diff(F,x1);
df2 = diff(F,x2);
df3 = diff(F,x3);
df4 = diff(F,x4);
df5 = diff(F,x5);
%%
df1n = matlabFunction(df1);
df2n = matlabFunction(df2);
df3n = matlabFunction(df3);
df4n = matlabFunction(df4);
df5n = matlabFunction(df5);
Fn = matlabFunction(F);
Ju = [df3,df4,df5];
Ju = matlabFunction(Ju);
param.Ju = Ju;
param.Jq = df1n;
param.Jqdot = df2n;
param.Kp = 0;
param.F = Fn;
param.N = eye(3);
param.N(3,3)=0.1;
%%

q0 = 0;
qf = pi/4;
tf = 0.5;
dt = 0.01;
[t, q_des, qd_des, qdd_des] = generate_trajectory_jerk(q0, qf, tf, dt);

tau_d = robot.desired_torque(q_des, qd_des, qdd_des);
taudot_d = gradient(tau_d, dt);
taud = tau_d;
%%

% initiate states
x.q = 0;
x.qd = 0;
x.qdd = 0;
x.m1 = 0;
x.m2 = 0.1;
x.m3 = 0;


u = zeros(3, length(t));
u0 = [x.m1; x.m2; x.m3];
u(:,1) = u0;
v = zeros(3, length(t-1));
vns = zeros(3,1);

BCv = [-6.8, 6.8;
       -6.8, 6.8;
       -inf, inf];
BCu = [-pi/3, pi/3;
       0,   pi/2;
       0,   1];
%%


for 2 = 1:length(t)-1 % iterate in time
    % compute desired qdd
    qdderr(i) = (q_des(i+1)-x.q)/(dt^2);
    taud(i) = robot.desired_torque(x.q, x.qd, qdderr(i));
    taudc(i) = robot.desired_torque(x.q, x.qd, x.qdd);
    vi = nscontroller_mccpvd(x, taud(i), (taud(i)-taudc(i))/dt, vns, param);
    vi = min(max(vi,BCv(:,1)),BCv(:,2));
    uip = u(:,i) + vi*dt;
    uip = min(max(uip,BCu(:,1)), BCu(:,2));
    vi = (uip - u(:,i))/dt;
    v(:,i) = vi;
    u(:,i+1) = uip;
    % update
    xn = robot.step([x.q; x.qd],u(:,i),dt,dt);
    x.qdd = robot.accel([x.q; x.qd],u(:,i));
    x.q = xn(1);
    x.qd = xn(2);
    
    x.m1 = u(1,i+1);
    x.m2 = u(2,i+1);
    x.m3 = u(3,i+1);
end


%u = [u0,u0+cumsum(v,2)*dt];

%%
xx0 = [0;0];
uu = u;
uu(:,end)=[];
%uu(:,end)=[];
%simp.dt = dt;
%simp.solver = 'rk4';
%f = @(xx,uu)robot.dynamics0(xx,uu);
simx = robot.simulate_feedforward(xx0,uu,dt);
simqddot = robot.accel(simx(:,1:end-1),uu);

%%




figure(1)
subplot(3,1,1)

plot(t,q_des)
ylabel('q')
title('desired trajectory')

subplot(3,1,2)
plot(t,qd_des)
ylabel('\dot{q}')

subplot(3,1,3)
plot(t,tau_d)
ylabel('\tau')
xlabel('Time (s)')

figure(2)
plot(t,u)
title('resolved trajectory of internal variables')
xlabel('Time (s)')
ylabel('u')
legend('u1','u2','u3')

figure(3)
subplot(3,1,1)
title('desired vs simulated')
hold on
plot(t,simx(1,:))
plot(t,q_des)
legend('sim','desired')
hold off
ylabel('q')
subplot(3,1,2)
hold on
plot(t,simx(2,:))
plot(t,qd_des)
hold off
ylabel('qdot')
subplot(3,1,3)
hold on
plot(t,gradient(simx(2,:))/dt)
plot(t,qdd_des)
plot(t(1:end-1),simqddot)
hold off
ylabel('qddot')