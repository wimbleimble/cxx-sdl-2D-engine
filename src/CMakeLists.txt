cmake_minimum_required(VERSION 3.7...3.18)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
	cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project(SDLTest VERSION 0.0.1
		DESCRIPTION "testing testing 123"
		LANGUAGES CXX)


set(cppFiles
	Main.cpp
	Err.cpp
	SDLHandler.cpp
	LogHandler.cpp
	Sprite.cpp
	Vec2.cpp
	Engine.cpp
	Renderer.cpp
	MessageBus.cpp
	FlippyState.cpp
)

find_package(SDL2 REQUIRED)
find_package(SDL2_Image REQUIRED) 
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(${PROJECT_NAME}
	${headerFiles}
	${cppFiles}
)
target_include_directories(${PROJECT_NAME} PUBLIC ../include)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${SDL2_IMAGE_LIBRARIES})