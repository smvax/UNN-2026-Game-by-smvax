#include "pch.h" 
#include "characters_old.h" 

TEST(CharacterTest, CheckDefaultWarriorConstructor) {
    Warrior wa;
    EXPECT_EQ(wa.getHealth(), 100);
    EXPECT_EQ(wa.getPower(), 20);
    EXPECT_EQ(wa.getArmor(), 10);
}

TEST(CharacterTest, CheckDefaultArcherConstructor) {
    Archer a;
    EXPECT_EQ(a.getHealth(), 100);
    EXPECT_EQ(a.getPower(), 5);
    EXPECT_EQ(a.getFireRate(), 3);
}

TEST(CharacterTest, CheckDefaultWizardConstructor) {
    Wizard wi;
    EXPECT_EQ(wi.getHealth(), 100);
    EXPECT_EQ(wi.getPower(), 5);
    EXPECT_EQ(wi.getDegree(), 1);
}

TEST(CharacterTest, CheckCopyWarriorConstructor) {
    Warrior original(25, 100, 15, true);
    Warrior copy(original);

    EXPECT_EQ(original.getHealth(), 100);
    EXPECT_EQ(original.getPower(), 25);
    EXPECT_EQ(original.getArmor(), 15);
    EXPECT_TRUE(original.getAlive());

    EXPECT_EQ(copy.getHealth(), 100);
    EXPECT_EQ(copy.getPower(), 25);
    EXPECT_EQ(copy.getArmor(), 15);
    EXPECT_TRUE(copy.getAlive());
}

TEST(CharacterTest, CheckCopyArcherConstructor) {
    Archer original(8, 90, 4, true);
    Archer copy(original);

    EXPECT_EQ(original.getHealth(), 90);
    EXPECT_EQ(original.getPower(), 8);
    EXPECT_EQ(original.getFireRate(), 4);

    EXPECT_EQ(copy.getHealth(), 90);
    EXPECT_EQ(copy.getPower(), 8);
    EXPECT_EQ(copy.getFireRate(), 4);
}

TEST(CharacterTest, CheckCopyWizardConstructor) {
    Wizard original(10, 80, 5, true);
    Wizard copy(original);

    EXPECT_EQ(original.getHealth(), 80);
    EXPECT_EQ(original.getPower(), 10);
    EXPECT_EQ(original.getDegree(), 5);

    EXPECT_EQ(copy.getHealth(), 80);
    EXPECT_EQ(copy.getPower(), 10);
    EXPECT_EQ(copy.getDegree(), 5);
}

TEST(CharacterTest, CheckInitCharacterConstructor) {
    Warrior w(25, 120, 15, true);
    EXPECT_EQ(w.getHealth(), 120);
    EXPECT_EQ(w.getPower(), 25);
    EXPECT_EQ(w.getArmor(), 15);

    Archer a(8, 90, 4, true);
    EXPECT_EQ(a.getHealth(), 90);
    EXPECT_EQ(a.getPower(), 8);
    EXPECT_EQ(a.getFireRate(), 4);

    Wizard wi(10, 80, 5, true);
    EXPECT_EQ(wi.getHealth(), 80);
    EXPECT_EQ(wi.getPower(), 10);
    EXPECT_EQ(wi.getDegree(), 5);
}

TEST(CharacterTest, CheckInitWarriorConstructor) {
    Warrior w1(30, 150, 20, true);
    EXPECT_EQ(w1.getHealth(), 150);
    EXPECT_EQ(w1.getPower(), 30);
    EXPECT_EQ(w1.getArmor(), 20);

    Warrior w2(40);
    EXPECT_EQ(w2.getHealth(), 100);
    EXPECT_EQ(w2.getPower(), 40);
    EXPECT_EQ(w2.getArmor(), 10);

    Warrior w3(35, 200);
    EXPECT_EQ(w3.getHealth(), 200);
    EXPECT_EQ(w3.getPower(), 35);
    EXPECT_EQ(w3.getArmor(), 10);

    Warrior w4(45, 180, 25);
    EXPECT_EQ(w4.getHealth(), 180);
    EXPECT_EQ(w4.getPower(), 45);
    EXPECT_EQ(w4.getArmor(), 25);
}

