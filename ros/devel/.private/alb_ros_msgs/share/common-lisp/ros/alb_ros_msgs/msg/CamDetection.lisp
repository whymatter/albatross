; Auto-generated. Do not edit!


(cl:in-package alb_ros_msgs-msg)


;//! \htmlinclude CamDetection.msg.html

(cl:defclass <CamDetection> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (boundingBox
    :reader boundingBox
    :initarg :boundingBox
    :type alb_ros_msgs-msg:BoundingBox
    :initform (cl:make-instance 'alb_ros_msgs-msg:BoundingBox))
   (propability
    :reader propability
    :initarg :propability
    :type cl:float
    :initform 0.0)
   (objectId
    :reader objectId
    :initarg :objectId
    :type cl:integer
    :initform 0))
)

(cl:defclass CamDetection (<CamDetection>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <CamDetection>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'CamDetection)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name alb_ros_msgs-msg:<CamDetection> is deprecated: use alb_ros_msgs-msg:CamDetection instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <CamDetection>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader alb_ros_msgs-msg:header-val is deprecated.  Use alb_ros_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'boundingBox-val :lambda-list '(m))
(cl:defmethod boundingBox-val ((m <CamDetection>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader alb_ros_msgs-msg:boundingBox-val is deprecated.  Use alb_ros_msgs-msg:boundingBox instead.")
  (boundingBox m))

(cl:ensure-generic-function 'propability-val :lambda-list '(m))
(cl:defmethod propability-val ((m <CamDetection>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader alb_ros_msgs-msg:propability-val is deprecated.  Use alb_ros_msgs-msg:propability instead.")
  (propability m))

(cl:ensure-generic-function 'objectId-val :lambda-list '(m))
(cl:defmethod objectId-val ((m <CamDetection>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader alb_ros_msgs-msg:objectId-val is deprecated.  Use alb_ros_msgs-msg:objectId instead.")
  (objectId m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <CamDetection>) ostream)
  "Serializes a message object of type '<CamDetection>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'boundingBox) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'propability))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'objectId)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'objectId)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'objectId)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'objectId)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <CamDetection>) istream)
  "Deserializes a message object of type '<CamDetection>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'boundingBox) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'propability) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'objectId)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'objectId)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'objectId)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'objectId)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<CamDetection>)))
  "Returns string type for a message object of type '<CamDetection>"
  "alb_ros_msgs/CamDetection")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'CamDetection)))
  "Returns string type for a message object of type 'CamDetection"
  "alb_ros_msgs/CamDetection")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<CamDetection>)))
  "Returns md5sum for a message object of type '<CamDetection>"
  "6ec64339c86b71d9eb90869f49d3c927")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'CamDetection)))
  "Returns md5sum for a message object of type 'CamDetection"
  "6ec64339c86b71d9eb90869f49d3c927")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<CamDetection>)))
  "Returns full string definition for message of type '<CamDetection>"
  (cl:format cl:nil "Header       header~%~%BoundingBox  boundingBox~%float32        propability~%uint32       objectId~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: alb_ros_msgs/BoundingBox~%uint32       x~%uint32       y~%uint32       w~%uint32       h~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'CamDetection)))
  "Returns full string definition for message of type 'CamDetection"
  (cl:format cl:nil "Header       header~%~%BoundingBox  boundingBox~%float32        propability~%uint32       objectId~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: alb_ros_msgs/BoundingBox~%uint32       x~%uint32       y~%uint32       w~%uint32       h~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <CamDetection>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'boundingBox))
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <CamDetection>))
  "Converts a ROS message object to a list"
  (cl:list 'CamDetection
    (cl:cons ':header (header msg))
    (cl:cons ':boundingBox (boundingBox msg))
    (cl:cons ':propability (propability msg))
    (cl:cons ':objectId (objectId msg))
))
