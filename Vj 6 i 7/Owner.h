#pragma once
#ifndef OWNER_H
#define OWNER_H

#include <vector>
#include "VirtualPet.h"
#include "Food.h"

class Owner {
private:
    std::vector<VirtualPet> pets;

public:
    Owner();
    Owner(const Owner& other); // Konstr kop
    Owner(Owner&& other) noexcept; // Move konstr

    void addPet(const VirtualPet& pet);
    void performActions();


    void printAllPetStatus() const;
    const std::vector<VirtualPet>& getPets() const {
        return pets;
    }
};

#endif // OWNER_H
