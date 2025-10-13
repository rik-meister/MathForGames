#pragma once
#ifndef XpSystem_H
#define XpSystem_H
#include<iostream>
#include<fstream>
#include<string>

using namespace std;


class Player
{
private:
    void levelUp();
    long long calculateXPForNextLevel(int currentLevel);

public:
    string name;
    int level;
    int currentXP;
    int xpToNextLevel;
    int health;
    int atk;
    int attackPower;

    // Constructor
    Player();
    Player(string n, int lvl, int h, int ap, int cXP, int xpToNext);

    // Functions
    bool isAlive();
    int critDamage(int damage);
    void attack(Enemy target); 
    void displayStatus();
    void gainXP(int amount);
};



class Enemy
{
public:
    string name;
    int health;
    int atk;
    int attackPower;
    

    Enemy(string n, int h, int a) : name(n), health(h), attackPower(a) {}

    void takeDamage(int dmg)
    {
        health -= dmg;
        cout << name << " takes " << dmg << " damage. HP left: " << health << endl;
    }
    int critDamage(int damage) // Crit function for attackPower = critDamge(input damage here)
    {
        return (rand() % 30 - 10 + 1) + damage; // Right now it is adding damage, can be changed to multiply later
    }
    void attack(Player& Enemy)
    {
        attackPower = critDamage(atk);
        Enemy.health -= attackPower;
        cout << name << " attacks " << Enemy.name << " for " << attackPower << " damage!" << endl;
    }
    bool isAlive() // Checks if enemy is alive
    {
        return health > 0;
    }
    void attack()
    {
        cout << name << " attacks for " << attackPower << " damage!" << endl;
    }

    bool isDefeated()
    {
        return health <= 0;
    }
};
#endif