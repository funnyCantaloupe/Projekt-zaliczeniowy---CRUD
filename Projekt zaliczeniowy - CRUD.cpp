#include <iostream>
#include <string>
#include "Gra.h"
#include "GraKomputerowa.h"
#include "GraPlanszowa.h"
#include "ListManager.h"
#include "ProductsProvider.h"
#include "Sklep.h"
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

int Item::maxID = 0;

int main() {

	fstream plik;

	Sklep* menuSklep = new Sklep;
	ProductsProvider* menuProvider = new ProductsProvider;

	char wybor;

	cout << "1: Dodaj przedmiot\n2: Usun przedmiot\n3: Wypisz baze przedmiotow\n4: Modyfikuj cene po ID\n5: Zapisz do pliku\n6: Odczytaj z pliku\n7: Zakoncz\n";
	cin >> wybor;

	if (wybor == '7')
		exit(0);

	char typ_przedmiotu;
	string n;
	string a;
	string g;
	string p;
	string k = " ";
	string s = " ";
	float w;
	int c;
	int i;
	string wiersz = " ";
	string linia3, linia4 = " ";
	int nr_linii = 1;

	do {
		switch (wybor) {
		case '1':
			cout << "\n1: Dodaj gre komputerowa\n2: Dodaj gre planszowa\n3: Dodaj inny przedmiot\n";
			cin.ignore();
			cin >> typ_przedmiotu;
			if (typ_przedmiotu == '1') {

				cout << "Podaj cene: ";
				cin.ignore();
				cin >> c;

				cout << "Podaj nazwe: ";
				cin.ignore();
				getline(cin, n);
				cout << "Podaj autora: ";
				//	cin.ignore();
				getline(cin, a);
				cout << "Podaj gatunek: ";
				//	cin.ignore();
				getline(cin, g);
				cout << "Podaj platforme: ";
				//	cin.ignore();
				getline(cin, p);


			//	menuSklep->create(n, a, g, p);
				menuProvider->addItem(c, "gra komputerowa", menuSklep->create(n, a, g, p)->getDetails());
			}
			else if (typ_przedmiotu == '2') {

				cout << "Podaj cene: ";
				//	cin.ignore();
				cin >> c;

				cout << "Podaj nazwe: ";
				cin.ignore();
				getline(cin, n);
				cout << "Podaj autora: ";
				//	cin.ignore();
				getline(cin, a);
				cout << "Podaj gatunek: ";
				//	cin.ignore();
				getline(cin, g);
				cout << "Podaj wage: ";
				//	cin.ignore();
				cin >> w;

			//	menuSklep->create(n, a, g, w);
				menuProvider->addItem(c, "gra planszowa", menuSklep->create(n, a, g, w)->getDetails());

			}
			else if (typ_przedmiotu == '3') {
				cout << "Podaj cene: ";
				//		cin.ignore();
				cin >> c;
				cout << "Podaj kategorie: ";
				cin.ignore();
				getline(cin, k);
				cout << "Podaj szczegoly: ";
				//	cin.ignore();
				getline(cin, s);

				menuProvider->addItem(c, k, s);
			}
			else {
				cout << "Niepoprawna cyfra. Wracam do menu.\n";
			}

			break;

		case '2':
			cout << "Podaj ID przedmiotu do usuniecia: ";
			cin >> i;


			for (auto& n : menuProvider->productsList)
			{
				if (n.getID() == i) {
					if (n.getCategory() == "gra planszowa" || n.getCategory() == "gra komputerowa") {
						menuSklep->remove(i, menuProvider);
						break;
					}
				}
					
			}
			menuProvider->removeItem(i);
			
			
			break;

		case '3':
			menuProvider->getSortedItems();
			break;

		case '4':
			//	cin.ignore();
			int id;
			cout << "Podaj id: ";
			cin >> id;
			menuProvider->updateItem(id);
			break;

		case '5':
	
			plik.open("gry.txt", ios::out);

			menuProvider->getSortedByID();

			for (auto& n : menuProvider->productsList)
			{
				plik << n.getID() << endl;
				plik << n.getPrice() << endl;
				plik << n.getCategory() << endl;
				plik << n.getDetail() << endl;
				cout << endl;
			}
			plik.close();
			cout << "Zapisano do pliku." << endl << endl;
			break;

		case '6':

			plik.open("gry.txt", ios::in);
			
			int linia2;

			menuProvider->productsList.clear();

			Item::maxID = 0;

			if (plik.good() == false) {
				cout << "Nie udalo sie otworzyc pliku." << endl;
				break;
			}

			while (getline(plik, wiersz)) {

				switch (nr_linii) {
				case 1: nr_linii++; break;
				case 2: linia2 = stoi(wiersz); nr_linii++; break;
				case 3: linia3 = wiersz; nr_linii++; break;
				case 4: linia4 = wiersz; nr_linii++; break;
				case 5:
					nr_linii = 1;
					menuProvider->addItem(linia2, linia3, linia4);	
					break;
				default: break;
				}
			}

			plik.close();
			break;

		case 7:
			exit(0);

		default:
			cout << "\nWybierz poprawna operacje." << endl << endl;
			break;
		}

			cout << "1: Dodaj przedmiot\n2: Usun przedmiot\n3: Wypisz baze przedmiotow\n4: Modyfikuj cene po ID\n5: Zapisz do pliku\n6: Odczytaj z pliku\n7: Zakoncz\n";
			//	cin.ignore();
			cin >> wybor;

	} while (wybor != '7');

	delete menuSklep;
	delete menuProvider;



	return 0;
}