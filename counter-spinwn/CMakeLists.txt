add_executable(counter-spinwn)
target_sources(counter-spinwn PRIVATE counter.cpp)
target_link_libraries(counter-spinwn PRIVATE Microsoft.GSL::GSL)