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
}

TEST_F(GameTest, GameShipCreatorInitTest) {
	ASSERT_TRUE(game->shipCreator != NULL);
}

TEST_F(GameTest, GameShipsInitTest) {
	ASSERT_TRUE(game->ships != NULL);
}

#endif
