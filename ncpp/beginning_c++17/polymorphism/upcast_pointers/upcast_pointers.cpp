#include "box.hpp"
#include "carton.hpp"
#include "cerealpack.hpp"

#include <iostream>
#include <vector>
#include <memory>

#define SEP "--------------"

int main(void) {
	CerealPack *pPack{ new CerealPack{10.0, 20.0, 30.0, "plastic", "good"} };
	pPack->showVolume();

	Carton *pCarton {static_cast<Carton*>(pPack)};
	pCarton->showVolume();

	Box *pBox {static_cast<Box*>(pBox)};
	pBox->showVolume();

	delete pPack;

	return 0;
}
