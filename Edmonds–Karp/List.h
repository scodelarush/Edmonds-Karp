#pragma once
#include <iostream>

template<typename T>
class List
{
public:
	List();
	~List();

private:
	template<typename T>
	struct Node {
		Node* next;
		T data;

		Node(T data = T(), Node* next = nullptr) {
			this->data = data;
			this->next = next;
		}
	};
	Node<T>* head;
	Node<T>* tail;
	int size;
public:

	void push_back(T data); // ����� ���������� �������� � ����� ������
	void push_front(T data); // ����� ���������� �������� � ������ ������
	int getSize() { // �����, ������� ���������� ������ ������
		return size;
	}
	T& operator[](const int index); // ���������� ��������� []
	void pop_back(); // ����� �������� ���������� �������� ������
	void pop_front(); // ����� �������� ������� �������� ������
	void insert(int index, T data); // ����� ���������� �������� �� ������� 
	void remove(int index); // ����� �������� �������� �� �������
	void clear();
	void print();
	T front();
};
