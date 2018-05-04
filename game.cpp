#include "game.h"

void Game::placement() {
	for (ui8 i = 0; i < SHIPSNUM; i++) {
		bool success = true;
		do {
			success = true;
			try {
				ui8 l = 5 - i;
				ui8 d = Random(2);
				ui8 x = Random(10);
				ui8 y = Random(10);
				d == horizontal ?
					x = Random(10 - l + 1) :
					y = Random(10 - l + 1) ;
				ships[i] = shipCreator->create(map, d, x, y, l);
			}
			catch (std::bad_alloc& ba) {
				success = false;
			}
		} while (!success);
	}
}

void Game::message() {
	switch (gamestate) {
	case preparation:
		std::cout << "Preparations for the game..." << std::endl;
		break;
	case start:
		std::cout << "The game is on!" << std::endl;
		break;
	case outshot:
		std::cout << "Error: coordinates is outside of the map." << std::endl;
		break;
	case agnshot:
		std::cout << "Error: already shot at this point." << std::endl;
		break;
	case miss:
		std::cout << "You have missed the ship." << std::endl;
		break;
	case success:
		std::cout << "You have hit the ship!" << std::endl;
		break;
	case win:
		std::cout << "Congratulations! You Won!" << std::endl;
		break;
	default:
		break;
	}
}

void Game::print() {
	std::cout << " " << "  ";
	for (ui8 i = 0; i < MAPSIZE; i++) {
		std::cout << (int)i << " ";
	}
	std::cout << std::endl;
	for (ui8 i = 0; i < MAPSIZE; i++) {
		std::cout << " " << (int)i << " ";
		for (ui8 j = 0; j < MAPSIZE; j++) {
			switch ((*map)[i][j]) {
			case water:
				std::cout << cwater;
				break;
			case ship:
				std::cout << cship;
				break;
			case bomb:
				std::cout << cbomb;
				break;
			case crash:
				std::cout << ccrash;
				break;
			default:
				break;
			}
		}
		std::cout << std::endl;
	}
}

Game::Game() {
	gamestate = preparation;
	map = new Map();
	lengths = new ui8[MAXSHIPS];
	ships = new Ship**[MAXSHIPS];
	shipCreator = new ShipCreator();
	for (ui8 i = 0; i < MAXSHIPS; i++) {
		lengths[i] = 0;
		ships[i] = NULL;
	}
	placement();
	gamestate = start;
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
