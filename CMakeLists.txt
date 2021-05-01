cmake_minimum_required(VERSION 3.16)
project(threadpool C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_INSTALL_PREFIX .)


if(WIN32)
set(COMPILE_OPTIONS /Gs /GS /GT)
include(InstallRequiredSystemLibraries)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
elseif(UNIX)

endif()

add_compile_options(${COMPILE_OPTIONS})

add_library(ldthreadpool SHARED src/ldqueue.c)
target_include_directories(ldthreadpool PRIVATE src)


add_executable(queue_example src/examples/queue_example.c)
target_include_directories(queue_example PRIVATE src)
target_link_libraries(queue_example ldthreadpool)


install(TARGETS ldthreadpool DESTINATION bin)
install(TARGETS queue_example DESTINATION bin)
