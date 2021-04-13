add_executable(five five.cpp)
target_link_libraries(five PRIVATE project_options project_warnings)

add_executable(stdthread std_thread.cpp)
target_link_libraries(stdthread PRIVATE project_options project_warnings)

add_executable(opbool op_bool.cpp)
target_link_libraries(opbool PRIVATE project_options project_warnings)

add_executable(fork fork.cpp)
target_link_libraries(fork PRIVATE project_options project_warnings)

add_executable(rusage rusage.cpp)
target_link_libraries(rusage PRIVATE project_options project_warnings)