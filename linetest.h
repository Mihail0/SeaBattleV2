#ifndef __LINETEST
#define __LINETEST

#include "defs.h"
#include "line.h"

class LineTest :
	public testing::Test {
private:
protected:
	Line* line;
public:
	LineTest();
	virtual ~LineTest();
};

TEST_F(LineTest, LineCreationTest) {
	ASSERT_TRUE(line != NULL);
}

TEST_F(LineTest, LineInitializationTest) {
	ui8 expected = water;
	for (ui8 i = 0; i < MAPSIZE; i++) {
		ASSERT_EQ(expected, (*line)[i]);
	}
}

TEST_F(LineTest, LineFireAtXTest) {
	ui8 expected = bomb;
	for (ui8 i = 0; i < 100; i++) {
		ui8 rnd = Random(100);
		if (rnd > 9) {
			EXPECT_THROW(line->fire(rnd), std::out_of_range);
		}
		else {
			line->fire(rnd);
			EXPECT_EQ(expected, (*line)[rnd]);
		}
	}
}

#endif
