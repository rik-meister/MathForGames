#include<iostream>
#include<fstream>
#include<string>
#include "XpSystem.h"
#include "LootTable.h"

using namespace std;


Enemy generateEnemy() 
{
    string names[] = { "Goblin", "Orc", "Troll", "Skeleton", "Bandit" };
    int index = rand() % 5;
    int lvl = rand() % 10 + 5;        // 5-14 level
    int hp = rand() % 50 + 30;       // 30–79 HP
    int attackPower = rand() % 10 + 5;       // 5–14 attack
    return Enemy(names[index], lvl, hp, attackPower);
}

int main()
{
    srand(time(0));

    string command;

    Player p1("Rundas", 1, 250, 250, 25, 0, 100);
    Player p2("Billy", 1, 100, 100, 85, 0, 100);

    Enemy enemies = generateEnemy();

    //Loot Table
    LootTable rpgLoot;

    rpgLoot.addItem("Microtransactions", 70);
    rpgLoot.addItem("Shoe (Singular)", 15);
    rpgLoot.addItem("Shredded Sock (Singular?)", 15);
    rpgLoot.addItem("Toe", 0.003);


    //=== Roll SImulation ===
    /*for (int i = 0; i < 10; i++)
    {
        cout << "Drop" << (i + 1) << ": " << rpgLoot.rollLoot() << endl;
    }*/


    cout << "===== WELCOME TO THE ARENA =====" << endl;
    cout << "Player: '" << p1.name << "', Level: " << p1.level << ", XP " << p1.currentXP << ", XP to next level " << p1.xpToNextLevel << std::endl;

    int round = 1;
    int restCount = 0;

    while (p1.isAlive())
    {
        cout << "\n===================== Round " << round << " =====================" << endl;
        Enemy enemies = generateEnemy();
        cout << "---> Ecounter: Level " << enemies.level << " " << enemies.name << endl;
        cout << "===================================================" << endl;
        cout << "====== [C]ontinue - [R]est - [Q]uit =====" << endl;
        cout << "===================================================" << endl;
        cin >> command;
     
        if (command == "r")
        {
            if (restCount >= 3)
            {
                cout << "You can no longer rest" << endl;
                p1.displayStatus();
                cin.ignore();
            }
            else 
            {
                p1.rest();

                cout << "Resting... ";
                p1.displayStatus();
            }
            restCount++;
        }
        else if (command == "q")
        {
            break;
        }

        while (command == "c" && enemies.isAlive())
        {
            //Player 1's Turn
            p1.attack(enemies);
            enemies.displayStatus();

    
            if (!enemies.isAlive())
            {
                cout << enemies.name << " is defeated!" << endl;
                cout << enemies.name << " dropped " << rpgLoot.rollLoot() << endl;
                p1.gainXP(150);
                
                break;
            }

            enemies.attack(p1);
            p1.displayStatus();

            cout << "====== [C]ontinue - [E]scape =====" << endl;
            cin >> command;

            if (command == "e")
            {
                break;
            }

            if (!p1.isAlive())
            {
                cout << p1.name << " has fallen in battle." << endl;
                break;
            }
        }
        ++round;
    }
}