function [data, info] = rPY
%RPY gives an empty data for lwr_controllers/RPY
% Copyright 2019-2020 The MathWorks, Inc.
%#codegen
data = struct();
data.MessageType = 'lwr_controllers/RPY';
[data.Roll, info.Roll] = ros.internal.ros.messages.ros.default_type('double',1);
[data.Pitch, info.Pitch] = ros.internal.ros.messages.ros.default_type('double',1);
[data.Yaw, info.Yaw] = ros.internal.ros.messages.ros.default_type('double',1);
info.MessageType = 'lwr_controllers/RPY';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,3);
info.MatPath{1} = 'roll';
info.MatPath{2} = 'pitch';
info.MatPath{3} = 'yaw';
