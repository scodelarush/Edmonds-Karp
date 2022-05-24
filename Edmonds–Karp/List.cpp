#include "List.h"

template<typename T>
List<T>::List() {
	head = nullptr;
	tail = nullptr;
	size = 0;
}

template<typename T>
void List<T>::pop_back() {
	remove(size - 1);
}

template<typename T>
List<T>::~List() {
	while (size) pop_front();
	delete head;
}

template<typename T>
void List<T>::push_back(T data) {
	if (head == nullptr) head = new Node<T>(data);
	else if (head->next == nullptr) {
		tail = new Node<T>(data);
		head->next = tail;
	}
	else {
		tail->next = new Node<T>(data);
		tail = tail->next;
	}
	size++;
}

template<typename T>
T& List<T>::operator[](const int index) {
	int i = 0;
	Node<T>* temp = this->head;
	while (temp != nullptr) {
		if (i == index) return temp->data;
		else {
			temp = temp->next;
			i++;
		}
	}
}

template<typename T>
void List<T>::insert(int index, T data) {
	if (index == 0) push_front(data);
	else if (index == size) push_back(data);
	else {
		Node<T>* temp = this->head;
		for (int i = 0; i < index - 1; i++)temp = temp->next;
		Node<T>* newNode = new Node<T>(data, temp->next);
		temp->next = newNode;
		size++;
	}
}

template<typename T>
void List<T>::remove(int index) {
	if (index == 0)pop_front();
	else if (index == size - 1) {
		Node<T>* temp = this[size-2];
		temp->next = nullptr;
		delete tail;
		tail = temp;
	}
	else if(index < size) {
		Node<T>* temp = this->head;
		for (int i = 0; i < index - 1; i++)temp = temp->next;
		Node<T>* t = temp->next;
		temp->next = t->next;
		delete t;
		size--;
	}
}

template<typename T>
void List<T>::push_front(T data) {
	Node<T>* temp = new Node<T>(data, head);
	head = temp;
	size++;
}

template<typename T>
void List<T>::pop_front() {
	Node<T>* temp = head;
	head = head->next;
	delete temp;
	size--;
}

template<typename T>
void List<T>::clear() {
	while (size)pop_front();
}

template<typename T>
void List<T>::print() {
	Node<T>* temp = head;
	if (temp == nullptr) return;
	while (temp) {
		std::cout << temp->data << '\n';
		temp = temp->next;
	}
}

template<typename T>
T List<T>::front()
{
	return head->data;
}
