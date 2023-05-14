
(cl:in-package :asdf)

(defsystem "unity_robotics_demo_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
)
  :components ((:file "_package")
    (:file "PosRot" :depends-on ("_package_PosRot"))
    (:file "_package_PosRot" :depends-on ("_package"))
    (:file "PoseRPY" :depends-on ("_package_PoseRPY"))
    (:file "_package_PoseRPY" :depends-on ("_package"))
    (:file "RPY" :depends-on ("_package_RPY"))
    (:file "_package_RPY" :depends-on ("_package"))
    (:file "RotJoints" :depends-on ("_package_RotJoints"))
    (:file "_package_RotJoints" :depends-on ("_package"))
    (:file "UnityColor" :depends-on ("_package_UnityColor"))
    (:file "_package_UnityColor" :depends-on ("_package"))
  ))