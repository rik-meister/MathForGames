#pragma once
#ifndef XpSystem_H
#define XpSystem_H
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Player;
class Enemy;

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
    void attack(Enemy& target); 
    void displayStatus();
    void gainXP(int amount);
};

class Enemy
{
public:
    string name;
    int health;
    int attackPower;
    int atk;
    int level;
    
    Enemy(string n, int lvl, int h, int a) : name(n), level(lvl), health(h), attackPower(a) 
    {
        atk = a;
        attackPower = critDamage(atk);
    }
    int critDamage(int damage); // Crit function for attackPower = critDamge(input damage here)
    void attack(Player& player);
    bool isAlive(); // Checks if enemy is alive
    void displayStatus(); // Display health
};
#endif