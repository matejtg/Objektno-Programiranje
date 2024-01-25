#include "Karta.hpp"

Karta::Karta(int broj, Boja boja) : broj(broj), boja(boja) {}

int Karta::getBroj() const {
    return broj;
}

Boja Karta::getBoja() const {
    return boja;
}
