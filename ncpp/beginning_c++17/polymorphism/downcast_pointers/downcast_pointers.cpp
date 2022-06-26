#include "box.hpp"
#include "carton.hpp"
#include "cerealpack.hpp"

#include <iostream>
#include <vector>
#include <memory>

#define SEP "--------------"

int main(void) {
	Box *pBox{ new Box(10.0, 20.0, 30.0) };
	pBox->showVolume();

	Carton* pCarton{ static_cast<Carton*>(pBox) };
	pCarton->showVolume();

	CerealPack* pPack{ static_cast<CerealPack*>(pBox) };
	pPack->showVolume();

	delete pBox;

	/* CerealPack *pPack{ new CerealPack };
	pPack->showVolume();

	Carton *pCarton {static_cast<Carton*>(pPack)};
	pCarton->showVolume();

	Box *pBox {static_cast<Box*>(pBox)};
	pBox->showVolume();

	delete pPack; */

	return 0;
}
