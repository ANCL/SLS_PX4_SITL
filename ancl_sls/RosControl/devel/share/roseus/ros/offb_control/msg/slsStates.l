;; Auto-generated. Do not edit!


(when (boundp 'offb_control::slsStates)
  (if (not (find-package "OFFB_CONTROL"))
    (make-package "OFFB_CONTROL"))
  (shadow 'slsStates (find-package "OFFB_CONTROL")))
(unless (find-package "OFFB_CONTROL::SLSSTATES")
  (make-package "OFFB_CONTROL::SLSSTATES"))

(in-package "ROS")
;;//! \htmlinclude slsStates.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass offb_control::slsStates
  :super ros::object
  :slots (_header _sls_states _ref_states ))

(defmethod offb_control::slsStates
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:sls_states __sls_states) (make-array 16 :initial-element 0.0 :element-type :float))
    ((:ref_states __ref_states) (make-array 4 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _header __header)
   (setq _sls_states __sls_states)
   (setq _ref_states __ref_states)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:sls_states
   (&optional __sls_states)
   (if __sls_states (setq _sls_states __sls_states)) _sls_states)
  (:ref_states
   (&optional __ref_states)
   (if __ref_states (setq _ref_states __ref_states)) _ref_states)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float64[16] _sls_states
    (* 8    16)
    ;; float64[4] _ref_states
    (* 8    4)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float64[16] _sls_states
     (dotimes (i 16)
       (sys::poke (elt _sls_states i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[4] _ref_states
     (dotimes (i 4)
       (sys::poke (elt _ref_states i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float64[16] _sls_states
   (dotimes (i (length _sls_states))
     (setf (elt _sls_states i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     )
   ;; float64[4] _ref_states
   (dotimes (i (length _ref_states))
     (setf (elt _ref_states i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     )
   ;;
   self)
  )

(setf (get offb_control::slsStates :md5sum-) "7d89c16ac09a0000784fb21fb6327492")
(setf (get offb_control::slsStates :datatype-) "offb_control/slsStates")
(setf (get offb_control::slsStates :definition-)
      "#sls_state
std_msgs/Header header
float64[16] sls_states
float64[4] ref_states

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
string frame_id

")



(provide :offb_control/slsStates "7d89c16ac09a0000784fb21fb6327492")


