#ifndef __SHIPCREATORTEST
#define __SHIPCREATORTEST

#include "defs.h"
#include "ship.h"
#include "shipcreator.h"
#include "map.h"

class ShipCreatorTest :
	public testing::Test {
private:
protected:
	ShipCreator* shipCreator;
public:
	ShipCreatorTest();
	virtual ~ShipCreatorTest();
};

TEST_F(ShipCreatorTest, ShipCreatorCreationTest) {
	ASSERT_TRUE(shipCreator != NULL);
}

TEST_F(ShipCreatorTest, ShipCreatorCreateTest) {
	for (ui8 i = 0; i < 100; i++) {
		ui8 rndLength = Random(20);		//Random length of ship
		ui8 rndX = Random(20);			//Random x-coordinate
		ui8 rndY = Random(20);			//Random y-coordinate
		ui8 rndDirection = Random(2);	//Random direction

		//Initialize actual variables
		Map* actualMap = new Map();

		bool cond = false;
		rndDirection == horizontal ? 
			cond = (rndX + (rndLength - 1) < MAPSIZE) && (rndY < MAPSIZE) : 
			cond = (rndY + (rndLength - 1) < MAPSIZE) && (rndX < MAPSIZE) ;
		if (!(rndLength > 0 && cond)) {
			EXPECT_THROW(shipCreator->create(actualMap, rndDirection, rndX, rndY, rndLength), std::out_of_range);
			delete actualMap;
			continue;
		}

		Ship** actualShips = shipCreator->create(actualMap, rndDirection, rndX, rndY, rndLength);

		//Initialize expected variables
		Map* expectedMap = new Map();
		Ship** expectedShips = new Ship*[rndLength];
		ui8* counter = new ui8();
		*counter = rndLength;
		for (ui8 j = 0; j < rndLength; j++) {
			if (rndDirection == horizontal) {
				expectedShips[j] = new Ship(rndX + j, rndY, counter);
				(*expectedMap)[rndX + j][rndY] = ship;
			}
			else {
				expectedShips[j] = new Ship(rndX, rndY + j, counter);
				(*expectedMap)[rndX][rndY + j] = ship;
			}
		}

		//Comparison
		EXPECT_EQ(*expectedMap, *actualMap);
		for (ui8 j = 0; j < rndLength; j++) {
			EXPECT_EQ((*expectedShips[j]), (*actualShips[j]));
		}

		//Final cleansing
		for (ui8 j = 0; j < rndLength; j++) {
			delete actualShips[j];
			delete expectedShips[j];
		}
		delete[] actualShips;
		delete[] expectedShips;
		delete actualMap;
		delete expectedMap;
	}
}

TEST_F(ShipCreatorTest, ShipCreatorCreate2Test) {
	for (ui8 i = 0; i < 100; i++) {
		Map* map = new Map();
		Ship*** ships = new Ship**[2];
		for (ui8 j = 0; j < 2; j++) {
			ships[j] = NULL;
		}
		ui8 rndLen[2];
		for (ui8 j = 0; j < 2; j++) {
			ui8 rndX = Random(10);
			ui8 rndY = Random(10);
			ui8 rndDir = Random(2);
			rndDir == horizontal ?
				rndLen[j] = 1 + Random(10 - rndX) :
				rndLen[j] = 1 + Random(10 - rndY) ;
			bool error = false;
			for (ui8 k = 0, X = rndX, Y = rndY; (k < rndLen[j]) && !error; k++) {
				ui8 n = 0; if (X) n = X - 1;
				ui8 m = 0; if (Y) m = Y - 1;
				ui8 p = X + 1; if (p > (MAPSIZE - 1)) p = MAPSIZE - 1;
				ui8 q = Y + 1; if (q > (MAPSIZE - 1)) q = MAPSIZE - 1;
				for (ui8 r = n; (r <= p) && !error; r++) {
					for (ui8 s = m; (s <= q) && !error; s++) {
						if ((*map)[r][s] == ship) {
							error = true;
						}
					}
				}
				rndDir == horizontal ? X++ : Y++;
			}
			if (error) {
				EXPECT_THROW(shipCreator->create(map, rndDir, rndX, rndY, rndLen[j]),
					std::bad_alloc);
			}
			else {
				ships[j] = shipCreator->create(map, rndDir, rndX, rndY, rndLen[j]);
			}
		}
		for (ui8 j = 0; j < 2; j++) {
			if (ships[j]) {
				for (ui8 k = 0; k < rndLen[j]; k++) {
					delete ships[j][k];
				}
				delete[] ships[j];
			}
		}
		delete[] ships;
		delete map;
	}
}

#endif
