# Hackerrank-Solutions
## To run the examples:
 - Create Visual Studio solution:  simply run "cmake ." at root directory level. (CMake version 3.5 or greater needed)
 - Visual Studio sln file "Hackerrank-Solution.sln" is generated at root folder.
 
## Folder Structure:
    project/
    ├── app/
    │   ├── main.cpp
    │   └── CMakeLists.txt
    ├── libs/
    │   ├── Problem_1
    |   |    ├── problem_1.cpp
    |   |    ├── problem_1.h
    |   |    └── CMakeLists.txt
    |   ├── Problem_2
    |   |    ├── problem_2.cpp
    |   |    ├── problem_2.h
    |   |    └── CMakeLists.txt
    │   ├── Problem_3
    │   └── ...
    ├── docs
    |   └── html
    |         └── pages.html
    ├── CMakeLists.txt
    └── README.md


## Table of Contents:
| Questions | Solution |
| ---------------| ----------------|
| [Queen's Attack 2](https://www.hackerrank.com/challenges/queens-attack-2/problem) | [QueensAttack2.cpp](https://github.com/akhilesh-rai/Hackerrank-Solutions/tree/main/libs/Algorithms/Implementation/QueensAttack2)   |
| [Organizing Container of Balls](https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem) | [OrganizeContainer.cpp](https://github.com/akhilesh-rai/Hackerrank-Solutions/tree/main/libs/Algorithms/Implementation/OrganizeContainer) |

## Debug Info
- Many problems have debug code disbaled by predompiler define called "DEBUG", defined/commented out in the respective .h file
- You can use it to print additional useful info into the console
