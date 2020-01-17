function [  ] = plot_mccp1md( D_eval1 )
%PLOT_MCCP1 Summary of this function goes here
%   Detailed explanation goes here
t = D_eval1.t;
figure
subplot(311)
hold on
plot(t, D_eval1.x(1,:))
plot(t, D_eval1.x(3,:))
title('Joint & EP trajectories')
legend('Joint','EP')
hold off
subplot(312)
plot(t, D_eval1.x(4,:))
ylim([0 pi/2])
title('Stiffness Motor')
subplot(313)
plot(t(1:end-1), D_eval1.u(3,:))
title('Damping')

end

