#include "main.h"

int main(int argc, char** argv) {
	setlocale(LC_ALL, "");
	srand(time(NULL));
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}