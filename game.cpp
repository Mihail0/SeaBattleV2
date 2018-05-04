#include "game.h"

Game::Game() {
	map = new Map();
	lengths = new ui8[MAXSHIPS];
	ships = new Ship**[MAXSHIPS];
	shipCreator = new ShipCreator();
	for (ui8 i = 0; i < MAXSHIPS; i++) {
		lengths[i] = 0;
		ships[i] = NULL;
	}
}

Game::~Game() {
	for (ui8 i = 0; i < MAXSHIPS; i++) {
		for (ui8 j = 0; j < lengths[i]; j++) {
			delete ships[i][j];
		}
		delete[] ships[i];
	}
	delete shipCreator;
	delete[] ships;
	delete[] lengths;
	delete map;
}
