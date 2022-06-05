#include "GraPlanszowa.h"

string GraPlanszowa::getDetails() {
	ostringstream z;
	z << waga;
	string d(z.str());
	return nazwa + ", " + autor + ", " + gatunek + ", " + d;
}
