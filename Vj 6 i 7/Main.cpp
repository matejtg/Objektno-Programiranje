#include <iostream>
#include "Owner.h"
#include "VirtualPet.h"
#include "Food.h"


int main() {
    Owner anteOwner;
    Owner jureOwner;
    Owner matejOwner;
    Owner moveoriginalOwner;
 

    VirtualPet movePet("Fenix", "Ptica");
    VirtualPet antePet("Garo", "Pas");
    VirtualPet jurePet("Macak", "Macka");
    VirtualPet matejPet1("Tom", "Pas");
    VirtualPet matejPet2("Rex", "Papiga");
    VirtualPet dugiPet("Dugi", "Pas");

    anteOwner.addPet(dugiPet);
    anteOwner.addPet(antePet);
    jureOwner.addPet(jurePet);
    matejOwner.addPet(matejPet1);
    matejOwner.addPet(matejPet2);
    moveoriginalOwner.addPet(movePet);

    antePet.play();
    jurePet.eat();
    matejPet1.sleep();
    matejPet2.play();
    matejPet2.sleep();
    

    Owner moveprobaOwner= std::move(moveoriginalOwner);
    std::cout << "Provjera move konstruktora:" << std::endl;
    moveprobaOwner.printAllPetStatus();

    const std::vector<VirtualPet>& antePets = anteOwner.getPets();
    if (!antePets.empty()) {
        const VirtualPet& antinPet = antePets[0]; 
        Owner ivanOwner = anteOwner; 
        ivanOwner.addPet(antinPet); 
        std::cout << "Ivanov Ljubimac:" << std::endl;
        ivanOwner.printAllPetStatus();
    }

    std::cout << "\nAntin ljubimac\n" << std::endl;
    antePet.printPetStatus();
    std::cout << "\nJurin ljubimac\n" << std::endl;
    jurePet.printPetStatus();
    std::cout << "\nMatejov ljubimac\n" << std::endl;
    matejPet1.printPetStatus();
    std::cout << "\nMatejov ljubimac\n" << std::endl;
    matejPet2.printPetStatus();

    int GaroHappiness = antePet.getHappiness();
    int MacakHappiness = jurePet.getHappiness();
    int TomHappiness = matejPet1.getHappiness();
    int RexHappiness = matejPet2.getHappiness();

    int maxHappiness = GaroHappiness;

    if (MacakHappiness > maxHappiness) {
        maxHappiness = MacakHappiness;
    }

    if (TomHappiness > maxHappiness) {
        maxHappiness = TomHappiness;
    }

    if (RexHappiness > maxHappiness) {
        maxHappiness = RexHappiness;
    }

    VirtualPet* happiestPet = nullptr;

    if (maxHappiness == GaroHappiness) {
        happiestPet = &antePet;
    }
    else if (maxHappiness == MacakHappiness) {
        happiestPet = &jurePet;
    }
    else if (maxHappiness == TomHappiness) {
        happiestPet = &matejPet1;
    }
    else if (maxHappiness == RexHappiness) {
        happiestPet = &matejPet2;
    }

    if (happiestPet != nullptr) {
        std::cout << "\nNajsretniji ljubimac:\n";
        happiestPet->printPetStatus();
    }
    else {
        std::cout << "Nema ljubimaca.\n";
    }
    
    std::cout << "\n\n\nTrenutno stanje hrane(Non member funkcija):\n\n";
    printAvailableFood();

    std::cout << "\n\n\nHranjenje ljubimca Dugi:\n\n";
    Food::feedPet();
    dugiPet.eat();
    dugiPet.printPetStatus();

    std::cout << "\n\n\nHranjenje ljubimca Dugi:\n\n";
    Food::feedPet();
    dugiPet.eat();
    dugiPet.printPetStatus();
 
    //test za operatore jednakosti
    
    if (jurePet == matejPet2) {
        std::cout << "\nLjubimci Macak i Rex su jednaki." << std::endl;
    }
    else {
        std::cout << "\nLjubimci Macak i Rex su razliciti." << std::endl;
    }

    //test za operator pridruzivanja

    VirtualPet pet1("Dugi", "Zmija");
    VirtualPet pet2("Drogon", "Zmaj");

    std::cout << "\n\n\nLjubimac Dugi prije primjene operatora pridruzivanja: " << std::endl;
    std::cout << pet1 << std::endl;

    std::cout << "\n\n\nLjubimac Drogon prije primjene operatora pridruzivanja: " << std::endl;
    std::cout << pet2 << std::endl;

    pet1 = pet2;

    std::cout << "\n\n\nLjubimac Dugi nakon primjene operatora pridruzivanja: " << std::endl;
    std::cout << pet1 << std::endl;

    //prefiksni postfiksni inkrement test

    VirtualPet petInkrement("Rex", "Pas");

    std::cout << "Podaci o pet1 prije hranjenja: " << std::endl;
    std::cout << petInkrement << std::endl;
    petInkrement.eat();


    ++pet1; // Inkrementiranje broja porcija i smanjenje glad
    std::cout << "Podaci o pet1 nakon hranjenja: " << std::endl;
    std::cout << petInkrement << std::endl;
 
  //test operatora za relaciju srece:
 

    if (antePet < dugiPet) {
        std::cout << "Garo je manje sretan od Dugog." << std::endl;
    }
    else {
        std::cout << "Garo nije manje sretan od Dugog." << std::endl;
    }



    //test operatora za ispis:
    /*
    std::cout << "\n\n\nPodaci o Gari:" << std::endl;
    std::cout << antePet << std::endl;

    std::cout << "\n\n\nPodaci o Dugom:" << std::endl;
    std::cout << dugiPet << std::endl;
    */
    

    return 0;
}
