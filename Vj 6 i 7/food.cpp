#include "Food.h"
#include <iostream>

int Food::availableFood = 4;

void Food::feedPet() {
    if (availableFood > 0) {
        availableFood--; 
        std::cout << "Ljubimac je nahranjen. Raspolozivo porcija hrane: " << availableFood << std::endl;
    }
    else {
        std::cout << "Nema vise hrane za nahraniti ljubimca." << std::endl;
    }
}

int Food::getAvailableFood() {
    return availableFood; 
}

void printAvailableFood() {
    int available = Food::getAvailableFood();
    std::cout << "Raspolozivo porcija hrane: " << available << std::endl;
}