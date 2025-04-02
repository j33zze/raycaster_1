cmake_minimum_required(VERSION 3.30.0)
project(raycaster_project VERSION 0.1.0)
cmake_policy(SET CMP0072 NEW)

find_package(OpenGL REQUIRED)

add_executable(${PROJECT_NAME} 
    main.cpp
    src/glad/glad.h
    src/glad/glad.c
)

target_link_libraries(raycaster_project 
    glfw
    OpenGL::GL
)