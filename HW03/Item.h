
#include <iostream>
#include <string>
#pragma once

using namespace std;

class Item
{
private:
	string name_;
	int price_;

public:
	Item() : name_(""), price_(0) {}	// 기본 생성자

	Item(string name, int price) : name_(name), price_(price) {}

	int GetPrice() const
	{
		return price_;
	}

	void PrintInfo() const
	{
		cout << "[Item Name : " << name_ << ", Item Price : " << price_ << "G]" << endl;
	}
};