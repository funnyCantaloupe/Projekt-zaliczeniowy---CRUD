#include "GraPlanszowa.h"

string GraPlanszowa::getDetails() {
	ostringstream z;
	z << waga;
	string d(z.str());
	return "nazwa: " + nazwa + ", autor: " + autor + ", gatunek: " + gatunek + ", waga: " + d;
}
