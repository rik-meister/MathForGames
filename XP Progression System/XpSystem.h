#pragma once
#ifndef XpSystem_H
#define XpSystem_H
#include<iostream>
#include<fstream>
#include<string>

using namespace std;


class Character
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
    Character();
    Character(string n, int lvl, int h, int ap, int cXP, int xpToNext);

    // Functions
    bool isAlive();
    int critDamage(int damage);
    void attack(Enemy& target);
    void displayStatus();
    void gainXP(int amount);
};
class Enemy {
public:
    string name;
    int health;
    int attackPower;

    Enemy(string n, int h, int a) : name(n), health(h), attackPower(a) {}

    void takeDamage(int dmg) {
        health -= dmg;
        cout << name << " takes " << dmg << " damage. HP left: " << health << endl;
    }

    void attack() {
        cout << name << " attacks for " << attackPower << " damage!" << endl;
    }

    bool isDefeated() {
        return health <= 0;
    }
};
#endif