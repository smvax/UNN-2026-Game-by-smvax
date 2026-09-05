#include "characters_old.h"

Character::Character() {
	_health = 100;
	_power = 1;
	_isAlive = true;
}

Character::Character(const Character& other) {
	_health = other._health;
	_power = other._power;
	_isAlive = other._isAlive;
}

Character::Character(int power, int health, bool isAlive) {
	_health = health;
	_power = power;
	_isAlive = isAlive;
}

Warrior::Warrior() {
	_health = 100;
	_power = 20;
	_isAlive = true;

	_armor = 10;
}

Warrior::Warrior(const Warrior& other) {
	_health = other._health;
	_power = other._power;
	_isAlive = other._isAlive;

	_armor = other._armor;
}

Warrior::Warrior(int power, int health, int armor, bool isAlive) {
	_health = health;
	_power = power;
	_isAlive = isAlive;

	_armor = armor;
}

Archer::Archer() {
	_health = 100;
	_power = 5;
	_isAlive = true;

	_fireRate = 3;
}

Archer::Archer(const Archer& other) {
	_health = other._health;
	_power = other._power;
	_isAlive = other._isAlive;

	_fireRate = other._fireRate;
}
Archer::Archer(int power, int health, int fireRate, bool isAlive) {
	_health = health;
	_power = power;
	_isAlive = isAlive;

	_fireRate = fireRate;
}

Wizard::Wizard() {
	_health = 100;
	_power = 5;
	_isAlive = true;

	_degree = 1;
}

Wizard::Wizard(const Wizard& other) {
	_health = other._health;
	_power = other._power;
	_isAlive = other._isAlive;

	_degree = other._degree;
}

Wizard::Wizard(int power, int health, int degree, bool isAlive) {
	_health = health;
	_power = power;
	_isAlive = isAlive;

	_degree = degree;
}

void Warrior::attack(Character& other) {
	int damage = _power;

	if (_isAlive) {
		_health -= other.beAttacked(*this, damage);
	}
	if (_health <= 0) {
		kill();
	}
}

void Archer::attack(Character& other) {
	int damage = _power * _fireRate;

	if (_isAlive) {
		_health -= other.beAttacked(*this, damage);
	}
	if (_health <= 0) {
		kill();
	}
}

void Wizard::attack(Character& other) {
	int damage = _power + _degree;

	if (_isAlive) {
		_health -= other.beAttacked(*this, damage);
	}
	if (_health <= 0) {
		kill();
	}
}

//ВОИН атакован
int Warrior::beAttacked(const Character& other, int damage) {
	if (_isAlive) {
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
	}
	if (_health > 0) {
		int reflectedDamage = _health / 5; //пока есть силы защищаться
		return reflectedDamage;
	}
	else {
		kill();
	}
	return 0;
}

//ЛУЧНИК атакован
int Archer::beAttacked(const Character& other, int damage) {
	if (_isAlive) {
		_health -= damage;
	}
	if (_health > 0) {
		int reflectedDamage = _health / 10 + _fireRate; //пока есть силы защищаться
		return reflectedDamage;
	}
	else {
		kill();
	}
	return 0;
}

//МАГ атакован
int Wizard::beAttacked(const Character& other, int damage) {
	if (_isAlive) {
		_health -= damage;
	}
	if (_health > 0) {
		int reflectedDamage = _health / 15 * _degree; //пока есть силы защищаться
		return reflectedDamage;
	}
	else {
		kill();
	}
	return 0;
}