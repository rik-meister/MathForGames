#include<iostream>
#include<fstream>
#include<string>
#include "XpSystem.h"
#include "LootTable.h"

using namespace std;

int main()
{

           /* Player XP*/

    Player p1("Rundas", 1, 250, 25, 0, 100);
    Player p2("Billy", 1, 100, 75, 0, 100);

    cout << "===== WELCOME TO THE ARENA =====" << endl;
    cout << "In one corner we have...!" << endl;
    cout << "Player: '" << p1.name << "', Level: " << p1.level << ", XP " << p1.currentXP << ", XP to next level " << p1.xpToNextLevel << std::endl;
    cout << "and in the other...!" << endl;
    cout << "Player: '" << p2.name << "', Level: " << p2.level << ", XP " << p2.currentXP << ", XP to next level " << p2.xpToNextLevel << std::endl;


    return 0;


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