function [ y, ydot, yddot, t ] = generate_trajectory_2nd( x0, xt, alpha)
%GENERATE_TRAJECTORY_2ND Summary of this function goes here
%   Detailed explanation goes here
    sdt = 0.001;
    x = x0;
    xdot =0;
    xddot=0;
    y(1) = x0;
    ydot(1) = 0;
    yddot(1) = 0;
    t = 0;
    n =2;
    while abs(x - xt)>1e-10
        xddot = alpha^2*(xt - x) - 2*alpha*xdot;
        xdot = ydot(n-1) + xddot*sdt;
        x = x + ydot(n-1)*sdt;
        
        y(n) = x;
        ydot(n) = xdot;
        yddot(n) = xddot;
        t(n) = t(n-1)+sdt;
        n = n+1;
        
    end
    


end

