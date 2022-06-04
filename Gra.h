#ifndef gra1
#define gra1
#include <iostream>

using namespace std;

class Gra
{
	friend class ListManager;
protected:
	string nazwa;
	string autor;
	string gatunek;	

public:
	Gra(string title = "brak danych", string author = "brak danych", string genre = "brak danych") {
		nazwa = title;
		autor = author;
		gatunek = genre;
	}

	void show();
	
};

#endif

