function [ x, xdot, xddot, t ] = generate_trajectory_jerk_viapoint( x0, xf, tf, dt, x1, t1 )
%GENERATE_TRAJECTORY_JERK_VIAPOINT Summary of this function goes here
%   Detailed explanation goes here
    s1 = 0:dt:t1;
    s2 = t1+dt:dt:tf;
    tau1 = s1/tf;
    tau2 = s2/tf;
    
    v = t1/tf;
    
    c = 1/( tf^5*v^2*(1-v)^5 )*( (xf - x0)*(300*v^5 - 1200*v^4 + 1600*v^3 )+...
        v^2*(-720*xf+120*x1 + 600*x0) + (x0 - x1)*(300*v-200)) ;
    
    pai = 1/(tf^5*v^5*(1-v)^5)*((xf - x0)*(120*v^5-300*v^4+200*v^3)-20*(x1-x0));
    
    xm = tf^5/720*( pai*(v^4*(15*tau1.^4 - 30*tau1.^3) + v^3*(80*tau1.^3 - 30*tau1.^4)-...
        60*tau1.^3*v^2 + 30*tau1.^4*v - 6*tau1.^5) + c*(15*tau1.^4 - 10*tau1.^3 - 6*tau1.^5))+x0;
    
    xp = tf^5/720*( pai*(v^4*(15*tau2.^4 - 30*tau2.^3 + 30*tau2 - 15) + ...
         v^3*( -30*tau2.^4 + 80*tau2.^3 - 60*tau2.^2 + 10)) + c*(-6*tau2.^5+15*tau2.^4-10*tau2.^3+1))+xf;
     
    x = [xm,xp];
    t = [s1,s2];
    
    xdot = (x(:,3:end) - x(:,1:end-2))/(2*dt) ;
    xdot = [zeros(size(x0)),xdot,zeros(size(x0))];
    
    xddot = (x(:,3:end) + x(:,1:end-2) - 2*x(:,2:end-1) )/(dt^2);
    xddot = [zeros(size(x0)),xddot,zeros(size(x0))];

end

