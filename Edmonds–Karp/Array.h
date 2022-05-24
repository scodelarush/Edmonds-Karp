#pragma once
class Array
{
	int* data;
	int size;

public:
	Array();
	~Array();

	int& operator[](int index);

	void resize(int size);
	void destroy();

};

