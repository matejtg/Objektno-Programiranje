#ifndef IGRAC_HPP
#define IGRAC_HPP

#include <vector>
#include <string>
#include "Karta.hpp"

class Igrac {
private:
    std::string ime;
    std::vector<Karta> ruka;

public:
    Igrac(const std::string& ime);

    std::string getIme() const;
    void dodajKarte(const std::vector<Karta>& noveKarte);
    void ispisiRuku() const;
};

#endif
