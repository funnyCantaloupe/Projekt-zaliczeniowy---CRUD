#include "ProductsProvider.h"
#include <algorithm>
#include <map>

using namespace std;

void ProductsProvider::addItem(int a, string b, string c) {
	productsList.push_back(Item::Item(a, b, c));
}

void ProductsProvider::removeItem(int id) {
	productsList.erase(productsList.begin() + id);
}

void ProductsProvider::updateItem(int ID) {
	for (auto& n : productsList)
	{
		if (n.id == ID) {
			int new_price;
			cout << "Podaj nowa cene: " << endl;
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

void ProductsProvider::getSortedItems() {

	for (auto& n : productsList)
	{
		sort(productsList.begin(), productsList.end(), compareItems);
		cout << "ID: " << n.id << endl;
		cout << "Cena: " << n.price << endl;
		cout << "Kategoria: " << n.category << endl;
		cout << "Detale: " << n.detail << endl;
	}

}

void ProductsProvider::getGroupedItems() {

}