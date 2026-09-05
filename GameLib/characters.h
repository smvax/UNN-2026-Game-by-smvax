#pragma once
#include "object.h"

class Character : public Object {
protected:
    int _health;
    int _power;
    bool _isAlive;

public:
    Character(int x = 0, int y = 0,
        std::string color = COLOR_WHITE, char symbol = 'z',
        int power = 0, int health = 100, bool isAlive = true);
    Character(const Character& other);

    virtual void attack(Character& target) = 0;
    virtual int beAttacked(const Character& attacker, int damage) = 0;

    int getHealth() const noexcept {
        return _health;
    }
    int getPower() const noexcept {
        return _power;
    }
    bool getAlive() const noexcept {
        return _isAlive;
    }

    void kill() noexcept {
        _health = 0;
        _isAlive = false; 
    }
    void resurrect() {
        _health = 100;
        _isAlive = true;
    }
};

class Warrior : public Character {
    int _armor;

public:
    Warrior(int x = 0, int y = 0,
        std::string color = COLOR_GREEN, char symbol = 'W',
        int health = 120, int power = 15, int armor = 10, bool isAlive = true);
    Warrior(const Warrior& other);

    int getArmor() const noexcept {
        return _armor;
    }

    void attack(Character& target) override;
    int beAttacked(const Character& attacker, int damage) override;
};

class Archer : public Character {
    int _fireRate;

public:
    Archer(int x = 0, int y = 0,
        std::string color = COLOR_YELLOW, char symbol = 'A',
        int health = 90, int power = 12, int fireRate = 3, bool isAlive = true);
    Archer(const Archer& other);

    int getFireRate() const noexcept {
        return _fireRate;
    }

    void attack(Character& target) override;
    int beAttacked(const Character& attacker, int damage) override;
};

class Wizard : public Character {
    int _degree;   // учёная степень

public:
    Wizard(int x = 0, int y = 0,
        std::string color = COLOR_WHITE, char symbol = 'M',
        int health = 80, int power = 18, int degree = 2, bool isAlive = true);
    Wizard(const Wizard& other);

    int getDegree() const noexcept {
        return _degree;
    }

    void attack(Character& target) override;
    int beAttacked(const Character& attacker, int damage) override;
};