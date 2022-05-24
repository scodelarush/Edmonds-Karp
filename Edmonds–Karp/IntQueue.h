#pragma once
class IntQueue
{
	struct Node {
		Node* next;
		Node* prev;
		int data;

		Node(int data = int(), Node* next = nullptr, Node* prev = nullptr) {
			this->data = data;
			this->next = next;
			this->prev = prev;
		}
	};
	Node* head;
	Node* tail;
	int size;

public:
	IntQueue();
	~IntQueue();
	int getSize();
	int front();
	void pop();
	void push(int data);
};

