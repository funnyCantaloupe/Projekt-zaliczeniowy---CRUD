#ifndef nazwa_sklep
#define nazwa_sklep

#include <iostream>
#include "Gra.h"
#include "GraKomputerowa.h"
#include "GraPlanszowa.h"
#include <vector>

using namespace std;

class Sklep
{

public:

	GraKomputerowa* create(string title, string author, string genre, string platform);

	GraPlanszowa* create(string title, string author, string genre, float weigth);

	const vector<Gra*>& read() const;

	void remove(int id);

	Gra* last_element(Sklep*);

	vector<Gra*> gry;
};

#endif