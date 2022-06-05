#ifndef grakomputerowa
#define grakomputerowa
#include "Gra.h"


class GraKomputerowa :  public Gra
{
	string platforma;

public:
	

	GraKomputerowa(string title = "brak danych", string author = "brak danych", string genre = "brak danych", string platforma = "PC") : Gra(title, author, genre), platforma(platforma) {}
	GraKomputerowa(Gra& gra, string platform = "PC") : Gra(gra), platforma(platform) {}

	string getDetails();
		
};

#endif