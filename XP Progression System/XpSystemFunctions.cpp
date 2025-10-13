#include<iostream>
#include<fstream>
#include<string>
#include "XpSystem.h"

using namespace std;

        // Player Class Constructors

Player::Player()
{
    name = "Unkown";
    level = 1;
    health = 100;
    atk = 25;
    attackPower = critDamage(atk);
    currentXP = 0;
    xpToNextLevel = 100;
}
Player::Player(string n, int lvl, int h, int ap, int cXP, int xpToNext)
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
bool Player::isAlive() // Checks if player is alive
{
    return health > 0;
}
int Player::critDamage(int damage) // Crit function for attackPower = critDamge(input damage here)
{
    return (rand() % 30 - 10 + 1) + damage; // Right now it is adding damage, can be changed to multiply later
}
void Player::attack(Enemy target) // Targeting
{
    attackPower = critDamage(atk);
    target.health -= attackPower;
    cout << name << " attacks " << target.name << " for " << attackPower << " damage!" << endl;
}
void Player::displayStatus() // Display health of target
{
    cout << name << " - HP: " << health << endl;
}

        // XP Gain Functions
void Player::gainXP(int amount)
{
    currentXP += amount;
    cout << "Gained " << amount << " XP. Current XP: " << currentXP << endl;

    // Check for level up
    while (currentXP >= xpToNextLevel)
    {
        levelUp();
    }
}
void Player::levelUp()
{
    level++;
    currentXP -= xpToNextLevel; // XP needed for the level
    xpToNextLevel = calculateXPForNextLevel(level); // New XP requirement
    cout << "Leveled up! New level: " << level << ". XP to next level: " << xpToNextLevel << std::endl;
    // Add stats here later
}
long long Player::calculateXPForNextLevel(int currentLevel)
{
    //  Exponential XP increase
    return 100LL * currentLevel * currentLevel;
}


 //Enemy Class Functions

