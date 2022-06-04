#ifndef nazwa_item
#define nazwa_item

#include <iostream>

using namespace std;

class Item
{
	friend class ProductsProvider;
	int id;
	int price;
	string category;
	string detail;
	static int maxID;

public:
	void setPrice(int cena);
	int getID();
	int getPrice();
	string getCategory();
	string getDetail();

	Item(int, string, string);
};

#endif