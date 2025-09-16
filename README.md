# Programming-Abstraction-in-Cpp
This repository contains original solutions to problems from the Stanford CS106 B textbook, Programming Abstractions in C++ by Eric S. Roberts. These are solutions to problems at the end of each chapter, and they are 100% my own. Each problem has its own unit testing suite using the Google Test Framework. The Google Test framework uses a CMake file to configure the build system and declare a dependency on GoogleTest using `FetchContent` **CMake module**. 


# CLI Setup

Specify the project name in CMakeLists.txt `project(project_name LANGUAGES CXX)` to name your executable. 

```

cd project-name
mkdir build
cd build
cmake ..
cmake --build . -j
./project_name
```
