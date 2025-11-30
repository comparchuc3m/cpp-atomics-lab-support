add_executable(counter-atomic)
target_sources(counter-atomic PRIVATE counter.cpp)
target_link_libraries(counter-atomic PRIVATE Microsoft.GSL::GSL)