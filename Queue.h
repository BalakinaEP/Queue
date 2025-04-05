#pragma once
#include "Node.h"
class Queue
{
public:
	enum {QSIZE = 10};
private:
	size_t size;
	Node* head;
	Node* tail;
public:
	Queue();
	~Queue();
	bool isEmpty() const;
	bool isFull() const;
	bool addNew();
	bool deleteHead();
	size_t getSize() const;
};