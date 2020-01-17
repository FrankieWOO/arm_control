function [ y ] = explicitSol_2ndCrtDmp( y0, u, T, a, dt )
% explicit solution for 2nd order critical damped system
t = 0:dt:T;
y = y0*exp(-a.*t) + a*y0.*t.*exp(-a.*t)+( 1 - exp(-a.*t)- a*t.*exp(-a.*t) )*u;

end

