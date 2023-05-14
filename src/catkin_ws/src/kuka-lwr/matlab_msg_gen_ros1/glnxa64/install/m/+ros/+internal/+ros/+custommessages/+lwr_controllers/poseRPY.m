function [data, info] = poseRPY
%PoseRPY gives an empty data for lwr_controllers/PoseRPY
% Copyright 2019-2020 The MathWorks, Inc.
%#codegen
data = struct();
data.MessageType = 'lwr_controllers/PoseRPY';
[data.Id, info.Id] = ros.internal.ros.messages.ros.default_type('int32',1);
[data.Position, info.Position] = ros.internal.ros.messages.geometry_msgs.vector3;
info.Position.MLdataType = 'struct';
[data.Orientation, info.Orientation] = ros.internal.ros.custommessages.lwr_controllers.rPY;
info.Orientation.MLdataType = 'struct';
info.MessageType = 'lwr_controllers/PoseRPY';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,9);
info.MatPath{1} = 'id';
info.MatPath{2} = 'position';
info.MatPath{3} = 'position.x';
info.MatPath{4} = 'position.y';
info.MatPath{5} = 'position.z';
info.MatPath{6} = 'orientation';
info.MatPath{7} = 'orientation.roll';
info.MatPath{8} = 'orientation.pitch';
info.MatPath{9} = 'orientation.yaw';
