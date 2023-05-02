cmake_minimum_required(VERSION 3.5)

project(Hackerrank-Solutions LANGUAGES CXX)

add_subdirectory(libs/Algorithms/Implementation/QueensAttack2)
add_subdirectory(libs/Algorithms/Implementation/OrganizeContainer)
add_subdirectory(libs/Algorithms/Implementation/BiggerIsGreater)
add_subdirectory(libs/Algorithms/Implementation/GridSearch)


add_subdirectory(app)

################ G Test Start ##########################
# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_subdirectory(gtest)
################ G Test End ############################


