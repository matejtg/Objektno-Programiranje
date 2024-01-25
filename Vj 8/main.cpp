#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>

class Enemy {
protected:
    std::string name;
    int health;
    int damage;

public:
    Enemy(const std::string& _name, int _health, int _damage) : name(_name), health(_health), damage(_damage) {
        if (_health < 0 || _damage < 0) {
            throw std::invalid_argument("Health i damage moraju biti pozitivan broj.");
        }
    }

    virtual void attack() const = 0;
    virtual void displayInfo() const = 0;
    virtual ~Enemy() = default;
};

class Boss : public Enemy {
private:
    std::string weapon;

public:
    Boss(const std::string& _name, int _health, int _damage, const std::string& _weapon)
        : Enemy(_name, _health, _damage), weapon(_weapon) {
        if (_weapon.empty()) {
            throw std::invalid_argument("Polje weapon ne moze ostati prazno.");
        }
    }

    void attack() const override {
        std::cout << "Boss attacks with " << weapon << ". Dealing " << damage << " damage!" << std::endl;
    }

    void displayInfo() const override {
        std::cout << "Boss Name: " << name << ", Health: " << health << ", Damage: " << damage << ", Weapon: " << weapon << std::endl;
    }
};

class Monster : public Enemy {
private:
    std::string ability;

public:
    Monster(const std::string& _name, int _health, int _damage, const std::string& _ability)
        : Enemy(_name, _health, _damage), ability(_ability) {
        if (_ability.empty()) {
            throw std::invalid_argument("Polje ability ne smije ostati prazno.");
        }
    }

    void attack() const override {
        std::cout << "Monster attacks using " << ability << ". Dealing " << damage << " damage!" << std::endl;
    }

    void displayInfo() const override {
        std::cout << "Monster Name: " << name << ", Health: " << health << ", Damage: " << damage << ", Ability: " << ability << std::endl;
    }
};

int main() {
    std::vector<std::unique_ptr<Enemy>> enemies;

    try {
        enemies.push_back(std::make_unique<Boss>("Zmaj od sipova", 100, 20, "Orah"));
        enemies.push_back(std::make_unique<Monster>("Yorick", 80, 15, "Lopata"));
        enemies.push_back(std::make_unique<Boss>("Nasus", -10, 30, "Keva"));
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    for (const auto& enemy : enemies) {
        enemy->attack();
        enemy->displayInfo();
        std::cout << std::endl;
    }

    return 0;
}
    