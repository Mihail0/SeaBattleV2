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
	FRIEND_TEST(GameTest, GameLengthsInitTest);
private:
protected:
	Map* map;
	ui8* lengths;
	ui8 attempts;
	ui8 gamestate;
	Ship*** ships;
	ShipCreator* shipCreator;

	virtual void placement();
	virtual void message();
	virtual void print();
public:
	virtual void run();
	Game();
	virtual ~Game();
};

#endif
