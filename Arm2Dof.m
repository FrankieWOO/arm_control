classdef Arm2Dof
    %ARM2DOF Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
    end
    
    methods
        
        function [xn] = step(model, x, u, dt)
            %tic
            sdt = 0.001;
            t = 0;
            while t < dt
            g1 = sdt*model.dynamics(x            ,u);
            g2 = sdt*model.dynamics(x+.5*g1,u);
            g3 = sdt*model.dynamics(x+.5*g2,u);
            g4 = sdt*model.dynamics(x+   g3,u);
            x = x + (1/6)*(g1 + 2*g2 + 2*g3 + g4);
            t = t+sdt;
            end
            xn = x;
            %toc
        end
        
        function x = simulate_feedforward ( model, x0, u, dt )
            % dt: control timestep
            N = size(u,2)+1; % N of time index
            x = nan(size(x0,1),N); x(:,1)=x0; % initialise x
            for n=1:N-1
                x(:,n+1) = model.step ( x(:,n), u(:,n), dt );
            end

        end
        
        
        
    end
    
    methods (Static)
        
        function qddot = compute_qddot(q, qdot, tau, model)
            Mq = Arm2Dof.compute_Mq(q, model);
            C = Arm2Dof.compute_C(q, qdot, model);
            G = Arm2Dof.compute_G(q, model);
            
            
            
            fc = model.coulomb_friction;
            fv = model.viscous_friction;
            %qddot = Mq\(tau - C*qdot - G);
            %qddot = qddot - Mq\( fv*qdot + fc*sign(qdot));
            
            qddot = Mq\(tau - C*qdot - G - fv*qdot - fc*sign(qdot));
        end
        
        function M = compute_Mq(q, model)
            I = model.I; %inertia
            L = model.L; %link length
            M = model.M; % mass
            Lg = model.Lg; % center of mass
            
            M11 = I(1) + I(2) + M(2)*(L(1)^2) + 2*M(2)*L(1)*Lg(2)*cos(q(2));
            M12 = I(2) + M(2)*L(1)*Lg(2)*cos(q(2));
            M21 = I(2) + M(2)*L(1)*Lg(2)*cos(q(2));
            M22 = I(2);
            M = [M11, M12;...
                 M21, M22];
        end
        
        function G = compute_G(q, model)
            L   = model.L;  % link lengths
            M   = model.M;  % mass
            Lg  = model.Lg; % center of gravity
            g   = model.g;

            % gravity vector
            G = -g*[(M(1)*Lg(1)+M(2)*L(1))*cos(q(1))+M(2)*Lg(2)*cos(q(1)+q(2));...
                                        +M(2)*Lg(2)*cos(q(1)+q(2))];
        end
        
        function C = compute_C(q, qdot, model)
            
            L   = model.L;  % link lengths
            M   = model.M;  % mass
            Lg  = model.Lg; % center of gravity

            % Coriolis matrix
            C = M(2)*L(1)*Lg(2)*sin(q(2))*[-2*qdot(2),-qdot(2);...
	                            qdot(1),      0];
        end
        
        %%%% kinematics
        
        % end point position
        function x = endpoint(q, L)
            x1 = L(1)*cos(q(1,:)) + L(2)*cos( q(1,:)+q(2,:) );
            x2 = L(1)*sin(q(1,:)) + L(2)*sin( q(1,:)+q(2,:) );
            
            x = [x1;x2];
        end
        
        % end point jacobian
        function J = jacobian(q, L)
            J(1,1,:) = -L(1)*sin(q(1,:))-L(2)*sin(q(1,:)+q(2,:));
            J(1,2,:) =                  -L(2)*sin(q(1,:)+q(2,:));
            J(2,1,:) =  L(1)*cos(q(1,:))+L(2)*cos(q(1,:)+q(2,:));
            J(2,2,:) =                   L(2)*cos(q(1,:)+q(2,:));
        end
        
        function [fh,ph1,ph2] = plot_arm(q, L)
            x11 = L(1)*cos(q(1,:));
            x12 = L(1)*sin(q(1,:));
            x21 = L(1)*cos(q(1,:)) + L(2)*cos( q(1,:)+q(2,:) );
            x22 = L(1)*sin(q(1,:)) + L(2)*sin( q(1,:)+q(2,:) );
            fh = figure;
            LL = L(1)+L(2);
            xlim( [-LL-0.2, LL+0.2] )
            ylim([-LL-0.2,LL+0.2])
            hold on
            %line([0,x11],[0,x12])
            %line([x11,x21],[x12,x22])
            ph1 = plot([0,x11],[0,x12],'-bo','LineWidth',4,'MarkerSize',7);
            ph2 = plot([x11,x21],[x12,x22],'-b','LineWidth',4);
            hold off
        end
        
        function [] = update_plot(h,ph1,ph2, q, L)
            x11 = L(1)*cos(q(1,:));
            x12 = L(1)*sin(q(1,:));
            x21 = L(1)*cos(q(1,:)) + L(2)*cos( q(1,:)+q(2,:) );
            x22 = L(1)*sin(q(1,:)) + L(2)*sin( q(1,:)+q(2,:) );
            
            ph1.XData = [0,x11];
            ph1.YData = [0,x12];
            ph2.XData = [x11,x21];
            ph2.YData = [x12,x22];
        end
        
    end
    
end

