add_executable(bigfive big_five.cpp)
target_link_libraries(bigfive PRIVATE project_options project_warnings)

add_executable(stdthread std_thread.cpp)
target_link_libraries(stdthread PRIVATE project_options project_warnings)

add_executable(opbool op_bool.cpp)
target_link_libraries(opbool PRIVATE project_options project_warnings)
