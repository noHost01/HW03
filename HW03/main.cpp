// Main.cpp

#include <iostream>
#include <string>
#include "Item.h"
#include "Inventory.h"


using namespace std;

int main()
{
	Inventory<Item> inv(2);

	inv.AddItem(Item("Sword", 100));
	inv.AddItem(Item("Potion", 50));
	inv.AddItem(Item("Shild", 150));

	cout << "\n [Before Sort] \n";
	inv.PrintAllItems();	//호출 출력

	inv.SortItems(); // 정렬 테스트

	cout << "\n [After Sort] \n";
	inv.PrintAllItems();

	return 0;
}