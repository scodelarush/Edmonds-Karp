#include "IntQueue.h"

IntQueue::IntQueue()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

IntQueue::~IntQueue()
{
	while (size)this->pop();
}

int IntQueue::getSize()
{
	return this->size;
}

int IntQueue::front()
{
	return head->data;
}

void IntQueue::pop()
{
	if (!head) return;
	if (size == 1) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	size--;
}

void IntQueue::push(int data)
{
	if (!head) {
		head = new Node(data);
		tail = head;
	}
	else if (size == 1) {
		tail = new Node(data);
		tail->prev = head;
		head->next = tail;
	}
	else {
		Node* temp = new Node(data);
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
	}
	size++;
}