TEST(CharacterTest, CheckInitArcherConstructor) {
    Archer a1(8, 90, 4, true);
    EXPECT_EQ(a1.getHealth(), 90);
    EXPECT_EQ(a1.getPower(), 8);
    EXPECT_EQ(a1.getFireRate(), 4);

    Archer a2(6);
    EXPECT_EQ(a2.getHealth(), 100);
    EXPECT_EQ(a2.getPower(), 6);
    EXPECT_EQ(a2.getFireRate(), 2);

    Archer a3(7, 85);
    EXPECT_EQ(a3.getHealth(), 85);
    EXPECT_EQ(a3.getPower(), 7);
    EXPECT_EQ(a3.getFireRate(), 2);

    Archer a4(9, 95, 5);
    EXPECT_EQ(a4.getHealth(), 95);
    EXPECT_EQ(a4.getPower(), 9);
    EXPECT_EQ(a4.getFireRate(), 5);
}

TEST(CharacterTest, CheckInitWizardConstructor) {
    Wizard w1(10, 80, 5, true);
    EXPECT_EQ(w1.getHealth(), 80);
    EXPECT_EQ(w1.getPower(), 10);
    EXPECT_EQ(w1.getDegree(), 5);

    Wizard w2(12);
    EXPECT_EQ(w2.getHealth(), 100);
    EXPECT_EQ(w2.getPower(), 12);
    EXPECT_EQ(w2.getDegree(), 2);

    Wizard w3(15, 70);
    EXPECT_EQ(w3.getHealth(), 70);
    EXPECT_EQ(w3.getPower(), 15);
    EXPECT_EQ(w3.getDegree(), 2);

    Wizard w4(20, 60, 8);
    EXPECT_EQ(w4.getHealth(), 60);
    EXPECT_EQ(w4.getPower(), 20);
    EXPECT_EQ(w4.getDegree(), 8);
}

TEST(CharacterTest, CheckWarriorAttackWarriorOnce) {
    Warrior attacker(30, 100, 20, true);
    Warrior defender(25, 100, 15, true);

    attacker.attack(defender);

    EXPECT_EQ(defender.getArmor(), 0);
    EXPECT_EQ(defender.getHealth(), 85);

    int reflectedDamage = defender.getHealth() / 5;
    EXPECT_EQ(attacker.getHealth(), 100 - reflectedDamage);
}

TEST(CharacterTest, CheckWarriorAttackArcherOnce) {
    Warrior attacker(30, 100, 20, true);
    Archer defender(5, 100, 3, true);

    attacker.attack(defender);

    EXPECT_EQ(defender.getHealth(), 70);

    int reflectedDamage = defender.getHealth() / 10 + defender.getFireRate();
    EXPECT_EQ(attacker.getHealth(), 100 - reflectedDamage);
}

TEST(CharacterTest, CheckWarriorAttackWizardOnce) {
    Warrior attacker(30, 100, 20, true);
    Wizard defender(10, 100, 2, true);

    attacker.attack(defender);

    EXPECT_EQ(defender.getHealth(), 70);

    int reflectedDamage = (defender.getHealth() / 15) * defender.getDegree();
    EXPECT_EQ(attacker.getHealth(), 100 - reflectedDamage);
}

TEST(CharacterTest, CheckArcherAttackWarriorOnce) {
    Archer attacker(5, 100, 3, true);
    Warrior defender(20, 100, 20, true);

    int damage = attacker.getPower() * attacker.getFireRate();
    attacker.attack(defender);

    EXPECT_EQ(defender.getArmor(), 5);
    EXPECT_EQ(defender.getHealth(), 100);

    int reflectedDamage = defender.getHealth() / 5;
    EXPECT_EQ(attacker.getHealth(), 100 - reflectedDamage);
}

TEST(CharacterTest, CheckArcherAttackArcherOnce) {
    Archer attacker(5, 100, 3, true);
    Archer defender(5, 100, 2, true);

    int damage = attacker.getPower() * attacker.getFireRate();
    attacker.attack(defender);

    EXPECT_EQ(defender.getHealth(), 100 - damage);

    int reflectedDamage = defender.getHealth() / 10 + defender.getFireRate();
    EXPECT_EQ(attacker.getHealth(), 100 - reflectedDamage);
}

TEST(CharacterTest, CheckArcherAttackWizardOnce) {
    Archer attacker(5, 100, 3, true);
    Wizard defender(10, 100, 2, true);

    int damage = attacker.getPower() * attacker.getFireRate();
    attacker.attack(defender);

    EXPECT_EQ(defender.getHealth(), 100 - damage);

    int reflectedDamage = (defender.getHealth() / 15) * defender.getDegree();
    EXPECT_EQ(attacker.getHealth(), 100 - reflectedDamage);
}

