classdef Mccpvd2Dof < Arm2Dof
    %MCCPVD2DOF Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        name = 'maccepavd';
        dimQ = 2;
        dimU = 6;
        
        L = 0.3*ones(2,1);
        I = [0.0477;0.0588];
        M = [1.59; 1.44];
        Lg = [0.18; 0.21];
        g = 0;
        viscous_friction = 0;
        coulomb_friction = 0;
        
        actuator1
        actuator2
        
        figh
        plth1
        plth2
    end
    
    methods
        function obj = Mccpvd2Dof()
            obj = obj@Arm2Dof();
            obj.actuator1 = ActMccpvd();
            obj.actuator2 = ActMccpvd();
            
            
        end
        
        % x: (q1, q2, q1dot, q2dot, m11, m12, m21, m22,
        % m11dot, m12dot, m21dot, m22dot)
        function xdot = dynamics(model, x, u)
            %q = x(1:2);
            qdot = x(3:4);
            m = x(5:8); %motor position
            mdot = x(9:12); %motor velocity
            
            qddot = model.qddot(x, u);
            m11ddot = model.actuator1.motor_accel(m(1),mdot(1),u(1));
            m12ddot = model.actuator1.motor_accel(m(2),mdot(2),u(2));
            m21ddot = model.actuator2.motor_accel(m(3),mdot(3),u(4));
            m22ddot = model.actuator1.motor_accel(m(4),mdot(4),u(5));
            
            xdot = [qdot; qddot; mdot; m11ddot; m12ddot; m21ddot; m22ddot];
        end
        
        % compute accelaration 
        %qddot = Mq\(tau - C*qdot - G - fv*qdot - fc*sign(qdot));
        function qddot = qddot(model, x, u)
            tau = model.tau(x, u);
            qddot = model.compute_qddot(x(1:2), x(3:4), tau, model);
        end
        
        function tau = tau(model, x, u)
            tau1 = model.actuator1.torque(x(1), x(3), x(5), x(6), u(3));
            tau2 = model.actuator2.torque(x(2), x(4), x(7), x(8), u(6));
            tau = [tau1;tau2];
        end
        
        function [] = plot(model, x)
            q = x(1:2);
            
            global mccpvd2_fh mccpvd2_ph1 mccpvd2_ph2
            [mccpvd2_fh, mccpvd2_ph1, mccpvd2_ph2] = model.plot_arm(q, model.L);
            %model.figh = mccpvd2_fh;
            %model.plth1 = mccpvd2_ph1;
            %model.plth2 = mccpvd2_ph2;
        end
        
        function [] = update(model, x)
            q = x(1:2);
            global mccpvd2_fh mccpvd2_ph1 mccpvd2_ph2
            model.update_plot(mccpvd2_fh, mccpvd2_ph1, mccpvd2_ph2, q, model.L);
        end
        
        function [frames] = animate(model, xseq, dt)
            rate = robotics.Rate(int16(1/dt));
            N = size(xseq, 2);
            reset(rate)
            for i=1:N
                model.update(xseq(:,i));
                frames(i) = getframe;
                waitfor(rate);
            end
        end
        
    end
    
    methods (Static)
        
    end
    
end

