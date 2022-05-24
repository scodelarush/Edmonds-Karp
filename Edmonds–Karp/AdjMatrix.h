#pragma once
#include "Array.h"

class AdjMatrix
{
	Array* data;
	int size = 0;

public:
	~AdjMatrix();

	Array& operator [](int index);

	void resize(int size);
	void destroy();
	int getSize();
};

