#pragma once
#ifndef LOOTTABLE_H
#define LOOTTABLE_H

#include <string>
using namespace std;

struct LootItem
{
	string name;
	int weight;
};

class LootTable
{
private:
	LootItem items[5];
	int itemCount;
	int totalWeight;

public:
	LootTable();
	void addItem(string name, int weight);
	string rollLoot();
	void displayTable();
};
#endif