TEST(CharacterTest, CheckWizardAttackWarriorOnce) {
    Wizard attacker(10, 100, 3, true);
    Warrior defender(20, 100, 20, true);

    int damage = attacker.getPower() + attacker.getDegree();
    attacker.attack(defender);

    EXPECT_EQ(defender.getArmor(), 7);
    EXPECT_EQ(defender.getHealth(), 100);

    int reflectedDamage = defender.getHealth() / 5;
    EXPECT_EQ(attacker.getHealth(), 100 - reflectedDamage);
}

TEST(CharacterTest, CheckWizardAttackArcherOnce) {
    Wizard attacker(10, 100, 3, true);
    Archer defender(5, 100, 2, true);

    int damage = attacker.getPower() + attacker.getDegree();
    attacker.attack(defender);

    EXPECT_EQ(defender.getHealth(), 100 - damage);

    int reflectedDamage = defender.getHealth() / 10 + defender.getFireRate();
    EXPECT_EQ(attacker.getHealth(), 100 - reflectedDamage);
}

TEST(CharacterTest, CheckWizardAttackWizardOnce) {
    Wizard attacker(10, 100, 3, true);
    Wizard defender(10, 100, 2, true);

    int damage = attacker.getPower() + attacker.getDegree();
    attacker.attack(defender);

    EXPECT_EQ(defender.getHealth(), 100 - damage);

    int reflectedDamage = (defender.getHealth() / 15) * defender.getDegree();
    EXPECT_EQ(attacker.getHealth(), 100 - reflectedDamage);
}

TEST(CharacterTest, CheckWarriorKillWarrior) {
    Warrior strong(50, 200, 30, true);
    Warrior weak(10, 30, 5, true);

    strong.attack(weak);

    EXPECT_EQ(strong.getHealth(), 200);
    EXPECT_EQ(strong.getPower(), 50);
    EXPECT_EQ(strong.getArmor(), 30);
    EXPECT_TRUE(strong.getAlive());

    EXPECT_EQ(weak.getHealth(), 0);
    EXPECT_EQ(weak.getPower(), 10);
    EXPECT_EQ(weak.getArmor(), 0);
    EXPECT_FALSE(weak.getAlive());

    int strongHealthBefore = strong.getHealth();
    int strongArmorBefore = strong.getArmor();

    weak.attack(strong);

    EXPECT_EQ(strong.getHealth(), strongHealthBefore);
    EXPECT_EQ(strong.getPower(), 50);
    EXPECT_EQ(strong.getArmor(), strongArmorBefore);
    EXPECT_TRUE(strong.getAlive());

    EXPECT_EQ(weak.getHealth(), 0);
    EXPECT_EQ(weak.getPower(), 10);
    EXPECT_EQ(weak.getArmor(), 0);
    EXPECT_FALSE(weak.getAlive());
}

TEST(CharacterTest, CheckWarriorKillArcher) {
    Warrior strong(50, 200, 30, true);
    Archer weak(5, 30, 1, true);

    strong.attack(weak);

    EXPECT_EQ(strong.getHealth(), 200);
    EXPECT_EQ(strong.getPower(), 50);
    EXPECT_EQ(strong.getArmor(), 30);
    EXPECT_TRUE(strong.getAlive());

    EXPECT_EQ(weak.getHealth(), 0);
    EXPECT_EQ(weak.getPower(), 5);
    EXPECT_EQ(weak.getFireRate(), 1);
    EXPECT_FALSE(weak.getAlive());

    int strongHealthBefore = strong.getHealth();
    int strongArmorBefore = strong.getArmor();

    weak.attack(strong);

    EXPECT_EQ(strong.getHealth(), strongHealthBefore);
    EXPECT_EQ(strong.getPower(), 50);
    EXPECT_EQ(strong.getArmor(), strongArmorBefore);
    EXPECT_TRUE(strong.getAlive());

    EXPECT_EQ(weak.getHealth(), 0);
    EXPECT_EQ(weak.getPower(), 5);
    EXPECT_EQ(weak.getFireRate(), 1);
    EXPECT_FALSE(weak.getAlive());
}

