#include <iostream>
#include <string>

auto checksum_function(std::string argument_1) {
  auto checksum{0};
  for (auto element : argument_1) {
    checksum += element;
  }

  return checksum;
}

auto calculate_key(std::string program_name, std::string argument_1, char argument_1_first_character) {
  auto program_name_length{program_name.size()};
  auto checksum{checksum_function(argument_1)};

  return (checksum ^ argument_1_first_character * 3) << (program_name_length & 0x1f);
}

int main(int number_of_arguments, char *arguments[]) {
  if (number_of_arguments == 3) {
    std::string program_name{arguments[0]};
    std::string argument_1{arguments[1]};
    int argument_2{std::atoi(arguments[2])};
    char argument_1_first_character{*(arguments[1])};
    
    
    
    auto key{calculate_key(program_name, argument_1, argument_1_first_character)};
    if (key == argument_2) {
      std::cout << "Correct!" << std::endl;
    } else {
      std::cout << "Wrong!" << std::endl;
    }
  }
}