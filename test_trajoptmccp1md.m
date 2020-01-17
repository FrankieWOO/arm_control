mccp1md = Mccpvd1dofModel();

x0 = [0;   0;   0;   1;   0;   0];
%xf = -0.3 ; 
%xf = 0.7;
xf = [0.7; 0; 0.7; 0.5;0 ;0];
testtraj = TrajOptMccp1MD.reachFastIlqr(mccp1md, x0, xf, 'tf', 0.8 , 'dt', 0.01, 'm2min', 1, 'sfactor', 1, 'ConstraintType', 2);

stepinfo(testtraj.x(1,:), testtraj.t, 0.7, 'SettlingTimeShreshold', 0.02 )
plot_mccp1md(testtraj)
%%
x0 = [0;   0;   0;  0.1;   0;   0];
%xf = [0.7; 0; 0.7; 0.1 ;   0;   0];
xf = 0.7;
testtraj1 = TrajOptMccp1MD.reachFastIlqr_fixu1(mccp1md, x0, xf, 'tf', 0.7, 'dt', 0.01, 'm2min', 0.5, 'sfactor', 1);
stepinfo(testtraj1.x(1,:), testtraj1.t, 'SettlingTimeShreshold', 0.02)
plot_mccp1md(testtraj1)

