; Auto-generated. Do not edit!


(cl:in-package offb_control-msg)


;//! \htmlinclude slsStates.msg.html

(cl:defclass <slsStates> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (sls_states
    :reader sls_states
    :initarg :sls_states
    :type (cl:vector cl:float)
   :initform (cl:make-array 16 :element-type 'cl:float :initial-element 0.0))
   (ref_states
    :reader ref_states
    :initarg :ref_states
    :type (cl:vector cl:float)
   :initform (cl:make-array 4 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass slsStates (<slsStates>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <slsStates>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'slsStates)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name offb_control-msg:<slsStates> is deprecated: use offb_control-msg:slsStates instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <slsStates>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader offb_control-msg:header-val is deprecated.  Use offb_control-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'sls_states-val :lambda-list '(m))
(cl:defmethod sls_states-val ((m <slsStates>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader offb_control-msg:sls_states-val is deprecated.  Use offb_control-msg:sls_states instead.")
  (sls_states m))

(cl:ensure-generic-function 'ref_states-val :lambda-list '(m))
(cl:defmethod ref_states-val ((m <slsStates>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader offb_control-msg:ref_states-val is deprecated.  Use offb_control-msg:ref_states instead.")
  (ref_states m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <slsStates>) ostream)
  "Serializes a message object of type '<slsStates>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'sls_states))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'ref_states))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <slsStates>) istream)
  "Deserializes a message object of type '<slsStates>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (cl:setf (cl:slot-value msg 'sls_states) (cl:make-array 16))
  (cl:let ((vals (cl:slot-value msg 'sls_states)))
    (cl:dotimes (i 16)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-double-float-bits bits)))))
  (cl:setf (cl:slot-value msg 'ref_states) (cl:make-array 4))
  (cl:let ((vals (cl:slot-value msg 'ref_states)))
    (cl:dotimes (i 4)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-double-float-bits bits)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<slsStates>)))
  "Returns string type for a message object of type '<slsStates>"
  "offb_control/slsStates")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'slsStates)))
  "Returns string type for a message object of type 'slsStates"
  "offb_control/slsStates")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<slsStates>)))
  "Returns md5sum for a message object of type '<slsStates>"
  "7d89c16ac09a0000784fb21fb6327492")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'slsStates)))
  "Returns md5sum for a message object of type 'slsStates"
  "7d89c16ac09a0000784fb21fb6327492")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<slsStates>)))
  "Returns full string definition for message of type '<slsStates>"
  (cl:format cl:nil "#sls_state~%std_msgs/Header header~%float64[16] sls_states~%float64[4] ref_states~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'slsStates)))
  "Returns full string definition for message of type 'slsStates"
  (cl:format cl:nil "#sls_state~%std_msgs/Header header~%float64[16] sls_states~%float64[4] ref_states~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <slsStates>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'sls_states) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'ref_states) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <slsStates>))
  "Converts a ROS message object to a list"
  (cl:list 'slsStates
    (cl:cons ':header (header msg))
    (cl:cons ':sls_states (sls_states msg))
    (cl:cons ':ref_states (ref_states msg))
))
