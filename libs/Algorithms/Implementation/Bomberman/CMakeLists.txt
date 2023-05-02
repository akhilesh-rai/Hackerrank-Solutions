add_library(Bomberman STATIC Bomberman.cpp Bomberman.h)
target_include_directories(Bomberman PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
