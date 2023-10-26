# 将main.cpp编译成可执行文件
add_executable(main main.cpp)

# 进入各个内部库子目录
add_subdirectory(evolution)
add_subdirectory(initial)
add_subdirectory(io)
add_subdirectory(parser)

# 逻辑应该是进入到子目录，然后子目录生成库，由下面这个函数连接到main
# 链接外部库和内部库到可执行目标
target_link_libraries(main 
    PRIVATE         #不会传播
        evolution   #内部库
        initial     #内部库
        io          #内部库  
        parser      #内部库
        conversion  #外部库
)