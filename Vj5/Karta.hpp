#ifndef KARTA_HPP
#define KARTA_HPP

#include <iostream>

enum class Boja { SRCE, KARO, TREF, PIK };

class Karta {
private:
    int broj;
    Boja boja;

public:
    Karta(int broj, Boja boja);

    int getBroj() const;
    Boja getBoja() const;
};

#endif
