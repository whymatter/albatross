; Auto-generated. Do not edit!


(cl:in-package alb_ros_msgs-msg)


;//! \htmlinclude BoundingBox.msg.html

(cl:defclass <BoundingBox> (roslisp-msg-protocol:ros-message)
  ((x
    :reader x
    :initarg :x
    :type cl:integer
    :initform 0)
   (y
    :reader y
    :initarg :y
    :type cl:integer
    :initform 0)
   (w
    :reader w
    :initarg :w
    :type cl:integer
    :initform 0)
   (h
    :reader h
    :initarg :h
    :type cl:integer
    :initform 0))
)

(cl:defclass BoundingBox (<BoundingBox>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <BoundingBox>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'BoundingBox)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name alb_ros_msgs-msg:<BoundingBox> is deprecated: use alb_ros_msgs-msg:BoundingBox instead.")))

(cl:ensure-generic-function 'x-val :lambda-list '(m))
(cl:defmethod x-val ((m <BoundingBox>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader alb_ros_msgs-msg:x-val is deprecated.  Use alb_ros_msgs-msg:x instead.")
  (x m))

(cl:ensure-generic-function 'y-val :lambda-list '(m))
(cl:defmethod y-val ((m <BoundingBox>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader alb_ros_msgs-msg:y-val is deprecated.  Use alb_ros_msgs-msg:y instead.")
  (y m))

(cl:ensure-generic-function 'w-val :lambda-list '(m))
(cl:defmethod w-val ((m <BoundingBox>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader alb_ros_msgs-msg:w-val is deprecated.  Use alb_ros_msgs-msg:w instead.")
  (w m))

(cl:ensure-generic-function 'h-val :lambda-list '(m))
(cl:defmethod h-val ((m <BoundingBox>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader alb_ros_msgs-msg:h-val is deprecated.  Use alb_ros_msgs-msg:h instead.")
  (h m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <BoundingBox>) ostream)
  "Serializes a message object of type '<BoundingBox>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'x)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'x)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'x)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'x)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'y)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'y)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'y)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'y)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'w)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'w)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'w)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'w)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'h)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'h)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'h)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'h)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <BoundingBox>) istream)
  "Deserializes a message object of type '<BoundingBox>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'x)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'x)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'x)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'x)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'y)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'y)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'y)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'y)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'w)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'w)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'w)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'w)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'h)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'h)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'h)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'h)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<BoundingBox>)))
  "Returns string type for a message object of type '<BoundingBox>"
  "alb_ros_msgs/BoundingBox")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'BoundingBox)))
  "Returns string type for a message object of type 'BoundingBox"
  "alb_ros_msgs/BoundingBox")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<BoundingBox>)))
  "Returns md5sum for a message object of type '<BoundingBox>"
  "c1d7daec9dd3af1e73d39f873a977099")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'BoundingBox)))
  "Returns md5sum for a message object of type 'BoundingBox"
  "c1d7daec9dd3af1e73d39f873a977099")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<BoundingBox>)))
  "Returns full string definition for message of type '<BoundingBox>"
  (cl:format cl:nil "uint32       x~%uint32       y~%uint32       w~%uint32       h~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'BoundingBox)))
  "Returns full string definition for message of type 'BoundingBox"
  (cl:format cl:nil "uint32       x~%uint32       y~%uint32       w~%uint32       h~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <BoundingBox>))
  (cl:+ 0
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <BoundingBox>))
  "Converts a ROS message object to a list"
  (cl:list 'BoundingBox
    (cl:cons ':x (x msg))
    (cl:cons ':y (y msg))
    (cl:cons ':w (w msg))
    (cl:cons ':h (h msg))
))
