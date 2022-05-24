#include "AdjList.h"



AdjList::AdjList()
{
	data = nullptr;
	size = 0;
}

AdjList::~AdjList()
{
	for (int i = 0; i < this->size; i++)delete[] data[i];
	delete[] data;
}

int AdjList::getSize()
{
	return this->size;
}

void AdjList::resize(int size)
{
	this->size = size;
	data = new bool* [size];
	for (int i = 0; i < size; i++)data[i] = new bool[size];
	for (int i = 0; i < this->size; i++)for (int j = 0; j < this->size; j++)data[i][j] = false;
}

bool AdjList::exist(int a, int b)
{
	if (data[a][b]) return true;
	return false;
}

void AdjList::remove(int a, int b)
{
	data[a][b] = 0;
}

void AdjList::insert(int a, int b)
{
	data[a][b] = true;
}

void AdjList::print()
{
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++)std::cout << data[i][j] << " ";
		std::cout << '\n';
	}
}
