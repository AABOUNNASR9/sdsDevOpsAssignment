


add_executable(tests main.cpp tests_mylib.cpp)
target_link_libraries(tests PRIVATE mylib)
target_include_directories(tests PRIVATE 
    ${CMAKE_SOURCE_DIR}/deps/catch
    ${CMAKE_SOURCE_DIR}/deps/utils
)

add_test(
    NAME tests
    COMMAND $<TARGET_FILE:tests>
    )


add_custom_command(
    TARGET tests 
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "${CMAKE_SOURCE_DIR}/tests/data/input_image.bin" $<TARGET_FILE_DIR:tests>
)