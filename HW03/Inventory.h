// 인벤토리 클래스 템플릿 T 설계

#pragma once
#include <iostream>
#include <algorithm>
#include "Item.h"

using namespace std;

template <typename T>
class Inventory
{
	private:
		T* pItems_;		//아이템 배열(배열을 가리킬 변수(포인터)
		int capacity_;	//최대 개수
		int size_;		//현재 개수

	public:
		Inventory(int capacity = 10);
		Inventory(const Inventory<T>& other);	// 도전 기능 추가
		~Inventory();

		void AddItem(const T& item);
		void RemoveLastItem();

		void Assign(const Inventory<T>& other);	// 도전 기능 추가
		void Resize(int newCapacity);			// 도전 기능 추가
		void SortItems();						// 도전 기능 추가

		int GetSize() const;
		int GetCapacity() const;

		void PrintAllItems() const;
};

template <typename T>
Inventory<T>::Inventory(int capacity)
{
	if (capacity <= 0)
		capacity_ = 1;
	else
		capacity_ = capacity;

	size_ = 0;
	pItems_ = new T[capacity_];
}

template <typename T>
Inventory<T>::~Inventory()
{
	delete[] pItems_;
	pItems_ = nullptr;
}

template <typename T>
void Inventory<T>::AddItem(const T& pItem)
{
	// 도전 과제 기능
	if (size_ >= capacity_)
	{
		Resize(capacity_ * 2);
	}

	pItems_[size_] = pItem;
	size_++;
	/* 필수 기능시 사용 코드
	if (size_ < capacity_)
	{
		pItems_[size_] = pItem;	//현재 위치에 넣고
		size_++;				//개수 증가
	}
	else
	{
		cout << "Inventory is full." << endl;
	}
	*/
}

template <typename T>
void Inventory<T>::RemoveLastItem()
{
	if (size_ > 0)
	{
		size_--;	// 마지막 접근 못하게 만듦
	}
	else
	{
		cout << "Inventory is empty." << endl;
	}
}

template <typename T>
int Inventory<T>::GetSize() const
{
	return size_;
}

template <typename T>
int Inventory<T>::GetCapacity() const
{
	return capacity_;
}

template <typename T>
void Inventory<T>::PrintAllItems() const
{
	if (size_ == 0)
	{
		cout << "Empty.." << endl;
		return;
	}
	
	for (int i = 0; i < size_; i++)
	{
		pItems_[i].PrintInfo();
	}
}

template <typename T>
Inventory<T>::Inventory(const Inventory<T>& other)
{
	capacity_ = other.capacity_;
	size_ = other.size_;

	pItems_ = new T[capacity_];

	for (int i = 0; i < size_; ++i)
	{
		pItems_[i] = other.pItem_[i];
	}
}

template <typename T>
void Inventory<T>::Assign(const Inventory<T>& other)
{
	// 자기 자신 대입
	if (this == &other)
		return;

	// 기존 메모리 해제
	delete[] pItems_;

	capacity_ = other.capacity_;
	size_ = other.size_;

	// 새 메모리 할당
	pItems_ = new T[capacity_];

	// 데이터 복사
	for (int i = 0; i < size_; ++i)
	{
		pItems_[i] = other.pItems_[i];
	}
}

template <typename T>
void Inventory<T>::Resize(int newCapacity)
{
	if (newCapacity <= capacity_)
		return;

	// 1. 새 메모리 생성
	T* newItems = new T[newCapacity];

	// 2. 기존 데이터 복사
	for (int i = 0; i < size_; ++i)
	{
		newItems[i] = pItems_[i];
	}

	// 3. 기존 메모리 해제
	delete[] pItems_;

	// 4. 포인터 교체
	pItems_ = newItems;

	// 5. capacity 갱신
	capacity_ = newCapacity;
}

bool compareItemByPrice(const Item& a, const Item& b)
{
	return a.GetPrice() < b.GetPrice(); // 오름차순
}

template <typename T>
void Inventory<T>::SortItems()
{
	std::sort(pItems_, pItems_ + size_, compareItemByPrice);
}