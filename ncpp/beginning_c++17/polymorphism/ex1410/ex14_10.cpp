#include "box.hpp"                                 // For the Box class
#include "toughpack.hpp"                           // For the ToughPack class
#include "carton.hpp"                              // For the Carton class

#include <iostream>

int main(void) {
  ToughPack hardcase {20.0, 30.0, 40.0};         // A derived box - same size
  Carton carton {20.0, 30.0, 40.0, "plastic"};   // A different derived box

  Box*pBox {&hardcase};                          // Base pointer - derived address
  std::cout << "hardcase volume is " << pBox->volume() << std::endl;

  pBox = &carton;                                // New derived address
  std::cout << "carton volume is " << pBox->volume() << std::endl;

  return 0;
}
