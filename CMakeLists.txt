cmake_minimum_required(VERSION 3.10)
project(GimbalProject)

set(CMAKE_C_STANDARD 17)

option(COMPILE_FOR_DREAMCAST "Compilation for Dreamcast" OFF)

if(COMPILE_FOR_DREAMCAST)
	find_package(SDL3 REQUIRED)
	find_package(SDL3_image CONFIG REQUIRED)
else()
	add_subdirectory(deps/SDL)
	add_subdirectory(deps/SDL_image)
endif()

add_subdirectory(deps/libgimbal)

include_directories(BEFORE .)

if(COMPILE_FOR_DREAMCAST)
	file(GLOB SRCS src/*.c src/*.h)
else()
	file(GLOB SRCS src/*.c deps/glad/3_3/*.c src/*.h deps/glad/3_3/*.h)
endif()

add_executable(gimbal_project main.c ${SRCS})

if(COMPILE_FOR_DREAMCAST)
	target_link_libraries(gimbal_project  PRIVATE SDL3::SDL3 SDL3_image::SDL3_image GL pthread libGimbal)
else()
	target_link_libraries(gimbal_project PRIVATE SDL3::SDL3 SDL3_image::SDL3_image libGimbal)
endif()
