#ifndef nazwa_plansza
#define nazwa_plansza
#include "Gra.h"


class GraPlanszowa : public Gra
{
	float waga;

public:

	GraPlanszowa(string title = "brak danych", string author = "brak danych", string genre = "brak danych", float weigth = 0.5) : Gra(title, author, genre), waga(weigth) {}
	GraPlanszowa(Gra& gra, float weigth = 0.5) : Gra(gra), waga(weigth) {}

	string getDetails();
};


#endif