function [data, info] = multiPriorityTask
%MultiPriorityTask gives an empty data for lwr_controllers/MultiPriorityTask
% Copyright 2019-2020 The MathWorks, Inc.
%#codegen
data = struct();
data.MessageType = 'lwr_controllers/MultiPriorityTask';
[data.Links, info.Links] = ros.internal.ros.messages.ros.default_type('int32',NaN);
[data.Tasks, info.Tasks] = ros.internal.ros.messages.ros.default_type('double',NaN);
info.MessageType = 'lwr_controllers/MultiPriorityTask';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,2);
info.MatPath{1} = 'links';
info.MatPath{2} = 'tasks';
