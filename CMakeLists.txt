cmake_minimum_required(VERSION 4.0)
project(Ezy_OS C)

set(CMAKE_C_STANDARD 23)

add_executable(Ezy_OS
        main.c
        file/workfiles.c
        additions/calculator.c
        additions/timenow.c
        additions/wearth/getWearth.c
        interface/interface.c
        additions/help/help.c
        additions/infos.c
        additions/notich.c
)

target_include_directories(Ezy_OS PRIVATE libraru)
target_link_libraries(Ezy_OS ws2_32)