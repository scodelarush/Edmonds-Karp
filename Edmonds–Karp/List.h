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

	void push_back(T data); // Метод добавление элемента в конец списка
	void push_front(T data); // Метод добавление элемента в начало списка
	int getSize() { // Метод, которая возвращает размер списка
		return size;
	}
	T& operator[](const int index); // Перегрузка оператора []
	void pop_back(); // Метод удаление последнего элемента списка
	void pop_front(); // Метод удаление первого элемента списка
	void insert(int index, T data); // Метод добавление элемента по индексу 
	void remove(int index); // Метод удаления элемента по индексу
	void clear();
	void print();
	T front();
};
