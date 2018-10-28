;; Auto-generated. Do not edit!


(when (boundp 'alb_ros_msgs::CamDetection)
  (if (not (find-package "ALB_ROS_MSGS"))
    (make-package "ALB_ROS_MSGS"))
  (shadow 'CamDetection (find-package "ALB_ROS_MSGS")))
(unless (find-package "ALB_ROS_MSGS::CAMDETECTION")
  (make-package "ALB_ROS_MSGS::CAMDETECTION"))

(in-package "ROS")
;;//! \htmlinclude CamDetection.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass alb_ros_msgs::CamDetection
  :super ros::object
  :slots (_header _boundingBox _propability _objectId ))

(defmethod alb_ros_msgs::CamDetection
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:boundingBox __boundingBox) (instance alb_ros_msgs::BoundingBox :init))
    ((:propability __propability) 0.0)
    ((:objectId __objectId) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _boundingBox __boundingBox)
   (setq _propability (float __propability))
   (setq _objectId (round __objectId))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:boundingBox
   (&rest __boundingBox)
   (if (keywordp (car __boundingBox))
       (send* _boundingBox __boundingBox)
     (progn
       (if __boundingBox (setq _boundingBox (car __boundingBox)))
       _boundingBox)))
  (:propability
   (&optional __propability)
   (if __propability (setq _propability __propability)) _propability)
  (:objectId
   (&optional __objectId)
   (if __objectId (setq _objectId __objectId)) _objectId)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; alb_ros_msgs/BoundingBox _boundingBox
    (send _boundingBox :serialization-length)
    ;; float32 _propability
    4
    ;; uint32 _objectId
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; alb_ros_msgs/BoundingBox _boundingBox
       (send _boundingBox :serialize s)
     ;; float32 _propability
       (sys::poke _propability (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; uint32 _objectId
       (write-long _objectId s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; alb_ros_msgs/BoundingBox _boundingBox
     (send _boundingBox :deserialize buf ptr-) (incf ptr- (send _boundingBox :serialization-length))
   ;; float32 _propability
     (setq _propability (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; uint32 _objectId
     (setq _objectId (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get alb_ros_msgs::CamDetection :md5sum-) "6ec64339c86b71d9eb90869f49d3c927")
(setf (get alb_ros_msgs::CamDetection :datatype-) "alb_ros_msgs/CamDetection")
(setf (get alb_ros_msgs::CamDetection :definition-)
      "Header       header

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
")



(provide :alb_ros_msgs/CamDetection "6ec64339c86b71d9eb90869f49d3c927")


