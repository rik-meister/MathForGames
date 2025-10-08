#include<iostream>
#include<fstream>
#include<string>
#include "XpSystem.h"

using namespace std;

        // Player Class Constructors

Character::Character()
{
    name = "Unkown";
    level = 1;
    health = 100;
    atk = 25;
    attackPower = critDamage(atk);
    currentXP = 0;
    xpToNextLevel = 100;
}
Character::Character(string n, int lvl, int h, int ap, int cXP, int xpToNext)
{
    name = n;
    level = lvl;
    health = h;
    atk = ap;
    attackPower = critDamage(atk);
    currentXP = cXP;
    xpToNextLevel = xpToNext;
}


        // Player Class Functions
//Turn base combat
bool Character::isAlive() // Checks if player is alive
{
    return health > 0;
}
int Character::critDamage(int damage) // Crit function for attackPower = critDamge(input damage here)
{
    return (rand() % 30 - 10 + 1) + damage; // Right now it is adding damage, can be changed to multiply later
}
void Character::attack(Enemy& Character) // Targeting
{
    attackPower = critDamage(atk);
    Character.health -= attackPower;
    cout << name << " attacks " << Character.name << " for " << attackPower << " damage!" << endl;
}
void Character::displayStatus() // Display health of target
{
    cout << name << " - HP: " << health << endl;
}

        // XP Gain Functions
void Character::gainXP(int amount)
{
    currentXP += amount;
    std::cout << "Gained " << amount << " XP. Current XP: " << currentXP << std::endl;

    // Check for level up
    while (currentXP >= xpToNextLevel)
    {
        levelUp();
    }
}
void Character::levelUp()
{
    level++;
    currentXP -= xpToNextLevel; // XP needed for the level
    xpToNextLevel = calculateXPForNextLevel(level); // New XP requirement
    std::cout << "Leveled up! New level: " << level << ". XP to next level: " << xpToNextLevel << std::endl;
    // Add stats here later
}
long long Character::calculateXPForNextLevel(int currentLevel)
{
    //  Exponential XP increase
    return 100LL * currentLevel * currentLevel;
}

        //Enemy Class Constructors
//Enemy::Enemy()
//{
//    name = "Unkown";
//    level = 1;
//    health = 100;
//    atk = 25;
//    attackPower = critDamage(atk);
//}
//Enemy::Enemy(string n, int lvl, int h, int ap)
//{
//    name = n;
//    level = lvl;
//    health = h;
//    atk = ap;
//    attackPower = critDamage(atk);
//}

// Enemy Class Functions

//bool Enemy::isAlive() // Checks if enemy is alive
//{
//    return health > 0;
//}
//int Enemy::critDamage(int damage) // Crit function for attackPower = critDamge(input damage here)
//{
//    return (rand() % 30 - 10 + 1) + damage; // Right now it is adding damage, can be changed to multiply later
//}
//void Enemy::attack(Player& target) // Targeting Player Class
//{
//    attackPower = critDamage(atk);
//    target.health -= attackPower;
//    cout << name << " attacks " << target.name << " for " << attackPower << " damage!" << endl;
//}
//void Enemy::displayStatus() // Display health of Enemy
//{
//    cout << name << " - HP: " << health << endl;
//}
//int Enemy::levelRand(int lvl)
//{
//    return (rand() % 10 - 1 + 1) + lvl;
//}