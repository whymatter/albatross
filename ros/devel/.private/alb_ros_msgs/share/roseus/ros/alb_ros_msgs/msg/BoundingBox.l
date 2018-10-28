;; Auto-generated. Do not edit!


(when (boundp 'alb_ros_msgs::BoundingBox)
  (if (not (find-package "ALB_ROS_MSGS"))
    (make-package "ALB_ROS_MSGS"))
  (shadow 'BoundingBox (find-package "ALB_ROS_MSGS")))
(unless (find-package "ALB_ROS_MSGS::BOUNDINGBOX")
  (make-package "ALB_ROS_MSGS::BOUNDINGBOX"))

(in-package "ROS")
;;//! \htmlinclude BoundingBox.msg.html


(defclass alb_ros_msgs::BoundingBox
  :super ros::object
  :slots (_x _y _w _h ))

(defmethod alb_ros_msgs::BoundingBox
  (:init
   (&key
    ((:x __x) 0)
    ((:y __y) 0)
    ((:w __w) 0)
    ((:h __h) 0)
    )
   (send-super :init)
   (setq _x (round __x))
   (setq _y (round __y))
   (setq _w (round __w))
   (setq _h (round __h))
   self)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:w
   (&optional __w)
   (if __w (setq _w __w)) _w)
  (:h
   (&optional __h)
   (if __h (setq _h __h)) _h)
  (:serialization-length
   ()
   (+
    ;; uint32 _x
    4
    ;; uint32 _y
    4
    ;; uint32 _w
    4
    ;; uint32 _h
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint32 _x
       (write-long _x s)
     ;; uint32 _y
       (write-long _y s)
     ;; uint32 _w
       (write-long _w s)
     ;; uint32 _h
       (write-long _h s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint32 _x
     (setq _x (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _y
     (setq _y (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _w
     (setq _w (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _h
     (setq _h (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get alb_ros_msgs::BoundingBox :md5sum-) "c1d7daec9dd3af1e73d39f873a977099")
(setf (get alb_ros_msgs::BoundingBox :datatype-) "alb_ros_msgs/BoundingBox")
(setf (get alb_ros_msgs::BoundingBox :definition-)
      "uint32       x
uint32       y
uint32       w
uint32       h
")



(provide :alb_ros_msgs/BoundingBox "c1d7daec9dd3af1e73d39f873a977099")


