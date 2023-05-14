
classdef RPY < ros.Message
    %RPY MATLAB implementation of lwr_controllers/RPY
    %   This class was automatically generated by
    %   ros.internal.pubsubEmitter.
    %   Copyright 2014-2020 The MathWorks, Inc.
    properties (Constant)
        MessageType = 'lwr_controllers/RPY' % The ROS message type
    end
    properties (Constant, Hidden)
        MD5Checksum = 'eeec8b25a660789a89540dedcb2b06d6' % The MD5 Checksum of the message definition
        PropertyList = { 'Roll' 'Pitch' 'Yaw' } % List of non-constant message properties
        ROSPropertyList = { 'roll' 'pitch' 'yaw' } % List of non-constant ROS message properties
        PropertyMessageTypes = { '' ...
            '' ...
            '' ...
            } % Types of contained nested messages
    end
    properties (Constant)
    end
    properties
        Roll
        Pitch
        Yaw
    end
    methods
        function set.Roll(obj, val)
            validClasses = {'numeric'};
            validAttributes = {'nonempty', 'scalar'};
            validateattributes(val, validClasses, validAttributes, 'RPY', 'Roll');
            obj.Roll = double(val);
        end
        function set.Pitch(obj, val)
            validClasses = {'numeric'};
            validAttributes = {'nonempty', 'scalar'};
            validateattributes(val, validClasses, validAttributes, 'RPY', 'Pitch');
            obj.Pitch = double(val);
        end
        function set.Yaw(obj, val)
            validClasses = {'numeric'};
            validAttributes = {'nonempty', 'scalar'};
            validateattributes(val, validClasses, validAttributes, 'RPY', 'Yaw');
            obj.Yaw = double(val);
        end
    end
    methods (Static, Access = {?matlab.unittest.TestCase, ?ros.Message})
        function obj = loadobj(strObj)
        %loadobj Implements loading of message from MAT file
        % Return an empty object array if the structure element is not defined
            if isempty(strObj)
                obj = ros.msggen.lwr_controllers.RPY.empty(0,1);
                return
            end
            % Create an empty message object
            obj = ros.msggen.lwr_controllers.RPY(strObj);
        end
    end
end
