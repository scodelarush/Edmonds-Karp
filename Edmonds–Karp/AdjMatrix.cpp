#include "AdjMatrix.h"

AdjMatrix::~AdjMatrix()
{
	destroy();
}

Array& AdjMatrix::operator[](int index)
{
	return data[index];
}

void AdjMatrix::resize(int size)
{
	destroy();
	this->data = new Array[size];
	for (int i = 0; i < size; i++)data[i].resize(size);
	this->size = size;
}

void AdjMatrix::destroy()
{
	delete[] this->data;
	this->size = 0;
}

int AdjMatrix::getSize()
{
	return this->size;
}
