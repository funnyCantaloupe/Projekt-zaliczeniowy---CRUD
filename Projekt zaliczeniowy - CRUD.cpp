#include <iostream>
#include <string>
#include "Gra.h"
#include "GraKomputerowa.h"
#include "GraPlanszowa.h"
#include "ListManager.h"
#include "ProductsProvider.h"

using namespace std;

int Item::maxID = 0;

int main() {

	Gra ck3("Crusader Kings", "Paradox");

	Gra* neuro = new Gra("Neuroshima");

	GraPlanszowa* neuro_board = new GraPlanszowa(*neuro);

	neuro_board->show();

	ListManager* manager = new ListManager;

	manager->pushBack(*neuro);

	manager->showAll();

	ProductsProvider provider;

	provider.addItem(10, "gra", "Dixit");
	provider.addItem(25, "gra", "Nemesis");
	provider.addItem(32, "gra", "Battle Brothers");
	provider.addItem(5, "ksiazka", "Przepis na czlowieka");

	provider.getSortedItems();

	


	return 0;
}