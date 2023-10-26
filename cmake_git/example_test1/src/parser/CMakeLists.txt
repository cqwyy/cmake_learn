add_library(parser "")#编译静态库--默认就是静态库,第一个参数是定义库的名字
# 需要的源码用下面的方式加
# 这种方式更好，因为可以更细粒度地访问权限。
# 例如对cpp文件就是PRIVATE，而hpp则是PUBLIC

# 注：${CMAKE_CURRENT_LIST_DIR}代表当前的CMakeLists.txt文件所在的绝对路径。

target_sources(parser#加到哪个库
PRIVATE
    parser.cpp#加什么
PUBLIC
    parser.hpp
)
# 增加头文件目录
target_include_directories(parser
PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}#当前文件夹
)