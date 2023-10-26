#include <cstdlib>
#include <iostream>
#include <string>
std::string say_hello() { return std::string("Hello, CMake world!"); }
int main() {
  std::cout << say_hello() << std::endl;
  return EXIT_SUCCESS;
}
// 补充：在编译之前先走之前ctrl+shift+p的流程
// 或者按照如下步骤：
// 编写代码----编写cmakelists-----
// 生成Make file  注意：第一次需要输入"cmake -G"Unix Makefiles" …/",尤其是电脑装了Visual Studio如果直接"cmake …"会生成VS的工程文件，所以这里需要指定下。
// （已经按照教程在设置里配置了这个了，以后应该就不用了）

// 步骤如下
// 注意，可能需要现在设置里设置CMake Tools的生成器为GinGW Makefiles
// mkdir build
// cd build
// ctrl+shift+p(看左下角有没有GCC)
// cmake ..
// cmake --build .   ---生成可执行文件(路径由cmakelists指定，不指定就在build目录)
// 去到有可执行文件的路径，执行可执行文件.\文件名.exe



// cmake -G "Unix Makefiles" ../