#include <iostream>
#include <string>
#include "Gra.h"
#include "GraKomputerowa.h"
#include "GraPlanszowa.h"
#include "ListManager.h"
#include "ProductsProvider.h"
#include "Sklep.h"

using namespace std;

int Item::maxID = 0;

int main() {

	Sklep menuSklep;
	ProductsProvider menuProvider;

	cout << "1: Dodaj przedmiot\n2: Usun przedmiot\n3: Wypisz baze przedmiotow\n4: Odczytaj z pliku\n5: Zapisz do pliku\n6: Zakoncz\n";
	char wybor;
	cin >> wybor;

	int typ_przedmiotu;
	string n;
	string a;
	string g;
	string p;
	string k;
	string s;
	int w;
	int c;
	int i;

	do {
		switch (wybor) {
		case '1':
			cout << "\n1: Dodaj gre komputerowa\n2: Dodaj gre planszowa\n3: Dodaj inny przedmiot\n";
			cin >> typ_przedmiotu;
			if (typ_przedmiotu == '1') {

				cout << "Podaj cene: ";
				cin >> c;

				cout << "Podaj nazwe: ";
				cin >> n;
				cout << "Podaj autora: ";
				cin >> a;
				cout << "Podaj gatunek: ";
				cin >> g;
				cout << "Podaj platforme: ";
				cin >> p;

				menuSklep.create(n, a, g, p);
				Sklep* psklep = &menuSklep;
				Gra* pgra = menuSklep.last_element(psklep);
				menuProvider.addItem(c, "gra komputerowa", pgra);
			}
			else if (typ_przedmiotu == '2') {

				cout << "Podaj cene: ";
				cin >> c;

				cout << "Podaj nazwe: ";
				cin >> n;
				cout << "Podaj autora: ";
				cin >> a;
				cout << "Podaj gatunek: ";
				cin >> g;
				cout << "Podaj wage: ";
				cin >> w;

				menuSklep.create(n, a, g, w);
				Sklep* psklep = &menuSklep;
				Gra* pgra = menuSklep.last_element(psklep);
				menuProvider.addItem(c, "gra komputerowa", pgra);

			}
			else if (typ_przedmiotu == 3) {
				cout << "Podaj cene: ";
				cin >> c;
				cout << "Podaj kategorie: ";
				cin >> k;
				cout << "Podaj szczegoly: ";
				cin >> s;

				menuProvider.addItem(c, k, s);
			}
			else {
				cout << "Podaj poprawna cyfre\n";
			}
			break;

		case '2':
			cout << "Podaj ID przedmiotu do usuniecia: ";
			cin >> i;
			menuSklep.remove(i);
			break;

		case '3':

			break;
		}

		cout << "1: Dodaj przedmiot\n2: Usun przedmiot\n3: Wypisz baze przedmiotow\n4: Odczytaj z pliku\n5: Zapisz do pliku\n6: Zakoncz\n";
		cin >> wybor;
	} while (wybor != '6');
	

	return 0;
}