#ifndef __GAME
#define __GAME

#include "defs.h"
#include "map.h"
#include "ship.h"
#include "shipcreator.h"

class Game {
	FRIEND_TEST(GameTest, GameCreationTest);
	FRIEND_TEST(GameTest, GameMapInitTest);
	FRIEND_TEST(GameTest, GameShipCreatorInitTest);
	FRIEND_TEST(GameTest, GameShipsInitTest);
private:
protected:
	Map* map;
	Ship** ships;
	ShipCreator* shipCreator;
public:
	Game();
	virtual ~Game();
};

#endif
