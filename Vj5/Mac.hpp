#ifndef MAC_HPP
#define MAC_HPP

#include <vector>
#include "Karta.hpp"

class Mac {
private:
    std::vector<Karta> karte;

public:
    Mac();

    void promijesaj();
    std::vector<Karta> podijeliKarte(int brojIgraca);
    void otvoriKarteNaStolu();
};

#endif