TEST(CharacterTest, CheckWarriorKillWizard) {
    Warrior strong(50, 200, 30, true);
    Wizard weak(5, 30, 1, true);

    strong.attack(weak);

    EXPECT_EQ(strong.getHealth(), 200);
    EXPECT_EQ(strong.getPower(), 50);
    EXPECT_EQ(strong.getArmor(), 30);
    EXPECT_TRUE(strong.getAlive());

    EXPECT_EQ(weak.getHealth(), 0);
    EXPECT_EQ(weak.getPower(), 5);
    EXPECT_EQ(weak.getDegree(), 1);
    EXPECT_FALSE(weak.getAlive());

    int strongHealthBefore = strong.getHealth();
    int strongArmorBefore = strong.getArmor();

    weak.attack(strong);

    EXPECT_EQ(strong.getHealth(), strongHealthBefore);
    EXPECT_EQ(strong.getPower(), 50);
    EXPECT_EQ(strong.getArmor(), strongArmorBefore);
    EXPECT_TRUE(strong.getAlive());

    EXPECT_EQ(weak.getHealth(), 0);
    EXPECT_EQ(weak.getPower(), 5);
    EXPECT_EQ(weak.getDegree(), 1);
    EXPECT_FALSE(weak.getAlive());
}

TEST(CharacterTest, CheckArcherKillWarrior) {
    Archer strong(30, 200, 5, true);
    Warrior weak(10, 30, 5, true);

    strong.attack(weak);

    int reflectedDamage = 0;
    if (weak.getHealth() > 0) {
        reflectedDamage = weak.getHealth() / 5;
    }

    EXPECT_EQ(strong.getHealth(), 200 - reflectedDamage);
    EXPECT_EQ(strong.getPower(), 30);
    EXPECT_EQ(strong.getFireRate(), 5);
    EXPECT_TRUE(strong.getAlive());

    EXPECT_EQ(weak.getHealth(), 0);
    EXPECT_EQ(weak.getPower(), 10);
    EXPECT_EQ(weak.getArmor(), 0);
    EXPECT_FALSE(weak.getAlive());

    int strongHealthBefore = strong.getHealth();

    weak.attack(strong);

    EXPECT_EQ(strong.getHealth(), strongHealthBefore);
    EXPECT_EQ(strong.getPower(), 30);
    EXPECT_EQ(strong.getFireRate(), 5);
    EXPECT_TRUE(strong.getAlive());

    EXPECT_EQ(weak.getHealth(), 0);
    EXPECT_EQ(weak.getPower(), 10);
    EXPECT_EQ(weak.getArmor(), 0);
    EXPECT_FALSE(weak.getAlive());
}

TEST(CharacterTest, CheckArcherKillArcher) {
    Archer strong(30, 200, 5, true);
    Archer weak(5, 30, 1, true);

    strong.attack(weak);

    EXPECT_EQ(strong.getHealth(), 200);
    EXPECT_EQ(strong.getPower(), 30);
    EXPECT_EQ(strong.getFireRate(), 5);
    EXPECT_TRUE(strong.getAlive());

    EXPECT_EQ(weak.getHealth(), 0);
    EXPECT_EQ(weak.getPower(), 5);
    EXPECT_EQ(weak.getFireRate(), 1);
    EXPECT_FALSE(weak.getAlive());

    int strongHealthBefore = strong.getHealth();

    weak.attack(strong);

    EXPECT_EQ(strong.getHealth(), strongHealthBefore);
    EXPECT_EQ(strong.getPower(), 30);
    EXPECT_EQ(strong.getFireRate(), 5);
    EXPECT_TRUE(strong.getAlive());

    EXPECT_EQ(weak.getHealth(), 0);
    EXPECT_EQ(weak.getPower(), 5);
    EXPECT_EQ(weak.getFireRate(), 1);
    EXPECT_FALSE(weak.getAlive());
}

TEST(CharacterTest, CheckArcherKillWizard) {
    Archer strong(30, 200, 5, true);
    Wizard weak(5, 30, 1, true);

    strong.attack(weak);

    EXPECT_EQ(strong.getHealth(), 200);
    EXPECT_EQ(strong.getPower(), 30);
    EXPECT_EQ(strong.getFireRate(), 5);
    EXPECT_TRUE(strong.getAlive());

    EXPECT_EQ(weak.getHealth(), 0);
    EXPECT_EQ(weak.getPower(), 5);
    EXPECT_EQ(weak.getDegree(), 1);
    EXPECT_FALSE(weak.getAlive());

    int strongHealthBefore = strong.getHealth();

    weak.attack(strong);

    EXPECT_EQ(strong.getHealth(), strongHealthBefore);
    EXPECT_EQ(strong.getPower(), 30);
    EXPECT_EQ(strong.getFireRate(), 5);
    EXPECT_TRUE(strong.getAlive());

    EXPECT_EQ(weak.getHealth(), 0);
    EXPECT_EQ(weak.getPower(), 5);
    EXPECT_EQ(weak.getDegree(), 1);
    EXPECT_FALSE(weak.getAlive());
}

