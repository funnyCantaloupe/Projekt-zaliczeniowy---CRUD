#ifndef nazwa_plansza
#define nazwa_plansza
#include "Gra.h"


class GraPlanszowa : public Gra
{
	float waga;

public:

	GraPlanszowa(Gra& game, float weigth = 0.5) : Gra(game), waga(weigth) {}
	GraPlanszowa(string title = "brak danych", string author = "brak danych", string genre = "brak danych", float weigth = 0.5) : Gra(title, author, genre), waga(weigth) {}

	void show();
};


#endif