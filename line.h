#ifndef __LINE
#define __LINE

#include "defs.h"

class Line {
private:
protected:
	ui8* elements;
public:
	virtual void fire(const ui8 &);
	bool operator==(const Line &) const;
	bool operator!=(const Line &) const;
	ui8& operator[](const ui8 &);
	Line();
	virtual ~Line();
};

#endif
