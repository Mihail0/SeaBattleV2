#ifndef __SHIPTEST
#define __SHIPTEST

#include "defs.h"
#include "ship.h"

class ShipTest :
	public testing::Test {
private:
protected:
	Ship* ship;
public:
	ShipTest();
	virtual ~ShipTest();
};

TEST_F(ShipTest, ShipCreationTest) {
	ASSERT_TRUE(ship != NULL);
}

#endif
