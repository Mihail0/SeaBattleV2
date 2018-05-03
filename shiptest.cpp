#include "shiptest.h"

ShipTest::ShipTest() {
	ship = new Ship();
}

ShipTest::~ShipTest() {
	delete ship;
}
