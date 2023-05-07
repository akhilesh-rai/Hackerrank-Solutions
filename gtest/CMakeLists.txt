
add_executable(unitTests main.cpp)
target_link_libraries(unitTests 
                      GTest::gtest_main
					  QueensAttack2
					  OrganizeContainer
					  GridSearch
					  BiggerIsGreater
					  AlmostSorted
                      SurfaceArea )

include(GoogleTest)
gtest_discover_tests(unitTests)
