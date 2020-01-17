classdef Mccpvd1Dof < Arm
    %MCCPVD1DOF Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        
        dimX = 2
        dimU = 3
        M = 0.0036 % inertia
        fv = 0.0077 %viscous friction
        gc = 0 %gravity constant, default 0 for planar
        B = 0.036;
        C = 0.135;
        A0 = 0.099; % C - B
        Ks = 394; %231 % spring constant
        r = 0.015;
        Dm = 0.0339;
        
        mass = 0.18
        com = 0.085
        modelpara
        actuator
        
        %%%% store feedforward command
        %ffu1
        %ffu2
        %%%%
    end
    
    methods
        function obj = Mccpvd1Dof()
            obj = obj@Arm();
            obj.actuator = ActMccpvd();
            obj.modelpara = [];
            obj.modelpara.M = obj.M;
            obj.modelpara.fv = obj.fv;
            obj.modelpara.gc = obj.gc;
            obj.modelpara.B = obj.B;
            obj.modelpara.C = obj.C;
            obj.modelpara.A0 = obj.A0;
            obj.modelpara.Ks = obj.Ks;
            obj.modelpara.r = obj.r;
            obj.modelpara.Dm = obj.Dm;
            obj.modelpara.mass=obj.mass;
            obj.modelpara.com=obj.com;
            
            
        end
        
        function tau = desired_torque(obj, q, qd, qdd)
            tau = obj.M*qdd + obj.fv*qd - obj.gravity(q);
        end
        
        function f = gravity(obj, q)
            f = -obj.mass*obj.com*obj.gc*sin(q);
            %
        end
        
        % SSM dynamics
        % dynamics: u is motor positions
        function xdot = dynamics(obj, x, u)
            qdd = obj.accel(x, u);
            xdot = [x(2);qdd];
        end
        
        % dynamics_v: 
        % x: (q, qd, u1, u2, u3)
        % v: motor velocities
        function xdot = dynamics_v(obj, x, v)
            qdd = obj.accel(x(1:2,:), [x(3:4,:); v(3)]);
            xdot = [x(2); qdd; v(1); v(2)];
        end
        
%         function xdot = dynamics3(obj, x, u3, n)
%             u1 = obj.ffu1(n);
%             u2 = obj.ffu2(n);
%             qdd = obj.accel( x(1:2,:), [u1;u2;u3] );
%             xdot = [x(2); qdd];
%         end
%         
%         function xdot = dynamics2(obj, x, u23, n)
%             u1 = obj.ffu1(n);
%             qdd = obj.accel( x(1:2,:), [u1; u23]);
%             xdot = [ x(2); qdd];
%         end
        
        function qdd = accel(obj, x, u)
            tau = obj.torque_actuator(x, u);
            %tau = mccp1TauA_mex(obj.modelpara,x,u);
            qdd = (tau - obj.fv*x(2,:) + obj.gravity(x(1,:)))/obj.M;
        end
        
        function tau = torque_actuator(obj, x, u)
            tau = obj.Ks*obj.B*obj.C*sin(u(1,:)-x(1,:)).*(1+ (obj.r*u(2,:) ...
                -obj.A0)./sqrt(obj.B^2+obj.C^2-2*obj.B*obj.C*cos(u(1,:)-x(1,:))) )...
                - obj.Dm*u(3,:).*x(2,:);
        end
        function force = spring_force(obj, x, u)
            
            %sprlength = obj.spring_displacement(q,theta1, theta2);
            force = obj.actuator.spring_force(x(1,:), u(1,:), u(2,:));
        end
%         function tau = tauA_mex(obj, s, x, u)
%             tau = mccp1TauA_mex( s, x, u);
%         end
        % torques
        function tau = torque_spring(obj, x, u)
            tau = obj.actuator.torque_spring(x(1,:), u(1,:), u(2,:));
        end
        function tau = torque_damping(obj, qdot, u3)
            tau = obj.Dm*u3*qdot;
        end
        % motor torques
        function tau_l = tau_l1(obj, x, u)
            tau_l = -obj.torque_spring(x, u);
        end
        
        function tau_l = tau_l2(obj, x, u)
            phi = u(1,:) - x(1,:);
            A = sqrt( obj.C^2 + obj.B^2 - 2*(obj.B*obj.C).*cos( phi ));
            tau_l = -obj.Ks*(A + obj.r*u(2,:) - obj.A0)*obj.r;
            
        end
        
        function tau_m = tau_m1(obj, x, u, yd, ydd)
            % tau_m of servo1 at servo's shaft
            % M ddtheta + D dtheta = tau_m + tau_l
            tau_l = obj.tau_l1(x,u);
            %p = obj.alpha_servo;
            %accel = p^2*(u(1)-x(3)) - 2*p*x(5);
            
            tau_m = - tau_l + obj.actuator.J1*ydd(1,:) + obj.actuator.D1*yd(1,:) ;
            %tau_m = model.actuator.J1*accel + model.actuator.D1*x(5) ;
            %tau_m = tau_l;
        end
        
        function tau_m = tau_m2(obj, x, u, yd, ydd)
            % tau_m of servo2 at servo's shaft
            % yd: motor velocity,
            % ydd: motor's acceleration
            tau_l = obj.tau_l2(x,u);
            %p = obj.alpha_servo;
            %accel = p^2*(u(2)-x(4)) - 2*p*x(6);
            
            tau_m = - tau_l + obj.actuator.D2*yd + obj.actuator.J2*ydd;
            %tau_m = model.actuator.D2*x(6) + model.actuator.J2*accel;
        end
        
        % power
        function p = power_out(obj, x, u)
            % to replace power_link
            tau = obj.torque_spring(x, u);
            p = tau.*x(2,:); % joint velocity
        end
        function out = sqrt_torques(obj, x, u)
            t1 = obj.tau_l1(x,u);
            t2 = obj.tau_l2(x,u);
            out = 5.6611*(t1.^2 + t2.^2); % 5.6611 = R/K_t^2 according to motor specs
            
        end
        % note: before input x, add extra u and udot to x to make up 6 x Nt
        % state matrix
        function p = power_in(obj, x, u)
            %tau_l1 = model.actuator.torque_load1(x(1,:),x(3,:),x(4,:));
            %tau_l2 = model.actuator.torque_load2(x(1,:),x(3,:),x(4,:));
            %p = max(-tau_l1.*x(5,:),0) + max(-tau_l2.*x(6,:),0);
            p1 = obj.power_in1(x, u);
            p2 = obj.power_in2(x, u);
            p1 = max(p1,0);
            p2 = max(p2,0);
            p = p1 + p2;
        end
        function p = power_in1(obj, x, u)
            tau_l1 = obj.actuator.torque_load1(x(1,:),u(1,:),u(2,:));
            p = -tau_l1.*x(5,:); % motor1 velocity
        end
        function p = power_in2(obj, x, u)
            
            tau_l2 = obj.actuator.torque_load2(x(1,:),u(1,:),u(2,:));
            p = -tau_l2.*x(6,:); % motor2 velocity
        end
        function E = energy_spring(obj, x, u)
            l = obj.actuator.spring_displacement(x(1,:),u(1,:),u(2,:));
            E = obj.actuator.Ks*(l.^2)/2;
        end
        function D = evaluate_traj(obj, traj, parameters)
            
        end
    end
    methods (Static)
        
    end
    
    
end

