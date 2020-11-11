#pragma once
#include <iomanip>
#include <iostream>

class Node
{
	int Value;
	class Node* Next;
	class Node* Prev;
	friend class List;
};

class List
{
	Node* head;
	Node* last;
	Node* current;
	size_t count = 0;
public:
	List() { head = NULL; last = head; current = head; }
	void push_front(int num);
	void set_last();
	void insert(int, int);
	void push_back(int num);
	void print_to_console();
	void pop_back();
	void remove(int);
	int at(int position);
	void set(int, int);
	void push_frontL(List);
	void pop_front();
	size_t get_size();
	bool isEmpty();
	void clear();
	~List() {};
};