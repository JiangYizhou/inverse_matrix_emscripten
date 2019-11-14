cmake_minimum_required(VERSION 3.0)
set (CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Release)

OPTION(_NDEBUG "skip ASSERT of the project" ON)
if(_NDEBUG)
  ADD_DEFINITIONS(-D_NDEBUG)
endif(_NDEBUG)

project( inversematrix )

add_executable( inversematrix
InverseMatrix.cpp
)

set_target_properties(inversematrix PROPERTIES COMPILE_FLAGS "-msimd128")

SET_PROPERTY(TARGET inversematrix APPEND_STRING PROPERTY LINK_FLAGS "-s USE_GLFW=3 -s USE_SDL=0 -s STRICT=1 -s USE_WEBGL2=1 -lGL -lglfw -s TOTAL_MEMORY=512MB -s DISABLE_EXCEPTION_CATCHING=0 -s SIMD=1")
SET_PROPERTY(TARGET inversematrix PROPERTY SUFFIX ".html")
