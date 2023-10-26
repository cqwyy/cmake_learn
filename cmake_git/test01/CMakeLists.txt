cmake_minimum_required(VERSION 3.5 FATAL_ERROR)#设置CMake所需的最低版本
project(test1 LANGUAGES CXX)#声明了项目的名称和支持的编程语言(CXX代表C++)：
add_executable(hello_world hello_world.cpp)#生成可执行文件，文件名为参数一。可执行文件通
# 过编译和链接参数二（源文件）生成。（CMake将为编译器使用默认设置，并自动选择生成工具：）

# 将本文件与源文件hello-world.cpp放在相同的目录中。记住，它只能被命名为CMakeLists.txt。