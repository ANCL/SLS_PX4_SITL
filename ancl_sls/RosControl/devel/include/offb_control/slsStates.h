// Generated by gencpp from file offb_control/slsStates.msg
// DO NOT EDIT!


#ifndef OFFB_CONTROL_MESSAGE_SLSSTATES_H
#define OFFB_CONTROL_MESSAGE_SLSSTATES_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace offb_control
{
template <class ContainerAllocator>
struct slsStates_
{
  typedef slsStates_<ContainerAllocator> Type;

  slsStates_()
    : header()
    , sls_states()
    , ref_states()  {
      sls_states.assign(0.0);

      ref_states.assign(0.0);
  }
  slsStates_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , sls_states()
    , ref_states()  {
  (void)_alloc;
      sls_states.assign(0.0);

      ref_states.assign(0.0);
  }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef boost::array<double, 16>  _sls_states_type;
  _sls_states_type sls_states;

   typedef boost::array<double, 4>  _ref_states_type;
  _ref_states_type ref_states;





  typedef boost::shared_ptr< ::offb_control::slsStates_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::offb_control::slsStates_<ContainerAllocator> const> ConstPtr;

}; // struct slsStates_

typedef ::offb_control::slsStates_<std::allocator<void> > slsStates;

typedef boost::shared_ptr< ::offb_control::slsStates > slsStatesPtr;
typedef boost::shared_ptr< ::offb_control::slsStates const> slsStatesConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::offb_control::slsStates_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::offb_control::slsStates_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::offb_control::slsStates_<ContainerAllocator1> & lhs, const ::offb_control::slsStates_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.sls_states == rhs.sls_states &&
    lhs.ref_states == rhs.ref_states;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::offb_control::slsStates_<ContainerAllocator1> & lhs, const ::offb_control::slsStates_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace offb_control

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::offb_control::slsStates_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::offb_control::slsStates_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::offb_control::slsStates_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::offb_control::slsStates_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::offb_control::slsStates_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::offb_control::slsStates_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::offb_control::slsStates_<ContainerAllocator> >
{
  static const char* value()
  {
    return "7d89c16ac09a0000784fb21fb6327492";
  }

  static const char* value(const ::offb_control::slsStates_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x7d89c16ac09a0000ULL;
  static const uint64_t static_value2 = 0x784fb21fb6327492ULL;
};

template<class ContainerAllocator>
struct DataType< ::offb_control::slsStates_<ContainerAllocator> >
{
  static const char* value()
  {
    return "offb_control/slsStates";
  }

  static const char* value(const ::offb_control::slsStates_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::offb_control::slsStates_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#sls_state\n"
"std_msgs/Header header\n"
"float64[16] sls_states\n"
"float64[4] ref_states\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
;
  }

  static const char* value(const ::offb_control::slsStates_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::offb_control::slsStates_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.sls_states);
      stream.next(m.ref_states);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct slsStates_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::offb_control::slsStates_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::offb_control::slsStates_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "sls_states[]" << std::endl;
    for (size_t i = 0; i < v.sls_states.size(); ++i)
    {
      s << indent << "  sls_states[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.sls_states[i]);
    }
    s << indent << "ref_states[]" << std::endl;
    for (size_t i = 0; i < v.ref_states.size(); ++i)
    {
      s << indent << "  ref_states[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.ref_states[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // OFFB_CONTROL_MESSAGE_SLSSTATES_H