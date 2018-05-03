#include "line.h"

/**
* Fired at the target cell of line
* @param index - index of the target
* @note index should be less than the mapsize
*/
void Line::fire(const ui8 &index) {
	if (index < MAPSIZE) {
		elements[index] = bomb;
	}
	else {
		throw std::out_of_range ("Array index is out of range");
	}
}

bool Line::operator==(const Line &line) const {
	for (ui8 i = 0; i < MAPSIZE; i++) {
		if (elements[i] != line.elements[i]) return false;
	}
	return true;
}

bool Line::operator!=(const Line &line) const {
	return !operator==(line);
}

ui8& Line::operator[](const ui8 &index) {
	return elements[index];
}

Line::Line() {
	elements = new ui8[MAPSIZE];
	for (ui8 i = 0; i < MAPSIZE; i++) {
		elements[i] = water;
	}
}

Line::~Line() {
	delete[] elements;
}
