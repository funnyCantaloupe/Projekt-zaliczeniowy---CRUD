#ifndef nazwa_item
#define nazwa_item

#include <iostream>
#include "Gra.h"

using namespace std;

class Item
{
	friend class ProductsProvider;
	int id;
	int price;
	string category;
	string detail;

public:
	void setPrice(int cena);
	int getID();
	int getPrice();
	string getCategory();
	string getDetail();
	static int maxID;

	Item(int, string, string);

};

#endif