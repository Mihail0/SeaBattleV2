#ifndef __MAP
#define __MAP

#include "defs.h"
#include "line.h"
#include "ship.h"

class Map {
private:
protected:
	Line* container;
	virtual void explode(const ui8 &, const ui8 &);
	virtual void fireAround(const ui8 &, const ui8 &);
public:
	virtual void fire(const ui8 &, const ui8 &);
	virtual void fire(const ui8 &, const ui8 &, Ship*** &, ui8* &);
	bool operator==(const Map &) const;
	bool operator!=(const Map &) const;
	Line& operator[](const ui8 &);
	Map();
	virtual ~Map();
};

#endif
