#ifndef __DEFS
#define __DEFS

#include <time.h>
#include <gtest/gtest.h>

#define ui8 unsigned __int8
#define MAPSIZE 10
#define MAXSHIPS 32
#define TESTSHOOTS 30
#define TESTS 128
#define Random(x) (rand() % static_cast<ui8>(x))

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

#endif
