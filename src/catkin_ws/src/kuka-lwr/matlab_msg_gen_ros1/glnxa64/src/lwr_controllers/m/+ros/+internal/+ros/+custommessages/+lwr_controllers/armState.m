function [data, info] = armState
%ArmState gives an empty data for lwr_controllers/ArmState
% Copyright 2019-2020 The MathWorks, Inc.
%#codegen
data = struct();
data.MessageType = 'lwr_controllers/ArmState';
[data.Header, info.Header] = ros.internal.ros.messages.std_msgs.header;
info.Header.MLdataType = 'struct';
[data.JointName, info.JointName] = ros.internal.ros.messages.ros.char('string',NaN);
[data.EstExtTorques, info.EstExtTorques] = ros.internal.ros.messages.ros.default_type('single',NaN);
[data.EstEeWrench, info.EstEeWrench] = ros.internal.ros.messages.geometry_msgs.wrench;
info.EstEeWrench.MLdataType = 'struct';
[data.EstEeWrenchBase, info.EstEeWrenchBase] = ros.internal.ros.messages.geometry_msgs.wrench;
info.EstEeWrenchBase.MLdataType = 'struct';
info.MessageType = 'lwr_controllers/ArmState';
info.constant = 0;
info.default = 0;
info.maxstrlen = NaN;
info.MaxLen = 1;
info.MinLen = 1;
info.MatPath = cell(1,26);
info.MatPath{1} = 'header';
info.MatPath{2} = 'header.seq';
info.MatPath{3} = 'header.stamp';
info.MatPath{4} = 'header.stamp.sec';
info.MatPath{5} = 'header.stamp.nsec';
info.MatPath{6} = 'header.frame_id';
info.MatPath{7} = 'joint_name';
info.MatPath{8} = 'est_ext_torques';
info.MatPath{9} = 'est_ee_wrench';
info.MatPath{10} = 'est_ee_wrench.force';
info.MatPath{11} = 'est_ee_wrench.force.x';
info.MatPath{12} = 'est_ee_wrench.force.y';
info.MatPath{13} = 'est_ee_wrench.force.z';
info.MatPath{14} = 'est_ee_wrench.torque';
info.MatPath{15} = 'est_ee_wrench.torque.x';
info.MatPath{16} = 'est_ee_wrench.torque.y';
info.MatPath{17} = 'est_ee_wrench.torque.z';
info.MatPath{18} = 'est_ee_wrench_base';
info.MatPath{19} = 'est_ee_wrench_base.force';
info.MatPath{20} = 'est_ee_wrench_base.force.x';
info.MatPath{21} = 'est_ee_wrench_base.force.y';
info.MatPath{22} = 'est_ee_wrench_base.force.z';
info.MatPath{23} = 'est_ee_wrench_base.torque';
info.MatPath{24} = 'est_ee_wrench_base.torque.x';
info.MatPath{25} = 'est_ee_wrench_base.torque.y';
info.MatPath{26} = 'est_ee_wrench_base.torque.z';
