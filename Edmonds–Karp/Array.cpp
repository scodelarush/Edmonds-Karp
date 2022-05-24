#include "Array.h"

Array::Array()
{
	size = 0;
	data = nullptr;
}

Array::~Array()
{
	destroy();
}

int& Array::operator[](int index)
{
	return data[index];
}

void Array::resize(int size)
{
	destroy();
	data = new int[size];
	this->size = size;
}

void Array::destroy()
{
	delete[] data;
	this->size = 0;
}
