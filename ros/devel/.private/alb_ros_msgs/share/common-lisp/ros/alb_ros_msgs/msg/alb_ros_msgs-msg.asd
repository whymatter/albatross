
(cl:in-package :asdf)

(defsystem "alb_ros_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "BoundingBox" :depends-on ("_package_BoundingBox"))
    (:file "_package_BoundingBox" :depends-on ("_package"))
    (:file "CamDetection" :depends-on ("_package_CamDetection"))
    (:file "_package_CamDetection" :depends-on ("_package"))
  ))