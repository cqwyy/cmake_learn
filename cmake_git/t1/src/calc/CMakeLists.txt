# add_library(addition STATIC src/addition.cpp) #库名，静态库，用来生成库的源文件列表
# 推荐下列方式生成
add_library(addition STATIC)
target_sources(addition
PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src/addition.cpp#当前txt文件夹
)

# 添加头文件到可执行文件addition
target_include_directories(addition#对依赖这个库的目标生效，用INTERFACE
INTERFACE#谁依赖了addition，这个目录就会被包含到那个目标里
    ${CMAKE_CURRENT_LIST_DIR}/Inc
)

install(TARGETS addition DESTINATION ${PROJECT_SOURCE_DIR}/../install/lib)#静态库安装到lib
install(FILES Inc/addition.h DESTINATION ${PROJECT_SOURCE_DIR}/../install/include)



# 动态库就STATIC改为SHARED（一般动态库静态库不会放到一个文件夹，不过都一样，在那个动态库目录创txt用对应目录，还有一些包含子目录等等就行）
# add_library(subtract SHARED src/subtract.cpp)
# 推荐用如下方法添加
add_library(subtract SHARED)
target_sources(subtract
PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/src/subtract.cpp#当前txt文件夹
)
target_include_directories(subtract#对依赖这个库的目标生效，用interface
INTERFACE#谁依赖了subtract，这个目录就会被包含到那个目标里
    ${CMAKE_CURRENT_LIST_DIR}/Inc
)

install(TARGETS subtract DESTINATION ${PROJECT_SOURCE_DIR}/../install/bin)#动态库安装带bin，保证和exe同一目录下
install(FILES Inc/subtract.h DESTINATION ${PROJECT_SOURCE_DIR}/../install/include)