; Auto-generated. Do not edit!


(cl:in-package unity_robotics_demo_msgs-msg)


;//! \htmlinclude RotJoints.msg.html

(cl:defclass <RotJoints> (roslisp-msg-protocol:ros-message)
  ((a1_joint
    :reader a1_joint
    :initarg :a1_joint
    :type cl:float
    :initform 0.0)
   (a2_joint
    :reader a2_joint
    :initarg :a2_joint
    :type cl:float
    :initform 0.0)
   (a3_joint
    :reader a3_joint
    :initarg :a3_joint
    :type cl:float
    :initform 0.0)
   (a4_joint
    :reader a4_joint
    :initarg :a4_joint
    :type cl:float
    :initform 0.0)
   (a5_joint
    :reader a5_joint
    :initarg :a5_joint
    :type cl:float
    :initform 0.0)
   (a6_joint
    :reader a6_joint
    :initarg :a6_joint
    :type cl:float
    :initform 0.0)
   (e1_joint
    :reader e1_joint
    :initarg :e1_joint
    :type cl:float
    :initform 0.0))
)

(cl:defclass RotJoints (<RotJoints>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RotJoints>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RotJoints)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name unity_robotics_demo_msgs-msg:<RotJoints> is deprecated: use unity_robotics_demo_msgs-msg:RotJoints instead.")))

(cl:ensure-generic-function 'a1_joint-val :lambda-list '(m))
(cl:defmethod a1_joint-val ((m <RotJoints>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader unity_robotics_demo_msgs-msg:a1_joint-val is deprecated.  Use unity_robotics_demo_msgs-msg:a1_joint instead.")
  (a1_joint m))

(cl:ensure-generic-function 'a2_joint-val :lambda-list '(m))
(cl:defmethod a2_joint-val ((m <RotJoints>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader unity_robotics_demo_msgs-msg:a2_joint-val is deprecated.  Use unity_robotics_demo_msgs-msg:a2_joint instead.")
  (a2_joint m))

(cl:ensure-generic-function 'a3_joint-val :lambda-list '(m))
(cl:defmethod a3_joint-val ((m <RotJoints>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader unity_robotics_demo_msgs-msg:a3_joint-val is deprecated.  Use unity_robotics_demo_msgs-msg:a3_joint instead.")
  (a3_joint m))

(cl:ensure-generic-function 'a4_joint-val :lambda-list '(m))
(cl:defmethod a4_joint-val ((m <RotJoints>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader unity_robotics_demo_msgs-msg:a4_joint-val is deprecated.  Use unity_robotics_demo_msgs-msg:a4_joint instead.")
  (a4_joint m))

(cl:ensure-generic-function 'a5_joint-val :lambda-list '(m))
(cl:defmethod a5_joint-val ((m <RotJoints>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader unity_robotics_demo_msgs-msg:a5_joint-val is deprecated.  Use unity_robotics_demo_msgs-msg:a5_joint instead.")
  (a5_joint m))

(cl:ensure-generic-function 'a6_joint-val :lambda-list '(m))
(cl:defmethod a6_joint-val ((m <RotJoints>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader unity_robotics_demo_msgs-msg:a6_joint-val is deprecated.  Use unity_robotics_demo_msgs-msg:a6_joint instead.")
  (a6_joint m))

(cl:ensure-generic-function 'e1_joint-val :lambda-list '(m))
(cl:defmethod e1_joint-val ((m <RotJoints>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader unity_robotics_demo_msgs-msg:e1_joint-val is deprecated.  Use unity_robotics_demo_msgs-msg:e1_joint instead.")
  (e1_joint m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RotJoints>) ostream)
  "Serializes a message object of type '<RotJoints>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'a1_joint))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'a2_joint))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'a3_joint))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'a4_joint))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'a5_joint))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'a6_joint))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'e1_joint))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RotJoints>) istream)
  "Deserializes a message object of type '<RotJoints>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'a1_joint) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'a2_joint) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'a3_joint) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'a4_joint) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'a5_joint) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'a6_joint) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'e1_joint) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RotJoints>)))
  "Returns string type for a message object of type '<RotJoints>"
  "unity_robotics_demo_msgs/RotJoints")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RotJoints)))
  "Returns string type for a message object of type 'RotJoints"
  "unity_robotics_demo_msgs/RotJoints")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RotJoints>)))
  "Returns md5sum for a message object of type '<RotJoints>"
  "e483f27ca9086997bb07bd67723e718f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RotJoints)))
  "Returns md5sum for a message object of type 'RotJoints"
  "e483f27ca9086997bb07bd67723e718f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RotJoints>)))
  "Returns full string definition for message of type '<RotJoints>"
  (cl:format cl:nil "float32 a1_joint~%float32 a2_joint~%float32 a3_joint~%float32 a4_joint~%float32 a5_joint~%float32 a6_joint~%float32 e1_joint~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RotJoints)))
  "Returns full string definition for message of type 'RotJoints"
  (cl:format cl:nil "float32 a1_joint~%float32 a2_joint~%float32 a3_joint~%float32 a4_joint~%float32 a5_joint~%float32 a6_joint~%float32 e1_joint~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RotJoints>))
  (cl:+ 0
     4
     4
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RotJoints>))
  "Converts a ROS message object to a list"
  (cl:list 'RotJoints
    (cl:cons ':a1_joint (a1_joint msg))
    (cl:cons ':a2_joint (a2_joint msg))
    (cl:cons ':a3_joint (a3_joint msg))
    (cl:cons ':a4_joint (a4_joint msg))
    (cl:cons ':a5_joint (a5_joint msg))
    (cl:cons ':a6_joint (a6_joint msg))
    (cl:cons ':e1_joint (e1_joint msg))
))
