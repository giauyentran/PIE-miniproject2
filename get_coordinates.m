function coordinate = get_coordinates(a,pan_angle, tilt_angle)
    
    distance = get_distance(readVoltage(a,"A5"));
    theta = pan_angle;
    phi = tilt_angle;
    
    z = distance * sin(deg2rad(theta) * cos(deg2rad(phi)));
    y = distance * sin(deg2rad(phi));
    x = distance * cos(deg2rad(theta)) * cos(deg2rad(phi));

    coordinate = [x; y; z];

end