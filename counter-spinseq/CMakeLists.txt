add_executable(counter-spinseq)
target_sources(counter-spinseq PRIVATE counter.cpp)
target_link_libraries(counter-spinseq PRIVATE Microsoft.GSL::GSL)