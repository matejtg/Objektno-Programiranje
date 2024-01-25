#include "VirtualPet.h"
#include "Owner.h"
#include <ctime>
#include <iostream>


VirtualPet::VirtualPet(const std::string& petName, const std::string& petType)
    : name(petName), type(petType), hungerPoints(50), happinessPoints(50), isAwake(true) {}

void VirtualPet::eat() {
    hungerPoints -= 20;
    happinessPoints += 10;
}

void VirtualPet::sleep() {
    if (hungerPoints <= 99) {
        isAwake = false;
        happinessPoints += 20;
        hungerPoints += 20;
    }
    else {
        std::cout << "Pet is not hungry enough to sleep yet." << std::endl;
    }
}

void VirtualPet::play() {
    hungerPoints += 10;
    happinessPoints += 30;
}

void VirtualPet::printPetStatus() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Type: " << type << std::endl;
    std::cout << "Hunger: " << hungerPoints << std::endl;
    std::cout << "Happiness: " << happinessPoints << std::endl;
    std::cout << "Awake: " << (isAwake ? "Yes" : "No") << std::endl;
}

int VirtualPet::getHappiness() const {
    return happinessPoints;
}


bool operator==(const VirtualPet& lhs, const VirtualPet& rhs) { //implementacija operatora usporedbe
    return (
        lhs.name == rhs.name &&
        lhs.type == rhs.type &&
        lhs.hungerPoints == rhs.hungerPoints &&
        lhs.happinessPoints == rhs.happinessPoints &&
        lhs.isAwake == rhs.isAwake
        );
}

bool operator!=(const VirtualPet& lhs, const VirtualPet& rhs) { // operator nejednakosti negacije gornjeg
    return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream& os, const VirtualPet& pet) {  // operator za pridruzivanje
    os << "Name: " << pet.name << std::endl;
    os << "Type: " << pet.type << std::endl;
    os << "Hunger: " << pet.hungerPoints << std::endl;
    os << "Happiness: " << pet.happinessPoints << std::endl;
    os << "Awake: " << (pet.isAwake ? "Yes" : "No") << std::endl;
    return os;
}


VirtualPet& VirtualPet::operator++() {  //prefiksni inkrem
    if (hungerPoints >= 10) {
        hungerPoints -= 10;
    }
    return *this;
}

VirtualPet VirtualPet::operator++(int) { //postfiksni inkrement
    VirtualPet temp = *this;
    ++(*this);
    return temp;
}

//operatori za usporedbu srece:


bool VirtualPet::operator<(const VirtualPet& other) const {
    return happinessPoints < other.happinessPoints;
}

bool VirtualPet::operator>(const VirtualPet& other) const {
    return happinessPoints > other.happinessPoints;
}

bool VirtualPet::operator<=(const VirtualPet& other) const {
    return happinessPoints <= other.happinessPoints;
}

bool VirtualPet::operator>=(const VirtualPet& other) const {
    return happinessPoints >= other.happinessPoints;
}

//operatzor za ispis:
/*
std::ostream& operator<<(std::ostream& os, const VirtualPet& pet) {
    os << "Name: " << pet.name << std::endl;
    os << "Type: " << pet.type << std::endl;
    os << "Hunger: " << pet.hungerPoints << std::endl;
    os << "Happiness: " << pet.happinessPoints << std::endl;
    os << "Awake: " << (pet.isAwake ? "Yes" : "No") << std::endl;
    return os;
}
*/

