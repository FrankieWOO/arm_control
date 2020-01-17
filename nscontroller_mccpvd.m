function [ v ] = nscontroller_mccpvd( x, tau_d, taudot_d, v1, param )
%NSCONTROLLER_MCCPVD Summary of this function goes here
%   Detailed explanation goes here
    q = x.q;
    qdot = x.qd;
    qddot = x.qdd;
    u1 = x.m1;
    u2 = x.m2;
    u3 = x.m3;
    
    b = taudot_d - param.Jq(q,qdot,u1,u2,u3)*qdot - param.Jqdot(q,qdot,u1,u2,u3)*qddot + param.Kp*(tau_d - param.F(q, qdot, u1, u2, u3));
    J = param.Ju(q,qdot,u1,u2,u3);
    v = nscontroller(J,b,v1,param.N);
    

end

