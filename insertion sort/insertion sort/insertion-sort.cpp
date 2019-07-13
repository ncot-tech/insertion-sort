// insertion sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>

const int itemCount = 10;
int items[itemCount];

void fillItems()
{
	for (int i = 0; i < itemCount; i++)
		items[i] = i;
}

void shuffleItems()
{
	for (int i = 0; i < itemCount - 2; i++) {
		int j = rand() % itemCount;
		int tmp = items[i];
		items[i] = items[j];
		items[j] = tmp;
	}
}

void insertionSort()
{
	int unsortedStart = 1;
	while (unsortedStart < itemCount) {
		int currentItem = items[unsortedStart];
		int index = unsortedStart - 1;
		while (index >= 0 && items[index] > currentItem) {
			items[index + 1] = items[index];
			index--;
		}
		items[index + 1] = currentItem;
		unsortedStart++;
	}
}

void printItems()
{
	std::cout << "Items:\n|";
	for (int i = 0; i < itemCount; i++) {
		std::cout << items[i] << "|";
	}
	std::cout << "\n";
}

int main()
{
	fillItems();
	shuffleItems();
	printItems();
	insertionSort();
	printItems();
}
