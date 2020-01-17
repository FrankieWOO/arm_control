function [ v ] = nscontroller( J, b, v1, N )
%NSCONTROLLER Summary of this function goes here
%   Detailed explanation goes here
    Nmh = N^(-1/2);
    Nph = N^(1/2);
    A = J*Nmh;
    Ap = pinv(A);
    I = eye(size(v1,1));
    v = Nmh*Ap*b + Nmh*(I - Ap*A)*Nph*v1;
    %v = Nmh*Ap*b ;

end

