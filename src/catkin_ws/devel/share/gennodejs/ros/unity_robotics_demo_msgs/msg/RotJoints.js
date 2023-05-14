// Auto-generated. Do not edit!

// (in-package unity_robotics_demo_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class RotJoints {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.a1_joint = null;
      this.a2_joint = null;
      this.a3_joint = null;
      this.a4_joint = null;
      this.a5_joint = null;
      this.a6_joint = null;
      this.e1_joint = null;
    }
    else {
      if (initObj.hasOwnProperty('a1_joint')) {
        this.a1_joint = initObj.a1_joint
      }
      else {
        this.a1_joint = 0.0;
      }
      if (initObj.hasOwnProperty('a2_joint')) {
        this.a2_joint = initObj.a2_joint
      }
      else {
        this.a2_joint = 0.0;
      }
      if (initObj.hasOwnProperty('a3_joint')) {
        this.a3_joint = initObj.a3_joint
      }
      else {
        this.a3_joint = 0.0;
      }
      if (initObj.hasOwnProperty('a4_joint')) {
        this.a4_joint = initObj.a4_joint
      }
      else {
        this.a4_joint = 0.0;
      }
      if (initObj.hasOwnProperty('a5_joint')) {
        this.a5_joint = initObj.a5_joint
      }
      else {
        this.a5_joint = 0.0;
      }
      if (initObj.hasOwnProperty('a6_joint')) {
        this.a6_joint = initObj.a6_joint
      }
      else {
        this.a6_joint = 0.0;
      }
      if (initObj.hasOwnProperty('e1_joint')) {
        this.e1_joint = initObj.e1_joint
      }
      else {
        this.e1_joint = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type RotJoints
    // Serialize message field [a1_joint]
    bufferOffset = _serializer.float32(obj.a1_joint, buffer, bufferOffset);
    // Serialize message field [a2_joint]
    bufferOffset = _serializer.float32(obj.a2_joint, buffer, bufferOffset);
    // Serialize message field [a3_joint]
    bufferOffset = _serializer.float32(obj.a3_joint, buffer, bufferOffset);
    // Serialize message field [a4_joint]
    bufferOffset = _serializer.float32(obj.a4_joint, buffer, bufferOffset);
    // Serialize message field [a5_joint]
    bufferOffset = _serializer.float32(obj.a5_joint, buffer, bufferOffset);
    // Serialize message field [a6_joint]
    bufferOffset = _serializer.float32(obj.a6_joint, buffer, bufferOffset);
    // Serialize message field [e1_joint]
    bufferOffset = _serializer.float32(obj.e1_joint, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type RotJoints
    let len;
    let data = new RotJoints(null);
    // Deserialize message field [a1_joint]
    data.a1_joint = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [a2_joint]
    data.a2_joint = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [a3_joint]
    data.a3_joint = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [a4_joint]
    data.a4_joint = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [a5_joint]
    data.a5_joint = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [a6_joint]
    data.a6_joint = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [e1_joint]
    data.e1_joint = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 28;
  }

  static datatype() {
    // Returns string type for a message object
    return 'unity_robotics_demo_msgs/RotJoints';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'e483f27ca9086997bb07bd67723e718f';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 a1_joint
    float32 a2_joint
    float32 a3_joint
    float32 a4_joint
    float32 a5_joint
    float32 a6_joint
    float32 e1_joint
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new RotJoints(null);
    if (msg.a1_joint !== undefined) {
      resolved.a1_joint = msg.a1_joint;
    }
    else {
      resolved.a1_joint = 0.0
    }

    if (msg.a2_joint !== undefined) {
      resolved.a2_joint = msg.a2_joint;
    }
    else {
      resolved.a2_joint = 0.0
    }

    if (msg.a3_joint !== undefined) {
      resolved.a3_joint = msg.a3_joint;
    }
    else {
      resolved.a3_joint = 0.0
    }

    if (msg.a4_joint !== undefined) {
      resolved.a4_joint = msg.a4_joint;
    }
    else {
      resolved.a4_joint = 0.0
    }

    if (msg.a5_joint !== undefined) {
      resolved.a5_joint = msg.a5_joint;
    }
    else {
      resolved.a5_joint = 0.0
    }

    if (msg.a6_joint !== undefined) {
      resolved.a6_joint = msg.a6_joint;
    }
    else {
      resolved.a6_joint = 0.0
    }

    if (msg.e1_joint !== undefined) {
      resolved.e1_joint = msg.e1_joint;
    }
    else {
      resolved.e1_joint = 0.0
    }

    return resolved;
    }
};

module.exports = RotJoints;
