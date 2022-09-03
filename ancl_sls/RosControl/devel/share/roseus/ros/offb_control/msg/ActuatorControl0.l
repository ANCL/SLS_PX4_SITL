;; Auto-generated. Do not edit!


(when (boundp 'offb_control::ActuatorControl0)
  (if (not (find-package "OFFB_CONTROL"))
    (make-package "OFFB_CONTROL"))
  (shadow 'ActuatorControl0 (find-package "OFFB_CONTROL")))
(unless (find-package "OFFB_CONTROL::ACTUATORCONTROL0")
  (make-package "OFFB_CONTROL::ACTUATORCONTROL0"))

(in-package "ROS")
;;//! \htmlinclude ActuatorControl0.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(intern "*PX4_MIX_FLIGHT_CONTROL*" (find-package "OFFB_CONTROL::ACTUATORCONTROL0"))
(shadow '*PX4_MIX_FLIGHT_CONTROL* (find-package "OFFB_CONTROL::ACTUATORCONTROL0"))
(defconstant offb_control::ActuatorControl0::*PX4_MIX_FLIGHT_CONTROL* 0)
(intern "*PX4_MIX_FLIGHT_CONTROL_VTOL_ALT*" (find-package "OFFB_CONTROL::ACTUATORCONTROL0"))
(shadow '*PX4_MIX_FLIGHT_CONTROL_VTOL_ALT* (find-package "OFFB_CONTROL::ACTUATORCONTROL0"))
(defconstant offb_control::ActuatorControl0::*PX4_MIX_FLIGHT_CONTROL_VTOL_ALT* 1)
(intern "*PX4_MIX_PAYLOAD*" (find-package "OFFB_CONTROL::ACTUATORCONTROL0"))
(shadow '*PX4_MIX_PAYLOAD* (find-package "OFFB_CONTROL::ACTUATORCONTROL0"))
(defconstant offb_control::ActuatorControl0::*PX4_MIX_PAYLOAD* 2)
(intern "*PX4_MIX_MANUAL_PASSTHROUGH*" (find-package "OFFB_CONTROL::ACTUATORCONTROL0"))
(shadow '*PX4_MIX_MANUAL_PASSTHROUGH* (find-package "OFFB_CONTROL::ACTUATORCONTROL0"))
(defconstant offb_control::ActuatorControl0::*PX4_MIX_MANUAL_PASSTHROUGH* 3)
(defclass offb_control::ActuatorControl0
  :super ros::object
  :slots (_header _group_mix _controls ))

(defmethod offb_control::ActuatorControl0
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:group_mix __group_mix) 0)
    ((:controls __controls) (make-array 8 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _header __header)
   (setq _group_mix (round __group_mix))
   (setq _controls __controls)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:group_mix
   (&optional __group_mix)
   (if __group_mix (setq _group_mix __group_mix)) _group_mix)
  (:controls
   (&optional __controls)
   (if __controls (setq _controls __controls)) _controls)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint8 _group_mix
    1
    ;; float32[8] _controls
    (* 4    8)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; uint8 _group_mix
       (write-byte _group_mix s)
     ;; float32[8] _controls
     (dotimes (i 8)
       (sys::poke (elt _controls i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint8 _group_mix
     (setq _group_mix (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; float32[8] _controls
   (dotimes (i (length _controls))
     (setf (elt _controls i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     )
   ;;
   self)
  )

(setf (get offb_control::ActuatorControl0 :md5sum-) "9eea0a80c88944fe2fb67f3b3768854b")
(setf (get offb_control::ActuatorControl0 :datatype-) "offb_control/ActuatorControl0")
(setf (get offb_control::ActuatorControl0 :definition-)
      "# raw servo values for direct actuator controls
#
# about groups, mixing and channels:
# https://pixhawk.org/dev/mixing

# constant for mixer group
uint8 PX4_MIX_FLIGHT_CONTROL = 0
uint8 PX4_MIX_FLIGHT_CONTROL_VTOL_ALT = 1
uint8 PX4_MIX_PAYLOAD = 2
uint8 PX4_MIX_MANUAL_PASSTHROUGH = 3
#uint8 PX4_MIX_FC_MC_VIRT = 4
#uint8 PX4_MIX_FC_FW_VIRT = 5

std_msgs/Header header
uint8 group_mix
float32[8] controls

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



(provide :offb_control/ActuatorControl0 "9eea0a80c88944fe2fb67f3b3768854b")


