#ifndef __DEFS
#define __DEFS
#define _CRT_SECURE_NO_WARNINGS

#include <time.h>
#include <conio.h>
#include <gtest/gtest.h>

#define ui8 unsigned __int8
#define MAPSIZE 10
#define MAXSHIPS 5
#define TESTSHOOTS 30
#define TESTS 128
#define cwater	"* "
#define cbomb	"O "
#define cship	"* "
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
	destroy,
	win
};

#define Read(x)		do {								\
					scanf("%c", &x);					\
					x -= '0';							\
					} while (!(x >= 0 && x <= 9))

#define Random(x)	(rand() %							\
					static_cast<ui8>(x))

#endif
