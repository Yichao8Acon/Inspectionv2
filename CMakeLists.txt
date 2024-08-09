cmake_minimum_required(VERSION 3.26)
project(Inspectionv2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "C:/Users/yichao.qin/tools/Qt/6.6.0/msvc2019_64/lib/cmake")
set(QML2_IMPORT_PATH "C:/Users/yichao.qin/tools/Qt/6.6.0/msvc2019_64/qml")
link_directories("${CMAKE_CURRENT_SOURCE_DIR}//lib")


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Qml
        Quick
        SerialPort
        REQUIRED)
find_package(OpenCV REQUIRED)


include_directories("${CMAKE_CURRENT_SOURCE_DIR}//include")
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(Inspectionv2
        main.cpp
        resource.qrc
        src/ObjectLocator.cpp
        src/ObjectLocator.hpp
)


target_link_libraries(Inspectionv2
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Qml
        Qt::Quick
        Qt::SerialPort
        ${OpenCV_LIBS}
        MVCAMSDK_X64
)
