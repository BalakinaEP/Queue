#include "Queue.h"

Queue::Queue()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}

Queue::~Queue()
{
	while (!isEmpty())
	{
		Node* temp = head;
		head = head->getNext();
		delete temp;
	}
}

bool Queue::isEmpty() const
{
	return size == 0;
}

bool Queue::isFull() const
{
	return size == QSIZE;
}

bool Queue::addNew()
{
	if (isFull())
	{
		return false;
	}
	Node* add = new Node;
	add->setNext(nullptr);
	if (isEmpty())
	{
		head = add;
	}
	else
	{
		tail->setNext(add);
	}
	tail = add;
	size++;
	return true;
}

bool Queue::deleteHead()
{
	if (isEmpty())
	{
		return false;
	}
	size--;
	Node* temp = head;
	head = head->getNext();
	delete temp;
	if (size == 0)
	{
		tail = nullptr;
	}
	return true;
}

size_t Queue::getSize() const
{
	return size;
}
