#pragma once

class Character {
protected:
	int _health;
	int _power;
	bool _isAlive;

public:
	Character();
	Character(const Character&);
	Character(int power, int health = 100, bool isAlive = true);

	virtual void attack(Character&) = 0;
	virtual int beAttacked(const Character&, int) = 0;

	inline int getHealth() const noexcept {
		return _health;
	}
	inline int getPower() const noexcept {
		return _power;
	}
	inline bool getAlive() const noexcept {
		return _isAlive;
	}

	inline void kill() noexcept {
		_health = 0;
		_isAlive = false;
	}
	inline void resurrect() {
		_health = 100;
		_isAlive = true;
	}
};

class Warrior : public Character {
	int _armor;

public:
	Warrior();
	Warrior(const Warrior& other);
	Warrior(int power, int health = 100, int armor = 10, bool isAlive = true);

	inline int getArmor() const noexcept {
		return _armor;
	};

	void attack(Character&) override;
	int beAttacked(const Character&, int) override;
};

class Archer : public Character {
	int _fireRate;

public:
	Archer();
	Archer(const Archer& other);
	Archer(int power, int health = 100, int fireRate = 2, bool isAlive = true);

	inline int getFireRate() const noexcept {
		return _fireRate;
	};

	void attack(Character&) override;
	int beAttacked(const Character&, int) override;
};

class Wizard : public Character {
	int _degree; //учёная степень :)

public:
	Wizard();
	Wizard(const Wizard& other);
	Wizard(int power, int health = 100, int fireRate = 2, bool isAlive = true);

	inline int getDegree() const noexcept {
		return _degree;
	};

	void attack(Character&) override;
	int beAttacked(const Character&, int) override;
};

