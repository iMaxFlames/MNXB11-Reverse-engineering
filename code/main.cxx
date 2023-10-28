#include <iostream>
#include <string>

auto genenrate_key(auto key, auto argument_1) {
  for (auto element : argument_1) {
    key += element;
  }

  return key;
}

int main(int number_of_arguments, char *arguments[]) {
  if (number_of_arguments == 3) {
    std::string program_name{arguments[0]};
    auto argument_1_first_character{*(arguments[1])};
    auto program_name_length{program_name.size()};
    auto argument_2{std::atoi(arguments[2])};
    auto key{0};
    std::string argument_1{arguments[1]};
    key = genenrate_key(key, argument_1);
    if ((key ^ argument_1_first_character * 3) << (program_name_length & 0x1f) == argument_2) {
      std::cout << "Correct!" << std::endl;
    } else {
      std::cout << "Wrong!" << std::endl;
    }
  }
}