cmake_minimum_required(VERSION 3.22)
project(quadro7lab)

set(CMAKE_CXX_STANDARD 17)

include(conanBuild/conanbuildinfo.cmake)
conan_basic_setup()

set(emails_lib_folder "${CMAKE_CURRENT_SOURCE_DIR}/modules/emails/")

add_subdirectory(${emails_lib_folder})
add_subdirectory(./tests)

add_executable(main ${CMAKE_CURRENT_SOURCE_DIR}/modules/main.cpp)
target_link_libraries(main PUBLIC emails ${CONAN_LIBS_GLOG} ${CONAN_LIBS_GFLAGS})

file(GLOB_RECURSE resources "./resources/*.*")# move all resources
foreach (resource ${resources})
    get_filename_component(filename ${resource} NAME)
    get_filename_component(dir ${resource} DIRECTORY)
    get_filename_component(dirname ${dir} NAME)

    set(output "")

    while (NOT ${dirname} STREQUAL resources)
        get_filename_component(path_component ${dir} NAME)
        set(output "${path_component}/${output}")
        get_filename_component(dir ${dir} DIRECTORY)
        get_filename_component(dirname ${dir} NAME)
    endwhile ()

    set(output "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/resources/${output}${filename}")
    configure_file(${resource} ${output} COPYONLY)
endforeach ()