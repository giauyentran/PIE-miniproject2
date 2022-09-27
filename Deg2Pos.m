function pos = Deg2Pos(degree)
% degree ranges from -90 to 90
% converts angle in degrees to servo position between 0 and 1
    pos = 0.5+degree/180;
end
