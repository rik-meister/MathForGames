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
    int hp = rand() % 50 + 30;       // 30–79 HP
    int atk = rand() % 10 + 5;       // 5–14 attack
    return Enemy(names[index], hp, atk);
}

int main()
{
    srand(time(0));

    Character p1("Rundas", 1, 250, 25, 0, 100);
    Character p2("Billy", 1, 100, 85, 0, 100);


    Enemy enemy = generateEnemy();
    int round = 1;
    while (p1.isAlive())
    {
        cout << "--- Round " << round << " ---";
        while (!enemy.isDefeated())
        {
            p1.attack(enemy);
            if (!enemy.isDefeated())
            {
                enemy.attack(p1);
            }
        }
    }
    //cout << "===== WELCOME TO THE ARENA =====" << endl;
    //cout << "In one corner we have...!" << endl;
    //cout << "Player: '" << p1.name << "', Level: " << p1.level << ", XP " << p1.currentXP << ", XP to next level " << p1.xpToNextLevel << std::endl;
    //cout << "and in the other...!" << endl;
    //cout << "Player: '" << p2.name << "', Level: " << p2.level << ", XP " << p2.currentXP << ", XP to next level " << p2.xpToNextLevel << std::endl;

    //int turn = 1;
    //while (p1.isAlive() && p2.isAlive())
    //{
    //    cout << "\n--- Turn " << turn << " ---" << endl;

    //    //Player 1's Turn
    //    p1.attack(p2);
    //    p2.displayStatus();

    //    if (!p2.isAlive())
    //    {
    //        cout << " Victory! " << p1.name << ", is the winner!" << endl;
    //        p1.gainXP(150);
    //        break;
    //    }

    //    //Player 2's turn
    //    p2.attack(p1);
    //    p1.displayStatus();

    //    if (!p1.isAlive())
    //    {
    //        cout << "Defeat! " << p2.name << ", is the winner!" << endl;
    //        break;
    //    }
    //    cout << "Press Enter to continue...";
    //    cin.ignore();
    //    ++turn;
    //}
    //return 0;


            //Loot Table
    //LootTable MatthewLoot;

    //MatthewLoot.addItem("Microtransactions", 70);
    //MatthewLoot.addItem("Shoe (Singular)", 15);
    //MatthewLoot.addItem("Shredded Sock (Singular?)", 15);
    //MatthewLoot.addItem("Toe", 0.003);

    //MatthewLoot.displayTable();

    //cout << "=== Roll SImulation ===";
    //for (int i = 0; i < 10; i++ )
    //{
    //    cout << "Drop" << (i + 1) << ": " << MatthewLoot.rollLoot() << endl;
    //}

    //return 0;
}