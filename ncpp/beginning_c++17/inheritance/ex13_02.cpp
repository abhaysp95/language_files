#include "carton.hpp"

#include <iostream>

int main(void) {
  // Create four Carton objects
  Carton carton1;                             std::cout << std::endl;
  Carton carton2 {"Thin cardboard"};          std::cout << std::endl;
  Carton carton3 {4.0, 5.0, 6.0, "Plastic"};  std::cout << std::endl;
  Carton carton4 {2.0, "paper"};              std::cout << std::endl;

  std::cout << "carton1 volume is " << carton1.volume() << std::endl;
  std::cout << "carton2 volume is " << carton2.volume() << std::endl;
  std::cout << "carton3 volume is " << carton3.volume() << std::endl;
  std::cout << "carton4 volume is " << carton4.volume() << std::endl;

  return 0;
}
