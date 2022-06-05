#include "Sklep.h"

using namespace std;

void Sklep::create(string title, string author, string genre, string platform) {
    Gra* gra = new GraKomputerowa(title, author, genre, platform);
    gry.push_back(gra);
    delete gra;
}

void Sklep::create(string title, string author, string genre, float weigth) {
    Gra* gra = new GraPlanszowa(title, author, genre, weigth);
    gry.push_back(gra);
    delete gra;
}

const vector<Gra*>& Sklep::read() const {
    return gry;
}

Gra* Sklep::last_element(Sklep* sklep) {
    return sklep->read().back();
}

void Sklep::remove(int id) {
    gry.erase(gry.begin() + id);
}
