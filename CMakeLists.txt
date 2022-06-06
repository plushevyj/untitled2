cmake_minimum_required(VERSION 3.22)
project(untitled2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Sql
        Widgets
        Xml
        REQUIRED)

add_executable(untitled2 main.cpp login_window/login_window.cpp login_window/login_window.h enter_code_window/enter_code_window.cpp enter_code_window/enter_code_window.h sql_service/sql_service.cpp sql_service/sql_service.h admin_home_window/admin_home_window.cpp admin_home_window/admin_home_window.h registration_window/registration_window.cpp registration_window/registration_window.h)
target_link_libraries(untitled2
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Sql
        Qt5::Xml
        )

