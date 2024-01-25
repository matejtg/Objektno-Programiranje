#include "Igrac.hpp"
#include <iostream>

Igrac::Igrac(const std::string& ime) : ime(ime) {}

std::string Igrac::getIme() const {
    return ime;
}

void Igrac::dodajKarte(const std::vector<Karta>& noveKarte) {
    for (const auto& karta : noveKarte) {
        ruka.push_back(karta);
    }
}

void Igrac::ispisiRuku() const {
    std::cout << "Ruka igraca " << ime << ": ";
    for (const auto& karta : ruka) {
        std::cout << karta.getBroj() << " ";
    }
    std::cout << std::endl;
}
