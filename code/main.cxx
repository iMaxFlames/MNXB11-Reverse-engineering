#include <iostream>
#include <string>

auto func1(auto var6, auto argument_1) {
  for (int index{0}; index < argument_1.size(); index++) {
    var6 += argument_1[index];
  }
    return var6;
}

int main(int number_of_arguments, char *arguments[]) {
  if (number_of_arguments == 3) {
    std::string program_name{arguments[0]};
    auto argument_1_first_character{*(arguments[1])};
    auto program_name_length{program_name.size()};
    auto argument_2{std::atoi(arguments[2])};
    auto var6{0};
    std::string argument_1{arguments[1]};
    
    if ((var6 ^ argument_1_first_character * 3) << (program_name_length & 0x1f) == argument_2) {
      std::cout << "Correct!" << std::endl;
    } else {
      std::cout << "Wrong!" << std::endl;
    }
  }
}