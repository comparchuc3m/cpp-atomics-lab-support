add_executable(counter-spinra)
target_sources(counter-spinra PRIVATE counter.cpp)
target_link_libraries(counter-spinra PRIVATE Microsoft.GSL::GSL)