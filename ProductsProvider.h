#ifndef nazwa_provider
#define nazwa_provider

#include <iostream>
#include <vector>
#include "Item.h"
#include "Gra.h"
#include "Sklep.h"

using namespace std;

class ProductsProvider
{
public:

	void addItem(int a, string b, string c);
	void removeItem(int id);
	void updateItem(int ID);
	void getSortedItems();
	void getSortedByID();
	vector <Item> productsList;
};

#endif