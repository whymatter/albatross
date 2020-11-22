# OpenCV install folder
set_property(GLOBAL PROPERTY OpenCV_DIR $ENV{OpenCV_DIR})

# Darknet include
set_property(GLOBAL PROPERTY Darknet_include_DIR $ENV{Darknet_DIR}/src)
set_property(GLOBAL PROPERTY Darknet_link_DIR $ENV{Darknet_DIR})