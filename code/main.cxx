#include <iostream>
#include <string>

int checksum_function(std::string argument_1)
{
  auto checksum{0};
  for (auto element : argument_1)
  {
    checksum += element;
  }

  return checksum;
}

int calculate_key(int checksum, char argument_1_first_character, std::string program_name)
{
  auto program_name_length{program_name.size()};

  return (checksum ^ argument_1_first_character * 3) << (program_name_length & 0x1f);
}

void print_results(int checksum, int key, int argument_2)
{
  std::cout << "Calculated checksum: " << checksum << std::endl;
  std::cout << "Calculated key: " << key << std::endl;
  std::cout << "Expected key: " << argument_2 << std::endl;
}

void print_usage(int number_of_arguments)
{
  if (number_of_arguments < 3)
  {
    std::cout << "Missing arguments! Usage: ./FileName <arg1> <arg2>" << std::endl;
  }
  else
  {
    std::cout << "Too many arguments! Usage: ./FileName <arg1> <arg2>" << std::endl;
  }
}

int main(int number_of_arguments, char *arguments[])
{
  // Check for valid input
  if (number_of_arguments == 3)
  {
    // Extract variables from command line input
    std::string program_name{arguments[0]};
    std::string argument_1{arguments[1]};
    int argument_2{std::atoi(arguments[2])};
    char argument_1_first_character{*(arguments[1])};

    int checksum{checksum_function(argument_1)};
    int key{calculate_key(checksum, argument_1_first_character, program_name)};
    print_results(checksum, key, argument_2);

    if (key == argument_2)
    {
      std::cout << "Correct!" << std::endl;
    }
    else
    {
      std::cout << "Wrong!" << std::endl;
    }
  }
  else
  {
    print_usage(number_of_arguments);
  }
}