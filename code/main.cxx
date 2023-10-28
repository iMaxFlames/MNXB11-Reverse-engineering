#include <iostream>
#include <string>

auto genenrate_key(std::string argument_1) {
  auto key{0};
  for (auto element : argument_1) {
    key += element;
  }

  return key;
}

void comparing_key(std::string program_name, std::string argument_1, char argument_1_first_character, int argument_2) {
  auto program_name_length{program_name.size()};
  auto key{genenrate_key(argument_1)};
  
  if ((key ^ argument_1_first_character * 3) << (program_name_length & 0x1f) == argument_2) {
      std::cout << "Correct!" << std::endl;
    } else {
      std::cout << "Wrong!" << std::endl;
    }
}

int main(int number_of_arguments, char *arguments[]) {
  if (number_of_arguments == 3) {
    std::string program_name{arguments[0]};
    char argument_1_first_character{*(arguments[1])};
    std::string argument_1{arguments[1]};
    int argument_2{std::atoi(arguments[2])};

    comparing_key(program_name, argument_1, argument_1_first_character, argument_2);
    
  }
}