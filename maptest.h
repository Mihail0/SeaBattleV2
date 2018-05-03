#ifndef __MAPTEST
#define __MAPTEST

#include "defs.h"
#include "ship.h"
#include "map.h"
#include "shipcreator.h"

class MapTest :
	public testing::Test {
private:
protected:
	Map* map;
public:
	MapTest();
	virtual ~MapTest();
};

TEST_F(MapTest, MapCreationTest) {
	ASSERT_TRUE(map != NULL);
}

TEST_F(MapTest, MapInitializationTest) {
	ui8 expected = water;
	for (ui8 i = 0; i < MAPSIZE; i++) {
		for (ui8 j = 0; j < MAPSIZE; j++) {
			ASSERT_EQ(expected, (*map)[i][j]);
		}
	}
}

TEST_F(MapTest, MapFireAtX0Test) {
	ui8 expected = bomb;
	for (ui8 i = 0; i < 100; i++) {
		ui8 rnd = Random(100);
		if (rnd > 9) {
			EXPECT_THROW(map->fire(rnd, 0), std::out_of_range);
		}
		else {
			map->fire(rnd, 0);
			EXPECT_EQ(expected, (*map)[rnd][0]);
		}
	}
}

TEST_F(MapTest, MapFireAtXYTest) {
	ui8 expected = bomb;
	for (ui8 i = 0; i < 100; i++) {
		ui8 rndX = Random(100);
		ui8 rndY = Random(100);
		if (rndX > 9 || rndY > 9) {
			EXPECT_THROW(map->fire(rndX, rndY), std::out_of_range);
		}
		else {
			map->fire(rndX, rndY);
			EXPECT_EQ(expected, (*map)[rndX][rndY]);
		}
	}
}

TEST_F(MapTest, MapFireAtMapTest) {
	for (ui8 i = 0; i < 100; i++) {
		Map* expectMap = new Map();
		Map* actualMap = new Map();
		EXPECT_EQ(*expectMap, *actualMap);
		ui8 rndX = Random(10);
		ui8 rndY = Random(10);
		(*expectMap)[rndX][rndY] = bomb;
		actualMap->fire(rndX, rndY);
		EXPECT_EQ(*expectMap, *actualMap);
		delete actualMap;
		delete expectMap;
	}
}

TEST_F(MapTest, MapFireAtShipTest) {
	for (ui8 i = 0; i < 100; i++) {
		Map* expectMap = new Map();
		Map* actualMap = new Map();
		Ship*** expectShips = new Ship**[MAXSHIPS];
		Ship*** actualShips = new Ship**[MAXSHIPS];
		ui8* lengths = new ui8[MAXSHIPS];
		for (ui8 j = 0; j < MAXSHIPS; j++) {
			expectShips[j] = NULL;
			actualShips[j] = NULL;
			lengths[j] = 0;
		}

		//Initialization
		//Fire coordinates
		ui8* fireX = new ui8[TESTSHOOTS];
		ui8* fireY = new ui8[TESTSHOOTS];
		for (ui8 j = 0; j < TESTSHOOTS; j++) {
			fireX[j] = Random(10);
			fireY[j] = Random(10);
		}

		//Ship coordinates
		ui8 shipX = Random(10);
		ui8 shipY = Random(10);
		ui8 shipD = Random(2);
		shipD == horizontal ?
			lengths[0] = 1 + Random(10 - shipX) :
			lengths[0] = 1 + Random(10 - shipY);

		//Expected
		for (ui8 j = 0; j < TESTSHOOTS; j++) {
			(*expectMap)[fireX[j]][fireY[j]] = bomb;
		}
		ui8 counter = lengths[0];
		ui8* c = new ui8(); *c = lengths[0];
		expectShips[0] = new Ship*[lengths[0]];
		for (ui8 k = 0, X = shipX, Y = shipY; k < lengths[0]; k++) {
			expectShips[0][k] = new Ship(X, Y, c);
			bool cond = false;
			for (ui8 j = 0; j < TESTSHOOTS; j++) {
				if (X == fireX[j] && Y == fireY[j]) {
					cond = true;
					break;
				}
			}
			if (!cond) {
				//Didn't hit
				(*expectMap)[X][Y] = ship;
			}
			else {
				//Hit
				counter--;
				(*expectMap)[X][Y] = crash;
				delete expectShips[0][k];
				expectShips[0][k] = NULL;
			}
			shipD == horizontal ? X++ : Y++;
		}
		if (!counter) {
			for (ui8 x = 0; x < MAPSIZE; x++) {
				for (ui8 y = 0; y < MAPSIZE; y++) {
					if ((*expectMap)[x][y] == crash) {
						ui8 n = 0; if (x) n = x - 1;
						ui8 m = 0; if (y) m = y - 1;
						ui8 p = x + 1; if (p > (MAPSIZE - 1)) p = MAPSIZE - 1;
						ui8 q = y + 1; if (q > (MAPSIZE - 1)) q = MAPSIZE - 1;
						for (ui8 r = n; r <= p; r++) {
							for (ui8 s = m; s <= q; s++) {
								if ((*expectMap)[r][s] == water) {
									(*expectMap)[r][s] = bomb;
								}
							}
						}
					}
				}
			}
		}

		//Actual
		ShipCreator* shipCreator = new ShipCreator();
		actualShips[0] = shipCreator->create(actualMap, shipD, shipX, shipY, lengths[0]);
		for (ui8 j = 0; j < TESTSHOOTS; j++) {
			actualMap->fire(fireX[j], fireY[j], actualShips, lengths);
		}

		//Comparison
		EXPECT_EQ((*expectMap), (*actualMap));
		for (ui8 j = 0; j < MAXSHIPS; j++) {
			for (ui8 k = 0; k < lengths[j]; k++) {
				if (!expectShips[j][k]) EXPECT_TRUE(!actualShips[j][k]);
				else EXPECT_EQ((*expectShips[j][k]), (*actualShips[j][k]));
			}
		}

		//Cleansing
		delete shipCreator;
		delete[] fireX;
		delete[] fireY;
		for (ui8 j = 0; j < MAXSHIPS; j++) {
			for (ui8 k = 0; k < lengths[j]; k++) {
				delete actualShips[j][k];
				delete expectShips[j][k];
			}
			delete[] actualShips[j];
			delete[] expectShips[j];
		}
		delete[] lengths;
		delete[] actualShips;
		delete[] expectShips;
		delete actualMap;
		delete expectMap;
	}
}

#endif
