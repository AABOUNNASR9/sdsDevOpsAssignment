project(cpp_project)
enable_testing()
cmake_minimum_required(VERSION 3.16)

add_subdirectory(lib)
add_subdirectory(app)
add_subdirectory(tests)