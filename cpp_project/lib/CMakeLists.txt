

add_library(mylib SHARED mylib.cpp mylib.h)
target_include_directories(mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_definitions(mylib PRIVATE ACME_MYLIB_EXPORTS)


add_custom_command(
    TARGET mylib 
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:mylib> "${CMAKE_SOURCE_DIR}/../py/acme_mylib/$<TARGET_FILE_NAME:mylib>"
)