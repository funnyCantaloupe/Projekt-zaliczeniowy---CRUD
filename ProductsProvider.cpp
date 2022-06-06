#include "ProductsProvider.h"
#include <algorithm>
#include <iostream>
#include <utility>
#include "Sklep.h"


using namespace std;

void ProductsProvider::addItem(int a, string b, string c) {
	productsList.push_back(Item::Item(a, b, c));
}

void ProductsProvider::removeItem(int id) {

	if (Item::maxID != 0) {
		for (auto& n : productsList) {
			if (id == n.id) {
				delete& n;
				cout << "Usunieto obiekt." << endl;
				Item::maxID = 0;
				return;
			}
		}
		cout << "Nie ma obiektu o takim ID." << endl;	
	}
	else {
		cout << "Baza jest pusta." << endl;
	}
}

void ProductsProvider::updateItem(int ID) {
	int new_price;
	for (auto& n : productsList)
	{
		if (n.id == ID) {
			cout << "Podaj nowa cene: ";
			cin >> new_price;
			n.setPrice(new_price);
			break;
		}
	}
}


bool compareItems(Item i1, Item i2)
{
	return (i1.getPrice() < i2.getPrice());
}

bool compareIDinItems(Item i1, Item i2)
{
	return (i1.getID() < i2.getID());
}


void ProductsProvider::getSortedItems() {

	if (!productsList.empty()) {
		
		for (auto& n : productsList)
		{	
			sort(productsList.begin(), productsList.end(), compareItems);
			cout << "ID: " << n.getID() << endl;
			cout << "Cena: " << n.getPrice() << endl;
			cout << "Kategoria: " << n.getCategory() << endl;
			cout << "Szczegoly: " << n.getDetail() << endl;
			cout << endl;
		}
}
	else {
		cout << "Baza jest pusta." << endl;
	}	
}

void ProductsProvider::getSortedByID() {
	if (productsList.size() > 0) {
		for (auto& n : productsList)
		{
			sort(productsList.begin(), productsList.end(), compareIDinItems);
		}
	}

}
