function [data, info] = stiffness
%Stiffness gives an empty data for lwr_controllers/Stiffness
% Copyright 2019-2020 The MathWorks, Inc.
%#codegen
data = struct();
data.MessageType = 'lwr_controllers/Stiffness';
[data.X, info.X] = ros.internal.ros.messages.ros.default_type('double',1);
[data.Y, info.Y] = ros.internal.ros.messages.ros.default_type('double',1);
[data.Z, info.Z] = ros.internal.ros.messages.ros.default_type('double',1);
[data.Rx, info.Rx] = ros.internal.ros.messages.ros.default_type('double',1);
[data.Ry, info.Ry] = ros.internal.ros.messages.ros.default_type('double',1);
[data.Rz, info.Rz] = ros.internal.ros.messages.ros.default_type('double',1);
info.MessageType = 'lwr_controllers/Stiffness';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,6);
info.MatPath{1} = 'x';
info.MatPath{2} = 'y';
info.MatPath{3} = 'z';
info.MatPath{4} = 'rx';
info.MatPath{5} = 'ry';
info.MatPath{6} = 'rz';
