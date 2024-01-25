#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "Karta.hpp"
#include "Igrac.hpp"

int main() {
    std::vector<Karta> stol;
    std::vector<Igrac> igraci;

    // Dodajemo 52 karte u špil
    std::vector<Karta> spil;
    for (int i = 1; i <= 13; ++i) {
        for (int j = 0; j < 4; ++j) {
            spil.emplace_back(i, static_cast<Boja>(j));
        }
    }

    // Miješamo špil karata
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::random_shuffle(spil.begin(), spil.end());

    // Odabir broja igra?a
    int brojIgraca;
    do {
        std::cout << "Unesite broj igraca (2 ili 4): ";
        std::cin >> brojIgraca;
    } while (brojIgraca != 2 && brojIgraca != 4);

    // Dodjeljujemo po 2 karte svakom igra?u
    for (int i = 0; i < brojIgraca; ++i) {
        std::string ime;
        std::cout << "Unesite ime " << i + 1 << ". igraca: ";
        std::cin >> ime;

        Igrac igrac(ime);
        std::vector<Karta> karteZaIgraca;
        for (int j = 0; j < 2; ++j) {
            karteZaIgraca.push_back(spil.back());
            spil.pop_back();
        }
        igrac.dodajKarte(karteZaIgraca);
        igraci.push_back(igrac);
    }

    // Otvaramo 5 karata na stolu
    for (int i = 0; i < 5; ++i) {
        stol.push_back(spil.back());
        spil.pop_back();
    }

    // Ispisujemo karte na stolu
    std::cout << "\nKarte na stolu: ";
    for (const auto& karta : stol) {
        std::cout << karta.getBroj() << " ";
    }
    std::cout << std::endl;

    // Ispisujemo ruke svakog igra?a
    for (const auto& igrac : igraci) {
        igrac.ispisiRuku();
    }

    return 0;
}
