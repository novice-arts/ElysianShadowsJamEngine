cmake_minimum_required(VERSION 3.10)
project(GimbalProject)

set(CMAKE_C_STANDARD 17)

option(COMPILE_FOR_DREAMCAST "Compilation for Dreamcast" OFF)
option(PROJECT_IS_EXTERNAL   "Use separate folder for project" OFF)

if(PROJECT_IS_EXTERNAL)
	set(PROJECT_PARENT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/../ElysianShadowsJam_Game)
else()
	set(PROJECT_PARENT_FOLDER .)
endif()


if(COMPILE_FOR_DREAMCAST)
	find_package(SDL3 REQUIRED)
	find_package(SDL3_image CONFIG REQUIRED)
else()
	add_subdirectory(deps/SDL)
	add_subdirectory(deps/SDL_image)
endif()

add_subdirectory(deps/libgimbal)

include_directories(BEFORE .)
if(PROJECT_IS_EXTERNAL)
	include_directories(BEFORE ${PROJECT_PARENT_FOLDER})
endif()



if(COMPILE_FOR_DREAMCAST)
	file(GLOB SRCS src/*.c src/engine/*.c )
else()
	file(GLOB SRCS src/*.c src/engine/*.c src/platform/gl.c deps/glad/3_3/*.c deps/glad/3_3/*.h)
endif()

add_executable(gimbal_project main.c ${PROJECT_PARENT_FOLDER}/project/project.c ${SRCS})

if(COMPILE_FOR_DREAMCAST)
	target_link_libraries(gimbal_project  PRIVATE SDL3::SDL3 SDL3_image::SDL3_image GL pthread libGimbal)
else()
	target_link_libraries(gimbal_project PRIVATE SDL3::SDL3 SDL3_image::SDL3_image libGimbal)
endif()
