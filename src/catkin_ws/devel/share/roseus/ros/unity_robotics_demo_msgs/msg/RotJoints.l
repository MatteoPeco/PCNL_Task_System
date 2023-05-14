;; Auto-generated. Do not edit!


(when (boundp 'unity_robotics_demo_msgs::RotJoints)
  (if (not (find-package "UNITY_ROBOTICS_DEMO_MSGS"))
    (make-package "UNITY_ROBOTICS_DEMO_MSGS"))
  (shadow 'RotJoints (find-package "UNITY_ROBOTICS_DEMO_MSGS")))
(unless (find-package "UNITY_ROBOTICS_DEMO_MSGS::ROTJOINTS")
  (make-package "UNITY_ROBOTICS_DEMO_MSGS::ROTJOINTS"))

(in-package "ROS")
;;//! \htmlinclude RotJoints.msg.html


(defclass unity_robotics_demo_msgs::RotJoints
  :super ros::object
  :slots (_a1_joint _a2_joint _a3_joint _a4_joint _a5_joint _a6_joint _e1_joint ))

(defmethod unity_robotics_demo_msgs::RotJoints
  (:init
   (&key
    ((:a1_joint __a1_joint) 0.0)
    ((:a2_joint __a2_joint) 0.0)
    ((:a3_joint __a3_joint) 0.0)
    ((:a4_joint __a4_joint) 0.0)
    ((:a5_joint __a5_joint) 0.0)
    ((:a6_joint __a6_joint) 0.0)
    ((:e1_joint __e1_joint) 0.0)
    )
   (send-super :init)
   (setq _a1_joint (float __a1_joint))
   (setq _a2_joint (float __a2_joint))
   (setq _a3_joint (float __a3_joint))
   (setq _a4_joint (float __a4_joint))
   (setq _a5_joint (float __a5_joint))
   (setq _a6_joint (float __a6_joint))
   (setq _e1_joint (float __e1_joint))
   self)
  (:a1_joint
   (&optional __a1_joint)
   (if __a1_joint (setq _a1_joint __a1_joint)) _a1_joint)
  (:a2_joint
   (&optional __a2_joint)
   (if __a2_joint (setq _a2_joint __a2_joint)) _a2_joint)
  (:a3_joint
   (&optional __a3_joint)
   (if __a3_joint (setq _a3_joint __a3_joint)) _a3_joint)
  (:a4_joint
   (&optional __a4_joint)
   (if __a4_joint (setq _a4_joint __a4_joint)) _a4_joint)
  (:a5_joint
   (&optional __a5_joint)
   (if __a5_joint (setq _a5_joint __a5_joint)) _a5_joint)
  (:a6_joint
   (&optional __a6_joint)
   (if __a6_joint (setq _a6_joint __a6_joint)) _a6_joint)
  (:e1_joint
   (&optional __e1_joint)
   (if __e1_joint (setq _e1_joint __e1_joint)) _e1_joint)
  (:serialization-length
   ()
   (+
    ;; float32 _a1_joint
    4
    ;; float32 _a2_joint
    4
    ;; float32 _a3_joint
    4
    ;; float32 _a4_joint
    4
    ;; float32 _a5_joint
    4
    ;; float32 _a6_joint
    4
    ;; float32 _e1_joint
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _a1_joint
       (sys::poke _a1_joint (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _a2_joint
       (sys::poke _a2_joint (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _a3_joint
       (sys::poke _a3_joint (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _a4_joint
       (sys::poke _a4_joint (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _a5_joint
       (sys::poke _a5_joint (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _a6_joint
       (sys::poke _a6_joint (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _e1_joint
       (sys::poke _e1_joint (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _a1_joint
     (setq _a1_joint (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _a2_joint
     (setq _a2_joint (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _a3_joint
     (setq _a3_joint (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _a4_joint
     (setq _a4_joint (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _a5_joint
     (setq _a5_joint (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _a6_joint
     (setq _a6_joint (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _e1_joint
     (setq _e1_joint (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get unity_robotics_demo_msgs::RotJoints :md5sum-) "e483f27ca9086997bb07bd67723e718f")
(setf (get unity_robotics_demo_msgs::RotJoints :datatype-) "unity_robotics_demo_msgs/RotJoints")
(setf (get unity_robotics_demo_msgs::RotJoints :definition-)
      "float32 a1_joint
float32 a2_joint
float32 a3_joint
float32 a4_joint
float32 a5_joint
float32 a6_joint
float32 e1_joint

")



(provide :unity_robotics_demo_msgs/RotJoints "e483f27ca9086997bb07bd67723e718f")


