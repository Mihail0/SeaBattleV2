#ifndef __SHIPCREATOR
#define __SHIPCREATOR

#include "defs.h"
#include "ship.h"
#include "map.h"

class ShipCreator {
private:
protected:
public:
	virtual Ship** create(Map* &, const ui8 &, const ui8 &, const ui8 &, const ui8 &);
	ShipCreator();
	virtual ~ShipCreator();
};

#endif
