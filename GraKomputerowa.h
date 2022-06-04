#ifndef grakomputerowa
#define grakomputerowa
#include "Gra.h"


class GraKomputerowa :  public Gra
{
	string platforma;

public:
	
	void show();

	GraKomputerowa(string title = "brak danych", string author = "brak danych", string genre = "brak danych", string platform = "PC") {
		nazwa = title;
		autor = author;
		gatunek = genre;
		platforma = platform;
	}
};

#endif