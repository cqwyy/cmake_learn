# 这里没有具体连接什么，是进入src目录后，那里面由main，在main同目录有个总的cmakelists，这里是做总体配置

# cmake最低版本
cmake_minimum_required(VERSION 3.20)
# 本项目名
project(organize-3rd-parties)

# 设置C++17标准，需要满足标准，不用C++拓展语法
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/lib)#静态库输出目录--当前目录（根目录）下的lib目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)#可执行文件输出目录--当前目录（根目录）下的bin目录
set(CMAKE_LIBRRAY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)#动态库输出目录--当前目录（根目录）下的bin目录
# 进入src文件夹下面的CMakeLists.txt
add_subdirectory(src)

# 进入external文件夹下面的CMakeLists.txt
add_subdirectory(external)

# # 开启测试
# enable_testing()
# # 进入 tests 文件夹下面的CMakeLists.txt
# add_subdirectory(tests)