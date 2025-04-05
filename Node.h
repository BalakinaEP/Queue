#pragma once
class Node
{
private:
	Node* next;
public:
	Node();
	Node* getNext() const;
	void setNext(Node* next);
};