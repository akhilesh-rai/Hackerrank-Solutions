add_library(GridSearch STATIC GridSearch.cpp GridSearch.h)
target_include_directories(GridSearch PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
