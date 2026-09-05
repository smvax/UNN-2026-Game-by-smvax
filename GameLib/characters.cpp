#include "characters.h"

//ADDED COMMENT FOR A COPY

Character::Character(int x, int y, std::string color, char symbol,
    int power, int health, bool isAlive)
    : Object(x, y, color, symbol), _health(health), _power(power), _isAlive(isAlive) {
}

Character::Character(const Character& other)
    : Object(other), _health(other._health), _power(other._power), _isAlive(other._isAlive) {
}

Warrior::Warrior(int x, int y, std::string color, char symbol,
    int health, int power, int armor, bool isAlive)
    : Character(x, y, color, symbol, power, health, isAlive), _armor(armor) {
}

Warrior::Warrior(const Warrior& other)
    : Character(other), _armor(other._armor) {
}

void Warrior::attack(Character& target) {
    if (!_isAlive) return;
    int damage = _power;
    int reflected = target.beAttacked(*this, damage);
    _health -= reflected;
    if (_health <= 0) kill();
}

int Warrior::beAttacked(const Character& attacker, int damage) {
    if (!_isAlive) return 0;
    if (_armor > 0) {
        _armor -= damage;
        if (_armor < 0) {
            _health += _armor;
            _armor = 0;
        }
    }
    else {
        _health -= damage;
    }
    if (_health > 0) {
        return _health / 5;   // отражённый урон
    }
    else {
        kill();
        return 0;
    }
}

Archer::Archer(int x, int y, std::string color, char symbol,
    int health, int power, int fireRate, bool isAlive)
    : Character(x, y, color, symbol, power, health, isAlive), _fireRate(fireRate) {
}

Archer::Archer(const Archer& other)
    : Character(other), _fireRate(other._fireRate) {
}

void Archer::attack(Character& target) {
    if (!_isAlive) return;
    int damage = _power * _fireRate;
    int reflected = target.beAttacked(*this, damage);
    _health -= reflected;
    if (_health <= 0) kill();
}

int Archer::beAttacked(const Character& attacker, int damage) {
    if (!_isAlive) return 0;
    _health -= damage;
    if (_health > 0) {
        return _health / 10 + _fireRate;
    }
    else {
        kill();
        return 0;
    }
}

Wizard::Wizard(int x, int y, std::string color, char symbol,
    int health, int power, int degree, bool isAlive)
    : Character(x, y, color, symbol, power, health, isAlive), _degree(degree) {
}

Wizard::Wizard(const Wizard& other)
    : Character(other), _degree(other._degree) {
}

void Wizard::attack(Character& target) {
    if (!_isAlive) return;
    int damage = _power + _degree;
    int reflected = target.beAttacked(*this, damage);
    _health -= reflected;
    if (_health <= 0) kill();
}

int Wizard::beAttacked(const Character& attacker, int damage) {
    if (!_isAlive) return 0;
    _health -= damage;
    if (_health > 0) {
        return (_health / 15) * _degree;
    }
    else {
        kill();
        return 0;
    }
}