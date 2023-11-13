cmake_minimum_required(VERSION 3.0)
project(ComputerGraphics)

set(CMAKE_CXX_STANDARD 17)

#find_package(OpenGL REQUIRED)
#find_package(GLUT REQUIRED)

add_executable(ComputerGraphics 03_timer.cpp)

#target_link_libraries(ComputerGraphics ${OPENGL_LIBRARIES})
#target_link_libraries(ComputerGraphics ${GLUT_LIBRARIES})
#target_link_libraries(ComputerGraphics -lopengl32 -g -lfreeglut)
target_link_libraries(ComputerGraphics -lOpenGL32 -lfreeGLUT)