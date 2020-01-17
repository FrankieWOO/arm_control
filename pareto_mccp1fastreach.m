robot = Mccpvd1dofModel();
%%
x0 = [0;   0;   0;   1;   0;   0];
xf = 0.7 ; 
% xf = [0.7;0; 0.7; 1; 0; 0];
% sfactor = 1;
% traj = TrajOptMccp1.reachFastIlqr(robot, x0, xf, 'tf', 1.2 , 'dt', 0.01, 'm2min', 0.1, 'sfactor', sfactor);
% traj.sinfo = stepinfo(traj.x(1,:), traj.t, xf(1), 'SettlingTimeThreshold', 0.02);
% traj.info.SettlingTime = traj.sinfo.SettlingTime;
% traj.info.sfactor = sfactor;
% traj.info.Ein = traj.Ein;
% traj.info.q0 = x0(1);
% traj.info.qf = xf(1);
% traj.info
%%
sfactors = 0.1:0.1:10;

trajs = cell(length(sfactors),1);

for i=1:length(trajs)
    sfactor = sfactors(i);
traj = TrajOptMccp1.reachFastIlqr(robot, x0, xf, 'tf', 1.2 , 'dt', 0.01, 'm2min', 0.1, 'sfactor', sfactor);
traj.sinfo = stepinfo(traj.x(1,:), traj.t, xf(1), 'SettlingTimeThreshold', 0.02);
traj.info.SettlingTime = traj.sinfo.SettlingTime;
traj.info.sfactor = sfactor;
traj.info.Ein = traj.Ein;
traj.info.q0 = x0(1);
traj.info.qf = xf(1);
%traj.info
trajs{i} = traj;
end

%%
figure
hold on
for i=1:length(trajs)
    scatter(trajs{i}.info.Ein, trajs{i}.info.SettlingTime)
end
hold off