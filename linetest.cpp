#include "linetest.h"

LineTest::LineTest() {
	line = new Line();
}

LineTest::~LineTest() {
	delete line;
}
