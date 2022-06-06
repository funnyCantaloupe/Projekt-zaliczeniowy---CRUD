#include "Sklep.h"

using namespace std;

GraKomputerowa* Sklep::create(string title, string author, string genre, string platform) {
    GraKomputerowa* gra = new GraKomputerowa(title, author, genre, platform);
    gry.push_back(gra);
    return gra;
}

GraPlanszowa* Sklep::create(string title, string author, string genre, float weigth) {
    GraPlanszowa* gra = new GraPlanszowa(title, author, genre, weigth);
    gry.push_back(gra);
    return gra;
}

const vector<Gra*>& Sklep::read() const {
    return gry;
}

Gra* Sklep::last_element(Sklep* sklep) {
    return sklep->read().back();
}

void Sklep::remove(int id, ProductsProvider* provider) {

    int liczba_obiektow = 0;

    for (auto& n : provider->productsList)
    {
        liczba_obiektow++;
    }


    gry.erase(gry.begin() + id - liczba_obiektow);

}
