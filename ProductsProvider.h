#ifndef nazwa_provider
#define nazwa_provider

#include <iostream>
#include <vector>
#include "Item.h"

using namespace std;

class ProductsProvider
{
	vector <Item> productsList;	

public:

	void addItem(int a, string b, string c);
	void removeItem(int id);
	void updateItem(int ID);
	void getSortedItems();
	void getGroupedItems();
};

#endif