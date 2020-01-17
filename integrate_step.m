function [ xn ] = integrate_step( f, x, dt )
%INTEGRATE_STEP integrate dynamical system (uncontrolled) to give next
%state using 4th RK method
%   f: dynamical system 
%   x: state vector        
	g1 = dt*f(x);
	g2 = dt*f(x+.5*g1);
	g3 = dt*f(x+.5*g2);
	g4 = dt*f(x+   g3);
	xn = x + (1/6)*(g1 + 2*g2 + 2*g3 + g4);
end

