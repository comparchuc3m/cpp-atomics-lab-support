add_executable(counter)
target_sources(counter PRIVATE counter.cpp)
target_link_libraries(counter PRIVATE Microsoft.GSL::GSL)