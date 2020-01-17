

%% generate min jerk trajectory
% unconstrained point-to-point optimization
% refer to the paper Flash and Hogan: The coordination of arm movements

x0=[0;0];
xf = [pi/2;pi/3];

[t, x, xdot,xddot] = generate_trajectory_jerk(x0, xf, 0.7, 0.02);
%y = generate_trajectory_jerk(y0,yf,0.7,0.02);

figure
subplot(2,3,1)
%hold on
plot(t,x(1,:))
title('x')

subplot(2,3,2)
plot(t,xdot(1,:))

subplot(2,3,3)
plot(t,xddot(1,:))

subplot(2,3,4)
%hold on
plot(t,x(2,:))
title('y')

subplot(2,3,5)
plot(t,xdot(2,:))

subplot(2,3,6)
plot(t,xddot(2,:))

%%

x1 = [pi/4;pi/6];
t1 = 0.4;
[x, xdot,xddot, t] = generate_trajectory_jerk_viapoint(x0,xf,0.7,0.02, x1,t1 );

figure
subplot(2,3,1)
hold on
plot(t,x(1,:))
plot(t1,x1(1),'ro','MarkerSize',3)
title('x')
hold off

subplot(2,3,2)
plot(t,xdot(1,:))

subplot(2,3,3)
plot(t,xddot(1,:))

subplot(2,3,4)
hold on
plot(t,x(2,:))
plot(t1,x1(2),'ro','MarkerSize',3)
title('y')
hold off

subplot(2,3,5)
plot(t,xdot(2,:))

subplot(2,3,6)
plot(t,xddot(2,:))