TEST(CharacterTest, CheckWizardKillWarrior) {
    Wizard strong(50, 200, 30, true);
    Warrior weak(10, 30, 5, true);

    strong.attack(weak);

    int reflectedDamage = 0;
    if (weak.getHealth() > 0) {
        reflectedDamage = weak.getHealth() / 5;
    }

    EXPECT_EQ(strong.getHealth(), 200 - reflectedDamage);
    EXPECT_EQ(strong.getPower(), 50);
    EXPECT_EQ(strong.getDegree(), 30);
    EXPECT_TRUE(strong.getAlive());

    EXPECT_EQ(weak.getHealth(), 0);
    EXPECT_EQ(weak.getPower(), 10);
    EXPECT_EQ(weak.getArmor(), 0);
    EXPECT_FALSE(weak.getAlive());

    int strongHealthBefore = strong.getHealth();

    weak.attack(strong);

    EXPECT_EQ(strong.getHealth(), strongHealthBefore);
    EXPECT_EQ(strong.getPower(), 50);
    EXPECT_EQ(strong.getDegree(), 30);
    EXPECT_TRUE(strong.getAlive());

    EXPECT_EQ(weak.getHealth(), 0);
    EXPECT_EQ(weak.getPower(), 10);
    EXPECT_EQ(weak.getArmor(), 0);
    EXPECT_FALSE(weak.getAlive());
}

TEST(CharacterTest, CheckWizardKillArcher) {
    Wizard strong(50, 200, 30, true);
    Archer weak(5, 30, 1, true);

    strong.attack(weak);

    EXPECT_EQ(strong.getHealth(), 200);
    EXPECT_EQ(strong.getPower(), 50);
    EXPECT_EQ(strong.getDegree(), 30);
    EXPECT_TRUE(strong.getAlive());

    EXPECT_EQ(weak.getHealth(), 0);
    EXPECT_EQ(weak.getPower(), 5);
    EXPECT_EQ(weak.getFireRate(), 1);
    EXPECT_FALSE(weak.getAlive());

    int strongHealthBefore = strong.getHealth();

    weak.attack(strong);

    EXPECT_EQ(strong.getHealth(), strongHealthBefore);
    EXPECT_EQ(strong.getPower(), 50);
    EXPECT_EQ(strong.getDegree(), 30);
    EXPECT_TRUE(strong.getAlive());

    EXPECT_EQ(weak.getHealth(), 0);
    EXPECT_EQ(weak.getPower(), 5);
    EXPECT_EQ(weak.getFireRate(), 1);
    EXPECT_FALSE(weak.getAlive());
}

TEST(CharacterTest, CheckWizardKillWizard) {
    Wizard strong(50, 200, 30, true);
    Wizard weak(5, 30, 1, true);

    strong.attack(weak);

    EXPECT_EQ(strong.getHealth(), 200);
    EXPECT_EQ(strong.getPower(), 50);
    EXPECT_EQ(strong.getDegree(), 30);
    EXPECT_TRUE(strong.getAlive());

    EXPECT_EQ(weak.getHealth(), 0);
    EXPECT_EQ(weak.getPower(), 5);
    EXPECT_EQ(weak.getDegree(), 1);
    EXPECT_FALSE(weak.getAlive());

    int strongHealthBefore = strong.getHealth();

    weak.attack(strong);

    EXPECT_EQ(strong.getHealth(), strongHealthBefore);
    EXPECT_EQ(strong.getPower(), 50);
    EXPECT_EQ(strong.getDegree(), 30);
    EXPECT_TRUE(strong.getAlive());

    EXPECT_EQ(weak.getHealth(), 0);
    EXPECT_EQ(weak.getPower(), 5);
    EXPECT_EQ(weak.getDegree(), 1);
    EXPECT_FALSE(weak.getAlive());
}