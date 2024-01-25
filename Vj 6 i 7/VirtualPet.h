#pragma once
#ifndef VIRTUALPET_H
#define VIRTUALPET_H

#include <string>

class VirtualPet {
private:
    std::string name;
    std::string type;
    int hungerPoints;
    int happinessPoints;
    bool isAwake;


public:
    VirtualPet(const std::string& petName, const std::string& petType);

    void eat();
    void sleep();
    void play();

    void printPetStatus() const;
    int getHappiness() const;

    friend bool operator==(const VirtualPet& lhs, const VirtualPet& rhs); //operatori jednakosti i nejednakosti
    friend bool operator!=(const VirtualPet& lhs, const VirtualPet& rhs);

    friend std::ostream& operator<<(std::ostream& os, const VirtualPet& pet); // operator za pridruzivanje

    VirtualPet& operator++();     // inkrement prefiksni ++
    VirtualPet operator++(int);   // inkrement postfiksni ++

    bool operator<(const VirtualPet& other) const;  //operatori za usporedbu srece
    bool operator>(const VirtualPet& other) const; //operatori za usporedbu srece
    bool operator<=(const VirtualPet& other) const; //operatori za usporedbu srece
    bool operator>=(const VirtualPet& other) const; //operatori za usporedbu srece

   // friend std::ostream& operator<<(std::ostream& os, const VirtualPet& pet);//operator za ispis

    void print() const; //funkcija za ispis umjesto operatora jer sam ga vec iskoristio
 };



#endif // VIRTUALPET_H
