#include "box.hpp"                                 // For the Box class

#include <iostream>
#include "toughpack.hpp"                           // For the ToughPack class
#include "carton.hpp"                              // For the Carton class

int main(void) {
  Box box {20.0, 30.0, 40.0};
  ToughPack hardcase {20.0, 30.0, 40.0};         // A derived box - same size
  Carton carton {20.0, 30.0, 40.0, "plastic"};   // A different derived box

  std::cout << "box volume: " << box.volume() << std::endl;
  std::cout << "hardcase volume: " << hardcase.volume() << std::endl;
  std::cout << "carton volume: " << carton.volume() << std::endl;

  std::cout << std::endl;

  box.showVolume();                              // Volume of Box
  hardcase.showVolume();                         // Volume of ToughPack
  carton.showVolume();                           // Volume of Carton

  // Now using a base pointer...
  Box* pBox {&box};                              // Points to type Box
  std::cout << "\nbox volume through pBox is " << pBox->volume() << std::endl;
  pBox->showVolume();

  // these calls will be resolved statically, unless you use virtual keyword
  pBox = &hardcase;                              // Points to type ToughPack
  std::cout << "hardcase volume through pBox is " << pBox->volume() << std::endl;
  pBox->showVolume();

  pBox = &carton;                                // Points to type Carton
  std::cout << "carton volume through pBox is " << pBox->volume() << std::endl;
  pBox->showVolume();

  return 0;
}


// to check static resolution (or static binding or early binding), remove
// 'virtual' keyword from Box::volume()
