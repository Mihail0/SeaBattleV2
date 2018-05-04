#ifndef __GAMETEST
#define __GAMETEST

#include "defs.h"
#include "game.h"

class GameTest :
	public testing::Test {
private:
protected:
	Game* game;
public:
	GameTest();
	virtual ~GameTest();
};

TEST_F(GameTest, GameCreationTest) {
	ASSERT_TRUE(game != NULL);
}

TEST_F(GameTest, GameMapInitTest) {
	ASSERT_TRUE(game->map != NULL);
	for (ui8 i = 0; i < MAPSIZE; i++) {
		for (ui8 j = 0; j < MAPSIZE; j++) {
			EXPECT_TRUE(
				(*game->map)[i][j] == water || 
				(*game->map)[i][j] == ship);
		}
	}
}

TEST_F(GameTest, GameShipCreatorInitTest) {
	ASSERT_TRUE(game->shipCreator != NULL);
}

TEST_F(GameTest, GameShipsInitTest) {
	ASSERT_TRUE(game->ships);
	for (ui8 i = 0; i < SHIPSNUM; i++) {
		ASSERT_TRUE(game->ships[i]);
	}
	for (ui8 i = SHIPSNUM; i < MAXSHIPS; i++) {
		ASSERT_TRUE(!game->ships[i]);
	}
}

TEST_F(GameTest, GameLengthsInitTest) {
	for (ui8 i = 0; i < MAXSHIPS; i++) {
		ASSERT_TRUE(!game->lengths[i]);
	}
}

#endif
