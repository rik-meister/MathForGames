#include "LootTable.h"
#include <iostream>

using namespace std;

LootTable::LootTable()
{
	totalWeight = 0;
	itemCount = 0;
}
void LootTable::addItem(string name, int weight)
{
	if (itemCount < 5)
	{
		items[itemCount].name = name;
		items[itemCount].weight = weight;
		totalWeight += weight;
		itemCount++;
	}
}
string LootTable::rollLoot()
{
	if (itemCount == 0)
	{
		return "Nothing.";
	}

	int roll = rand() % totalWeight;
	int cumulative = 0;

	for (int i = 0; i < itemCount; i++)
	{
		cumulative += items[i].weight;
		if (roll < cumulative)
		{
			return items[i].name;
		}
	}
	return items[0].name;
}
void LootTable::displayTable()
{
	cout << "=== Loot Table ===" << endl;
	for (int i = 0; i < itemCount; i++)
	{
		float chance = (items[i].weight / (float)totalWeight) * 100;
		cout << items[i].name << ": " << chance << "%" << endl;
	}
}