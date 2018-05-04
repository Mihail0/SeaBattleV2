#ifndef __DEFS
#define __DEFS
#define _CRT_SECURE_NO_WARNINGS

#include <time.h>
#include <gtest/gtest.h>

#define ui8 unsigned __int8
#define MAPSIZE 10
#define MAXSHIPS 32
#define TESTSHOOTS 30
#define TESTS 128
#define SHIPSNUM 5
#define Random(x) (rand() % static_cast<ui8>(x))
#define cwater	"* "
#define cbomb	"O "
#define cship	"o "
#define ccrash	"X "

enum States {
	water,
	bomb,
	ship,
	crash
};

enum Directions {
	horizontal,
	vertical
};

enum GameStates {
	preparation,
	start,
	outshot,
	agnshot,
	miss,
	success,
	win
};

#endif
