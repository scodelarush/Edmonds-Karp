#pragma once
#include <iostream>
#include <list>
#include "List.h"
#include <iterator>
#include <string>

template <typename T1, typename T2>
class Map
{
public:

	Map(); //O(1)
	~Map(); //O(n)

private:
	template<typename T1, typename T2>
	struct Node {
		Node<T1, T2>* left;
		Node<T1, T2>* right;
		Node<T1, T2>* parent;
		bool color; // 0 - black, 1 - red
		T2 value;
		T1 key;

		Node(T1 key = T1(), T2 value = T2(), Node* left = nullptr, Node* right = nullptr, Node* parent = nullptr) {
			this->key = key;
			this->value = value;
			this->left = left;
			this->right = right;
			this->parent = parent;
			this->color = 1;
		}
	};
	Node<T1, T2>* head;
	int size;
	std::list<T1> keys;
	std::list<T2> values;
public:

	void removeNode(Node<T1, T2>* temp); //O(n)

	void insert(typename T1, typename T2); //O(logn)
	void balanceInsert(Node<T1, T2>* node); //O(logn)

	void remove(typename T1); //O(logn) (не учитывая удаления элементов из списка, которое вроде как O(n))
	void balanceRemove(Node<T1, T2>* node, bool side); //O(logn)

	void leftRotate(Node<T1, T2>* node); //O(1)
	void rightRotate(Node<T1, T2>* node); //O(1)

	int getSize(); //O(1)
	Node<T1, T2>* getHead() const; //O(1)

	T2 find(T1 key); //O(logn)
	Node<T1, T2>* findNode(T1 key) const; //O(logn)
	bool exist(T1 key);

	void clear(); //O(n)

	std::list<T1> getKeys(); //O(1)
	std::list<T2> getValues(); //O(1)

	void print(Node<T1, T2>* node); // O(n) 
	void print(); //O(n)

	T2& operator[](const T1 key);

	T1 getHeadKey();
	T2 getHeadValue();
};


