#include "Owner.h"
#include <algorithm>
#include <random>
#include <chrono>
#include <iostream>

Owner::Owner() {}

Owner::Owner(const Owner& other) : pets(other.pets) {}

Owner::Owner(Owner&& other) noexcept : pets(std::move(other.pets)) {}

void Owner::addPet(const VirtualPet& pet) {
    pets.push_back(pet);
}

void Owner::performActions() {

    unsigned seed = static_cast<unsigned>(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    std::shuffle(pets.begin(), pets.end(), std::default_random_engine(seed));


    for (auto& pet : pets) {
        int action = std::rand() % 3; 
        if (action == 0) {
            pet.eat();
        }
        else if (action == 1) {
            pet.sleep();
        }
        else {
            pet.play();
        }
    }
}


void Owner::printAllPetStatus() const {
    for (const auto& pet : pets) {
        pet.printPetStatus();
        std::cout << std::endl;
    }
}

