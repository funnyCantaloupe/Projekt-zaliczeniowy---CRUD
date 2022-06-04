#ifndef kolekcje
#define kolekcje

#include <iostream>
#include "Element.h"

using namespace std;


class ListManager
{
	Element* head = NULL;

public:
	void pushBack(Gra gra) {
		Element* N = new Element;
		N->id = gra.nazwa;
		N->next = NULL;
		Element* P = head;
		if (P == NULL)
			head = N;
		else {
			while (P->next != NULL) {
				P = P->next;
			}
			P->next = N;
		}

	}

	void popBack() {
		Element* P = head;
		if (P == NULL)
			return;
		else if (P->next == NULL) {
			delete P;
			head = NULL;
			return;
		}
		else {
			while (P->next->next != NULL) {
				P = P->next;
			}
			delete P->next;
			P->next = NULL;
		}
	}

	void showAll() {
		Element* P = head;
		while (P != NULL) {
			cout << P->id << endl;
			P = P->next;
		}
	}
};

#endif