#include "Item.h"
#include "Sklep.h"
#include <string>

using namespace std;

void Item::setPrice(int cena) {
	price = cena;
}

int Item::getID() {
	return id;
}

int Item::getPrice() {
	return price;
}

string Item::getCategory() {
	return category;
}

string Item::getDetail() {
	return detail;
}

Item::Item(int PRICE, string CATEGORY, string DETAIL) {
	maxID++;
	id = maxID;
	price = PRICE;
	category = CATEGORY;
	detail = DETAIL + "\n";
}
