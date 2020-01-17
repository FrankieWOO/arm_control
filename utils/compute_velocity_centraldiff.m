function [ v ] = compute_velocity_centraldiff( p,t )
%COMPUTE_VELOCITY_CENTRALDIFF Summary of this function goes here
%   Detailed explanation goes here
    % central difference and central window smoothing;
    v = zeros(size(p));
    
    for i = 2:length(p)-1
        v(i) = (p(i+1) - p(i-1))/(t(i+1)- t(i-1));
    end
    v(end) = (p(end) - p(end-1))/(t(end)- t(end-1));
    
    window = 5;
    for j = 1:window
        v(j) = mean(v(1:2*j-1));
    end
    
    for k = window+1:length(v)-window
        v(k) = mean(v(k-window:k+window));
    end
    
    for k = length(v)-window+1:length(v)
        w = length(v)-k;
        v(k) = mean( v( k-w:k+w ) );
    end
    
    %v(end-9:end) = DataProcess.mavg_filter(v(end-9:end), 3);

end

