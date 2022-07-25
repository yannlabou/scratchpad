add_executable(cv cond_variable.cpp)
target_link_libraries(cv PRIVATE project_options project_warnings -fsanitize="thread")

add_executable(diter dir_iterator.cpp)
target_link_libraries(diter PRIVATE project_options project_warnings)

add_executable(fib find_is_broken.cpp)
target_link_libraries(fib PRIVATE project_options project_warnings)

add_executable(five five.cpp)
target_link_libraries(five PRIVATE project_options project_warnings)

add_executable(fork fork.cpp)
target_link_libraries(fork PRIVATE project_options project_warnings)

add_executable(mmap mmap.cpp)
target_link_libraries(mmap PRIVATE project_options project_warnings)

add_executable(opbool op_bool.cpp)
target_link_libraries(opbool PRIVATE project_options project_warnings)

add_executable(rusage rusage.cpp)
target_link_libraries(rusage PRIVATE project_options project_warnings)

add_executable(selfpath self_path.cpp)
target_link_libraries(selfpath PRIVATE project_options project_warnings)

add_executable(threadcost thread_cost.cpp)
target_link_libraries(threadcost PRIVATE project_options project_warnings -fsanitize="thread")

add_executable(thread thread.cpp)
target_link_libraries(thread PRIVATE project_options project_warnings -fsanitize="thread")
