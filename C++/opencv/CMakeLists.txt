cmake_minimum_required(VERSION 2.8)
project( grimg )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

set( SRC_FILES  src/grimg.cpp
)

add_executable( grimg ${SRC_FILES} )
target_link_libraries( grimg ${OpenCV_LIBS} )
