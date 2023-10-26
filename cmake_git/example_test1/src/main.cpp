#include "conversion.hpp"
#include "evolution.hpp"
#include "initial.hpp"
#include "io.hpp"
#include "parser.hpp"

#include <iostream>

// 步骤如下
// 注意，可能需要现在设置里设置CMake Tools的生成器为GinGW Makefiles
// mkdir build
// cd build
// ctrl+shift+p(看左下角有没有GCC)
// cmake ..
// cmake --build .   ---生成可执行文件(路径由cmakelists指定，不知道就在build目录)
// 去到有可执行文件的路径，执行可执行文件.\文件名.exe




// cmake -G "Unix Makefiles" ../


int main(int argc, char *argv[]) {

  // parse arguments
  int length, num_steps, rule_decimal;
  std::tie(length, num_steps, rule_decimal) = parse_arguments(argc, argv);

  // print information about parameters
  std::cout << "length: " << length << std::endl;
  std::cout << "number of steps: " << num_steps << std::endl;
  std::cout << "rule: " << rule_decimal << std::endl;

  // obtain binary representation for the rule
  std::string rule_binary = binary_representation(rule_decimal);

  // create initial distribution
  std::vector<int> row = initial_distribution(length);

  // print initial configuration
  print_row(row);

  // the system evolves, print each step
  for (int step = 0; step < num_steps; step++) {
    row = evolve(row, rule_binary);
    print_row(row);
  }
}
