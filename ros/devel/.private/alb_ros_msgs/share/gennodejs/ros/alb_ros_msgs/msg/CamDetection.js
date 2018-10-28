// Auto-generated. Do not edit!

// (in-package alb_ros_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let BoundingBox = require('./BoundingBox.js');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class CamDetection {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.boundingBox = null;
      this.propability = null;
      this.objectId = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('boundingBox')) {
        this.boundingBox = initObj.boundingBox
      }
      else {
        this.boundingBox = new BoundingBox();
      }
      if (initObj.hasOwnProperty('propability')) {
        this.propability = initObj.propability
      }
      else {
        this.propability = 0.0;
      }
      if (initObj.hasOwnProperty('objectId')) {
        this.objectId = initObj.objectId
      }
      else {
        this.objectId = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type CamDetection
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [boundingBox]
    bufferOffset = BoundingBox.serialize(obj.boundingBox, buffer, bufferOffset);
    // Serialize message field [propability]
    bufferOffset = _serializer.float32(obj.propability, buffer, bufferOffset);
    // Serialize message field [objectId]
    bufferOffset = _serializer.uint32(obj.objectId, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type CamDetection
    let len;
    let data = new CamDetection(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [boundingBox]
    data.boundingBox = BoundingBox.deserialize(buffer, bufferOffset);
    // Deserialize message field [propability]
    data.propability = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [objectId]
    data.objectId = _deserializer.uint32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 24;
  }

  static datatype() {
    // Returns string type for a message object
    return 'alb_ros_msgs/CamDetection';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '6ec64339c86b71d9eb90869f49d3c927';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header       header
    
    BoundingBox  boundingBox
    float32        propability
    uint32       objectId
    ================================================================================
    MSG: std_msgs/Header
    # Standard metadata for higher-level stamped data types.
    # This is generally used to communicate timestamped data 
    # in a particular coordinate frame.
    # 
    # sequence ID: consecutively increasing ID 
    uint32 seq
    #Two-integer timestamp that is expressed as:
    # * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
    # * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
    # time-handling sugar is provided by the client library
    time stamp
    #Frame this data is associated with
    # 0: no frame
    # 1: global frame
    string frame_id
    
    ================================================================================
    MSG: alb_ros_msgs/BoundingBox
    uint32       x
    uint32       y
    uint32       w
    uint32       h
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new CamDetection(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.boundingBox !== undefined) {
      resolved.boundingBox = BoundingBox.Resolve(msg.boundingBox)
    }
    else {
      resolved.boundingBox = new BoundingBox()
    }

    if (msg.propability !== undefined) {
      resolved.propability = msg.propability;
    }
    else {
      resolved.propability = 0.0
    }

    if (msg.objectId !== undefined) {
      resolved.objectId = msg.objectId;
    }
    else {
      resolved.objectId = 0
    }

    return resolved;
    }
};

module.exports = CamDetection;
