project(tests)

add_executable(${PROJECT_NAME} test_emails.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE emails ${CONAN_LIBS_GTEST})
