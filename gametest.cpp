#include "gametest.h"

GameTest::GameTest() {
	game = new Game();
}

GameTest::~GameTest() {
	delete game;
}
