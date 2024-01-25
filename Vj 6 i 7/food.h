#ifndef FOOD_H
#define FOOD_H

class Food {
private:
    static int availableFood; 

public:
    static void feedPet(); // Smanji broj 
    static int getAvailableFood(); // Dohvati trenutni broj 
};

void printAvailableFood();

#endif // FOOD_H
