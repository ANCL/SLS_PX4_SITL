
(cl:in-package :asdf)

(defsystem "offb_control-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "ActuatorControl0" :depends-on ("_package_ActuatorControl0"))
    (:file "_package_ActuatorControl0" :depends-on ("_package"))
    (:file "slsStates" :depends-on ("_package_slsStates"))
    (:file "_package_slsStates" :depends-on ("_package"))
  ))