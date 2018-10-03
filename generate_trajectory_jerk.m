function [ x, xdot, xddot, t ] = generate_trajectory_jerk( x0, xf, tf, dt )
%GENERATE_TRAJECTORY_JERK Summary of this function goes here
%   Detailed explanation goes here
    t = 0:dt:tf;
    
    tau = t/tf;
    
    x = x0 + (x0 - xf)*( 15*tau.^4 - 6*tau.^5 - 10*tau.^3 );

    %xdot = (x(:,3:end) - x(:,1:end-2))/(2*dt) ;
    %xdot = [zeros(size(x0)),xdot,zeros(size(x0))];
    xdot = gradient(x);
    %xddot = (x(:,3:end) + x(:,1:end-2) - 2*x(:,2:end-1) )/(dt^2);
    %xddot = [zeros(size(x0)),xddot,zeros(size(x0))];
    xddot = gradient(xdot);
end

