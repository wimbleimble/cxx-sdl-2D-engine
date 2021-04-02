cmake_minimum_required(VERSION 3.7...3.18)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
	cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)

project(SDLTest VERSION 0.0.1
		DESCRIPTION "testing testing 123"
		LANGUAGES CXX)

set(src
	Main.cpp
	engine/Engine.cpp
	engine/Err.cpp
	engine/SDLHandler.cpp
	engine/LogHandler.cpp
	engine/Sprite.cpp
	engine/Vec2.cpp
	engine/State.cpp
	engine/Actor.cpp
	engine/Layer.cpp
	engine/Scene.cpp
	engine/Camera.cpp
	FlippyState.cpp
	WelpState.cpp
	Character.cpp
)

find_package(SDL2 REQUIRED)
find_package(SDL2_Image REQUIRED) 

add_executable(${PROJECT_NAME}
	${src}
)

target_include_directories(${PROJECT_NAME} PUBLIC ../include)
target_include_directories(${PROJECT_NAME} PUBLIC ../include/engine)
target_include_directories(${PROJECT_NAME} PUBLIC ${SDL2_INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME} PUBLIC ${SDL2_IMAGE_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${SDL2_IMAGE_LIBRARIES})

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E
	copy_directory "../lib" ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E
	copy_directory "../assets" ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})