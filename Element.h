#ifndef kolekcje2
#define kolekcje2
#include <iostream>
#include "Gra.h"

using namespace std;


class Element : protected Gra
{
public:
	Element* next = NULL;
	string id;
};

#endif