#pragma once
#include <iostream>
class AdjList
{
	bool** data = nullptr;
	int size = 0;

public:
	AdjList();
	~AdjList();
	int getSize();
	void resize(int size);
	bool exist(int a, int b);
	void remove(int a, int b);
	void insert(int a, int b);
	void print();
};

