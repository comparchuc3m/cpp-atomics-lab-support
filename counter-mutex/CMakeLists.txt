add_executable(counter-mutex)
target_sources(counter-mutex PRIVATE counter.cpp)
target_link_libraries(counter-mutex PRIVATE Microsoft.GSL::GSL)