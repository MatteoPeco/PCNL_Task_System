
classdef CartesianImpedancePoint < ros.Message
    %CartesianImpedancePoint MATLAB implementation of lwr_controllers/CartesianImpedancePoint
    %   This class was automatically generated by
    %   ros.internal.pubsubEmitter.
    %   Copyright 2014-2020 The MathWorks, Inc.
    properties (Constant)
        MessageType = 'lwr_controllers/CartesianImpedancePoint' % The ROS message type
    end
    properties (Constant, Hidden)
        MD5Checksum = '71b8c728a99ddb73ba603776d4733a5f' % The MD5 Checksum of the message definition
        PropertyList = { 'Header' 'XFRI' 'KFRI' 'DFRI' 'FFRI' } % List of non-constant message properties
        ROSPropertyList = { 'header' 'x_FRI' 'k_FRI' 'd_FRI' 'f_FRI' } % List of non-constant ROS message properties
        PropertyMessageTypes = { 'ros.msggen.std_msgs.Header' ...
            'ros.msggen.geometry_msgs.Pose' ...
            'ros.msggen.lwr_controllers.Stiffness' ...
            'ros.msggen.lwr_controllers.Stiffness' ...
            'ros.msggen.geometry_msgs.Wrench' ...
            } % Types of contained nested messages
    end
    properties (Constant)
    end
    properties
        Header
        XFRI
        KFRI
        DFRI
        FFRI
    end
    methods
        function set.Header(obj, val)
            validAttributes = {'nonempty', 'scalar'};
            validClasses = {'ros.msggen.std_msgs.Header'};
            validateattributes(val, validClasses, validAttributes, 'CartesianImpedancePoint', 'Header')
            obj.Header = val;
        end
        function set.XFRI(obj, val)
            validAttributes = {'nonempty', 'scalar'};
            validClasses = {'ros.msggen.geometry_msgs.Pose'};
            validateattributes(val, validClasses, validAttributes, 'CartesianImpedancePoint', 'XFRI')
            obj.XFRI = val;
        end
        function set.KFRI(obj, val)
            validAttributes = {'nonempty', 'scalar'};
            validClasses = {'ros.msggen.lwr_controllers.Stiffness'};
            validateattributes(val, validClasses, validAttributes, 'CartesianImpedancePoint', 'KFRI')
            obj.KFRI = val;
        end
        function set.DFRI(obj, val)
            validAttributes = {'nonempty', 'scalar'};
            validClasses = {'ros.msggen.lwr_controllers.Stiffness'};
            validateattributes(val, validClasses, validAttributes, 'CartesianImpedancePoint', 'DFRI')
            obj.DFRI = val;
        end
        function set.FFRI(obj, val)
            validAttributes = {'nonempty', 'scalar'};
            validClasses = {'ros.msggen.geometry_msgs.Wrench'};
            validateattributes(val, validClasses, validAttributes, 'CartesianImpedancePoint', 'FFRI')
            obj.FFRI = val;
        end
    end
    methods (Static, Access = {?matlab.unittest.TestCase, ?ros.Message})
        function obj = loadobj(strObj)
        %loadobj Implements loading of message from MAT file
        % Return an empty object array if the structure element is not defined
            if isempty(strObj)
                obj = ros.msggen.lwr_controllers.CartesianImpedancePoint.empty(0,1);
                return
            end
            % Create an empty message object
            obj = ros.msggen.lwr_controllers.CartesianImpedancePoint(strObj);
        end
    end
end
