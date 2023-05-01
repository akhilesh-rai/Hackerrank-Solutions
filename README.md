# Hackerrank-Solutions
## Building the project
 - To build the project, navigate to the project directory in a terminal and run the following commands:  
   mkdir build  
   cd build  
   cmake .. -G "Visual Studio 17 2022" -A x64     
 - Visual Studio sln file "Hackerrank-Solution.sln" is generated at 'project/build' folder.
 
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
