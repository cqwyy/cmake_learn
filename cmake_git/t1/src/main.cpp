#include <iostream>
#include "config.h"
#include "addition.h"
#include "subtract.h"
// 使用自己定义的库的步骤：生成静态库，连接库：添加搜索路径,直接include  .h
#include "multiply.h"
#include "division.h"
// 使用别人的库的步骤:连接库(注意动态库应该和exe同级目录下，可以连接放外部库的地址，然后再复制一份动态库去exe的目录),添加搜索路径，直接导入include .h


using namespace std;

int main(){
    // cd build
    // cmake -G "MinGW Makefiles" ..\src   要是ctrl+shift+p就不用指定了
    // 直接窗口输入错误，因为没有指定MinGW 指定语句报错，则是要删除之前的配置文件在执行该语句

    // cmake --build . 点表示当前目录，所以是在当前目录构建
    // ./Main.exe运行
    cout<<"hello"<<PROJECT_VERSION_MINOR<<endl;
    #ifdef DATE
        cout<<"date"<<DATE<<endl;
    #endif
    cout<<add(1,2)<<endl;
    cout<<sub(10,2)<<endl;
    cout<<mult(2,3)<<endl;
    cout<<divide(3,3)<<endl;
    return 0;
}
// cmake命令（或者说函数）不区分大小写，但是参数以及变量区分大小写。参数用空格或者分号隔开
// 使用   ${变量名}来引用变量--就是解引用变量（使用变量）
// 引号可加可不加，但若字符串中有空格必须加

// 目标文件（target）包括：可执行文件(add_executable),库文件（add_library）
// 命令：即函数
// 变量：以CMAKE_开头的变量名（cmake内置变量）
// 属性：文件/文件夹都有各自的属性

// 命令：
// 1.  cmake_minimum_required(VERSION 3.10)设置cmake最低版本
// 2.  project(项目名 C CXX)   设置项目名，项目名就是整个项目的名字;指定语言为c和C++ project(项目名 VERSION 1.0 LANGUAGES CXX)指定版本以及语言
//注意，项目名会被存在变量PROJECT_NAME以及CMAKE_PROJECT_NAME中。PROJECT_SOURCE_DIR就是源文件的绝对路径，他等价于：项目名_SOURCE_DIR 同理有PROJECT_BINARN_DIR是存二进制文件的文件夹的绝对路径--build
// 也同理，如果定义了版本号，版本号保存在PROJECT_VERSION，主版本号在PROJECT_VETSION_MAJOR,次版本号在PROJECT_VERSION_MINOR。(1.0，1是主，0是次)
// 3.  message("xxx")输出文本信息，也可以比如解引用PROJECT_NAME作为参数（可以用双引号引起来，也可以不用）-------cmake -G "MinGW Makefiles" ..\src即可输出
// 4.  add_executable(生成的可执行文件名 源文件)用指定源文件为项目添加可执行文件 ，在一个项目中必须唯一
// 5.  set(变量名 值)将变量设为指定值 set(CMAKE_CXX_STANDARD 11)  就是设置c++标准为11
// # 设置C++17标准，需要满足标准，不用C++拓展语法
// set(CMAKE_CXX_STANDARD 17)
// set(CMAKE_CXX_STANDARD_REQUIRED ON)
// set(CMAKE_CXX_EXTENSIONS OFF)
// set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/lib)#静态库输出目录--当前目录（根目录）下的lib目录
// set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)#可执行文件输出目录--当前目录（根目录）下的bin目录
// set(CMAKE_LIBRRAY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)#动态库输出目录--当前目录（根目录）下的bin目录
// 6.  option(变量名 "帮助信息" value-给前面变量名赋值为什么-ON--1 OFF--0，默认OFF)
// option的值可以通过命令行设置cmake ..\src -D 变量名=OFF（..\src看是在什么目录下吧，反正是要找到他）
// 7.  configure_file(input output) 将输入文件进行替换并生成输出文件---将cmake的变量让cpp文件能够使用，比如这个项目定义了config.h.in，把版本号定义为
// cpp变量，cmake --build .之后，就在build文件夹下（因为在build文件夹下执行的这个命令）生成输出文件，可以在主程序中include这个文件，直接使用生成的变量
// 还有一种情况是根据是否set进行设置，详情见config.h.in


// 将目录添加到目标的搜索路径下
// 8.include_directories(头文件所在目录-多个用空格分开)指定所有目标的头文件路径（为所有目标添加路径）。---自己要导入自己的头文件，告诉编译器去哪个目录找。
// 目录会被添加到当前文件的INCLUDE_DIRECTORIES 属性中。当前文件的每一个目标文件的 INCLUDE_DIRECTORIES 属性也会添加该目录
// # 目标文件有 INCLUDE_DIRECTORIES 和 INTERFACE_INCLUDE_DIRECTORIES 两个属性

// 9.target_include_directories(目标名 PUBLIC 文件搜索路径)为指定目标添加路径
// # INCLUDE_DIRECTORIES 对内头文件目录（自己用--PRIVATE）
// # INTERFACE_INCLUDE_DIRECTORIES 对外头文件目录（自己不用，给别人用--INTERFACE）PUBILC添加到这两个里面了，一般就用PUBLIC


// 文件安装--把可执行文件，库文件，头文件还有其他文件都安装到一个指定的目录
// install(TARGETS <target> DESTINATION <dir>) 安装目标文件  目标文件名  指定安装到哪个文件夹下(DESTINATION 目录名)
// install(FILES <file> DESTINATION <dir>) 安装普通文件
// install(PROGRAMS <非目标文件的可执行程序> DESTINATION <dir>)	# 非目标可执行文件(如脚本)
// install(DIRECTORY <dir> DESTINATION <dir>)	# 安装目录(文件夹)

// install(TARGETS MathFunctions DESTINATION lib)
// install(FILES MathFunctions.h DESTINATION include)
// install(DIRECTORY doc/ DESTINATION doc) （doc/表示文件夹）
// 先构建吗，然后cmake --install .（ROS2应该是自动安装了）
// .dll.a是MinGW自动生成的，不用管，删掉也可