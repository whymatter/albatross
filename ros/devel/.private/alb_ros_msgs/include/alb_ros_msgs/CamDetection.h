// Generated by gencpp from file alb_ros_msgs/CamDetection.msg
// DO NOT EDIT!


#ifndef ALB_ROS_MSGS_MESSAGE_CAMDETECTION_H
#define ALB_ROS_MSGS_MESSAGE_CAMDETECTION_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <alb_ros_msgs/BoundingBox.h>

namespace alb_ros_msgs
{
template <class ContainerAllocator>
struct CamDetection_
{
  typedef CamDetection_<ContainerAllocator> Type;

  CamDetection_()
    : header()
    , boundingBox()
    , propability(0.0)
    , objectId(0)  {
    }
  CamDetection_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , boundingBox(_alloc)
    , propability(0.0)
    , objectId(0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef  ::alb_ros_msgs::BoundingBox_<ContainerAllocator>  _boundingBox_type;
  _boundingBox_type boundingBox;

   typedef float _propability_type;
  _propability_type propability;

   typedef uint32_t _objectId_type;
  _objectId_type objectId;





  typedef boost::shared_ptr< ::alb_ros_msgs::CamDetection_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::alb_ros_msgs::CamDetection_<ContainerAllocator> const> ConstPtr;

}; // struct CamDetection_

typedef ::alb_ros_msgs::CamDetection_<std::allocator<void> > CamDetection;

typedef boost::shared_ptr< ::alb_ros_msgs::CamDetection > CamDetectionPtr;
typedef boost::shared_ptr< ::alb_ros_msgs::CamDetection const> CamDetectionConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::alb_ros_msgs::CamDetection_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::alb_ros_msgs::CamDetection_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace alb_ros_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'alb_ros_msgs': ['/home/whymatter/github.com/albatross/ros/src/alb_ros_msgs/msg'], 'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::alb_ros_msgs::CamDetection_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::alb_ros_msgs::CamDetection_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::alb_ros_msgs::CamDetection_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::alb_ros_msgs::CamDetection_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::alb_ros_msgs::CamDetection_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::alb_ros_msgs::CamDetection_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::alb_ros_msgs::CamDetection_<ContainerAllocator> >
{
  static const char* value()
  {
    return "6ec64339c86b71d9eb90869f49d3c927";
  }

  static const char* value(const ::alb_ros_msgs::CamDetection_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x6ec64339c86b71d9ULL;
  static const uint64_t static_value2 = 0xeb90869f49d3c927ULL;
};

template<class ContainerAllocator>
struct DataType< ::alb_ros_msgs::CamDetection_<ContainerAllocator> >
{
  static const char* value()
  {
    return "alb_ros_msgs/CamDetection";
  }

  static const char* value(const ::alb_ros_msgs::CamDetection_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::alb_ros_msgs::CamDetection_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header       header\n\
\n\
BoundingBox  boundingBox\n\
float32        propability\n\
uint32       objectId\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: alb_ros_msgs/BoundingBox\n\
uint32       x\n\
uint32       y\n\
uint32       w\n\
uint32       h\n\
";
  }

  static const char* value(const ::alb_ros_msgs::CamDetection_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::alb_ros_msgs::CamDetection_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.boundingBox);
      stream.next(m.propability);
      stream.next(m.objectId);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct CamDetection_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::alb_ros_msgs::CamDetection_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::alb_ros_msgs::CamDetection_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "boundingBox: ";
    s << std::endl;
    Printer< ::alb_ros_msgs::BoundingBox_<ContainerAllocator> >::stream(s, indent + "  ", v.boundingBox);
    s << indent << "propability: ";
    Printer<float>::stream(s, indent + "  ", v.propability);
    s << indent << "objectId: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.objectId);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ALB_ROS_MSGS_MESSAGE_CAMDETECTION_H