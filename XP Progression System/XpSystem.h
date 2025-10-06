#pragma once
#ifndef XpSystem_H
#define XpSystem_H
#include<iostream>
#include<fstream>
#include<string>

using namespace std;


class Player 
{
public:
    string name;
    int level;
    int currentXP;
    int xpToNextLevel;
    int health;
    int attackPower;

    // Constructor
    Player()
    {
        name = "Unkown";
        level = 1;
        health = 100;
        attackPower = 25;
        currentXP = 0;
        xpToNextLevel = 100;
    }
    Player(string n, int lvl, int h, int ap, int cXP, int xpToNext)
    {
        name = n;
        level = lvl;
        health = h;
        attackPower = ap;
        currentXP = cXP;
        xpToNextLevel = xpToNext;
    }
    bool isAlive()
    {
        return health > 0;
    }
    void attack(Player& target)
    {
        target.health -= attackPower;
        cout << name << " attacks " << target.name << " for " << attackPower << " damage!" << endl;
    }
    void displayStatus()
    {
        cout << name << " - HP: " << health << endl;
    }
    void gainXP(int amount)
    {
        currentXP += amount;
        std::cout << "Gained " << amount << " XP. Current XP: " << currentXP << std::endl;

        // Check for level up
        while (currentXP >= xpToNextLevel) 
        {
            levelUp();
        }
    }

private:
    void levelUp() 
    {
        level++;
        currentXP -= xpToNextLevel; // Deduct XP required for the level
        xpToNextLevel = calculateXPForNextLevel(level); // Calculate new XP requirement
        std::cout << "Leveled up! New level: " << level << ". XP to next level: " << xpToNextLevel << std::endl;
        // Add any other level-up logic here (e.g., increase stats)
    }

    long long calculateXPForNextLevel(int currentLevel) 
    {
        // Example: XP required increases exponentially
        return 100LL * currentLevel * currentLevel;
        // You can use a more complex formula based on your game's design
    }
};


#endif