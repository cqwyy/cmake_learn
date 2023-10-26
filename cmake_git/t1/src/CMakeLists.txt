cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)#静态库输出目录--build目录下的lib目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)#可执行文件输出目录--build目录下的bin目录
set(CMAKE_LIBRRAY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)#动态库输出目录--build目录下的bin目录--动态库和exe要么放在同一目录下，要么放在系统目录下
# 因为动态库的内容不被编译进去，而是在程序执行的时候，动态的引用动态库中的内容（系统目录：C/Windons/System32）

project(Main VERSION 1.0)

option(DATE_ENABLE "output date" ON)
if(DATE_ENABLE)
    set(DATE "2022.11")#变量被打开，就设置DATE为2022.11
endif()

configure_file(config.h.in config.h)

add_subdirectory(calc)#添加子目录，执行到这句时就进入到calc子目录中的cmakelists，执行该cmakelists，所以在子目录下也创建一个cmkaelists
# 在生成可执行程序之后进行连接

# add_executable(Main main.cpp)#生成tarfet，名为Main
# 推荐用下列方法生成可执行文件
add_executable(Main)
target_sources(Main
PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp#当前txt所在文件夹
)


# 连接库(静态库为Main私有的库，可以用私有连接)----以下可用一个函数完成
target_link_libraries(Main PUBLIC addition)#为哪个目标连接 ，PUBLIC连接，连接addition目标。因为这个addition在上面添加子目录时候生成了，所以可以找到
target_link_libraries(Main PUBLIC subtract)
# 连接别人的库就没有库名了，要用绝对路径
target_link_libraries(Main PUBLIC D:/vscode/cpp_program/add_learn/cmake_learn/cmake_practice/t1/other_lib/libmultiply.a)#要用单反斜杠
target_link_libraries(Main PUBLIC D:/vscode/cpp_program/add_learn/cmake_learn/cmake_practice/t1/other_lib/libdivision.dll)
# 然后为目标要添加头搜索路径

# include_directories(${PROJECT_BINARY_DIR})
#这里直接把头文件添加到可执行文件目标，之前的案例是库文件夹连接头文件，然后可执行文件连接库文件同样可以找到，更推荐用之前的方法(因为库自动找头文件这里一一列举可能会漏，新添加时候也不方便)
target_include_directories(Main PUBLIC
                            "${PROJECT_BINARY_DIR}"#这个变量里存的build目录，让编译器去build找头文件 （双引号有没有都行）
                            ${PROJECT_SOURCE_DIR}/calc/Inc #这个变量存src目录
                            ${PROJECT_SOURCE_DIR}/../other_lib)    #src的上一级下的文件夹（跟src同级）     
                            

# 用如下指定路径的方法安装到跟src同级的install下，也可以路径写为bin lib include 然后构建，然后安装--cmake --install . --prefix ../install  
# (指定路径，当前在build，安装到上一级目录下的install)也有同样效果
install(TARGETS Main DESTINATION ${PROJECT_SOURCE_DIR}/../install/bin) #可执行文件安装到bin
# 连接的库是在子目录下创建的，所以在子目录下安装
#外部库直接用普通文件安装
install(FILES D:/vscode/cpp_program/add_learn/cmake_learn/cmake_practice/t1/other_lib/libmultiply.a DESTINATION ${PROJECT_SOURCE_DIR}/../install/lib)
install(FILES D:/vscode/cpp_program/add_learn/cmake_learn/cmake_practice/t1/other_lib/libdivision.dll DESTINATION ${PROJECT_SOURCE_DIR}/../install/bin)
# 安装头文件
install(FILES ${PROJECT_BINARY_DIR}/config.h DESTINATION ${PROJECT_SOURCE_DIR}/../install/include)
# 链接库的头文件在子目录下安装
# 外部引用的头文件
install(FILES D:/vscode/cpp_program/add_learn/cmake_learn/cmake_practice/t1/other_lib/division.h DESTINATION ${PROJECT_SOURCE_DIR}/../install/include)
install(FILES D:/vscode/cpp_program/add_learn/cmake_learn/cmake_practice/t1/other_lib/multiply.h DESTINATION ${PROJECT_SOURCE_DIR}/../install/include)
