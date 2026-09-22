cmake_minimum_required(VERSION 3.31)
project(SimpleMiniCommander)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED OFF)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)

add_compile_definitions(__cpp_lib_constexpr_exceptions=0)
add_executable(SimpleMiniCommander main.cpp
        header/fs/FILEOPEN.h
        header/fs/FILEMAKE.hpp

        header/helper/check_command.hpp
        header/helper/include_helper.h
        header/helper/path_ff.h

        cpp/fs/FILEOPEN.cpp
        cpp/fs/FILEMAKE.cpp

        cpp/helper/path_ff.cpp
        header/console/cmd.h
        cpp/console/cmd.cpp
        header/helper/helper.h
        cpp/helper/helper.cpp
        header/console/color_console.h
        cpp/console/color_console.cpp
        header/fs/DIRMAKE.h
        cpp/fs/DIRMAKE.cpp
        header/helper/Helperfs/HFILEF.h
        cpp/helper/Hfs/HFILEF.cpp
        header/fs/FILERMV.h
        cpp/fs/FILERMV.cpp
        header/date/date.h
        header/date/include_date.h
        cpp/date/date.cpp
        header/fs/FILEFIND.h
        cpp/fs/FILEFIND.cpp
        header/fs/explorer.h
        cpp/fs/explorer.cpp
        header/text/io_text.h
        cpp/text/io_text.cpp
        header/fs/disk.h
        cpp/fs/disk.cpp
        cpp/fs/space.cpp
        header/fs/space.h
        header/fs/copy.h
        cpp/fs/copy.cpp
        header/fs/MOVE.h
        cpp/fs/MOVE.cpp
        header/helper/helper_echo.h
        cpp/helper/helper_echo.cpp
        cpp/json/JSON.cpp
        header/json/JSON.h
        header/helper/IO.hpp
        header/console/help.h
        cpp/console/help.cpp
        header/fs/rename.h
        cpp/fs/rename.cpp
        header/Clipboard/Clipboard.h
        cpp/Clipboard/Clipboard.cpp
)
target_link_libraries(SimpleMiniCommander PRIVATE stdc++exp Qt5::Widgets)
