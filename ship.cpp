#include "ship.h"

ui8 Ship::getX() const {
	return x;
}

ui8 Ship::getY() const {
	return y;
}

ui8 Ship::getCount() const {
	return *count;
}

bool Ship::operator==(const Ship &ship) const {
	if (x != ship.x) return false;
	if (y != ship.y) return false;
	if (*count != *(ship.count)) return false;
	return true;
}

bool Ship::operator!=(const Ship &ship) const {
	return !operator==(ship);
}

Ship::Ship() {
	x = 0;
	y = 0;
	count = NULL;
}

Ship::Ship(const ui8 &X, const ui8 &Y) : Ship() {
	x = X;
	y = Y;
}

Ship::Ship(const ui8 &X, const ui8 &Y, ui8* counter) : Ship(X, Y) {
	count = counter;
}

Ship::~Ship() {
	if (count) {
		(*count)--;
		if (!(*count)) delete count;
	}
}
