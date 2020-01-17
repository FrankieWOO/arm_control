classdef Mccpvd2DofMD < Mccpvd2Dof
    % Mccpvd2 with 2nd order dynamics
    
    properties
        
    end
    
    methods
        function obj = Mccpvd2DofMD()
            obj = obj@Mccpvd2Dof();
            %obj.actuator1 = ActMccpvd();
            %obj.actuator2 = ActMccpvd();
        end
    end
    
end

