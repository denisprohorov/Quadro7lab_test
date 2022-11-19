project(quadro7lab_emails_lib)


file(GLOB_RECURSE HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h) #collect all .h files
file(GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp) #collect all .cpp files
set(SOURCES ${HEADER_FILES} ${SOURCE_FILES})

add_library(emails ${SOURCES})

target_include_directories(emails PUBLIC ./include)