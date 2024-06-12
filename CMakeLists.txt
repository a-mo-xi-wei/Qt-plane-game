cmake_minimum_required(VERSION 3.10)

project(plane_game VERSION 1.0 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED Widgets)

set(PROJECT_SOURCES 
	main.cpp
	QGame.h
	QGame.cpp
	Entity.h
	Sprite.h
	Sprite.cpp 
	PlayerPlane.h
	PlayerPlane.cpp
	Bullet.h
	Bullet.cpp
	EntityManager.h
	Global.h
	Map.h
	Map.cpp
	Resource.qrc
)


add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})


target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)