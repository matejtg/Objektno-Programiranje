#include "Mac.hpp"
#include <algorithm>
#include <random>
#include "Karta.hpp"

Mac::Mac() {
    for (int i = 1; i <= 13; ++i) {
        for (int j = 0; j < 4; ++j) {
            karte.emplace_back(i, static_cast<Boja>(j));
        }
    }
}

void Mac::promijesaj() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(karte.begin(), karte.end(), g);
}

std::vector<Karta> Mac::podijeliKarte(int brojIgraca) {
    std::vector<Karta> ruka;
    size_t brojKarataPoIgracu = karte.size() / brojIgraca;

    // ... dijeljenje karata

    otvoriKarteNaStolu(karte); // Poziv metode za otvaranje karata na stolu

    return ruka;
}

void Mac::otvoriKarteNaStolu(std::vector<Karta>& karteNaStolu) {
    std::cout << "Karte na stolu: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << karteNaStolu.back().getBroj() << " ";
        karteNaStolu.pop_back();
    }
    std::cout << std::endl;
}