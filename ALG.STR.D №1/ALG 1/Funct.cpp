#include "Header.h"
#include <iomanip>
#include <iostream>

using namespace std;

//Adds a new element to the beginning of the list
void List::push_front(int num)
{
	Node* elem = new Node();
	elem->Value = num;
	count++;

	if (head == NULL)
	{
		elem->Next = NULL;
		elem->Prev = NULL;
		head = elem;
		last = elem;
	}
	else
	{
		elem->Next = head;
		head->Prev = elem;
		elem->Prev = NULL;
		head = elem;
	}
}

//Sets the "last" pointer at the end of the list
void List::set_last()
{
	last = head;
	while (1)
	{
		if (last->Next != NULL)
		{
			last = last->Next;
		}
		else
		{
			break;
		}
	}
}

//Adds a new element before choosen index
void List::insert(int IND, int INDV)
{
	Node* elem = new Node();
	elem->Value = INDV;
	current = head;
	if (IND == 0)
	{
		elem->Next = current;
		elem->Prev = NULL;
		current->Prev = elem;
		head = elem;
	}
	else
	{
		for (int i = 0; i < IND; i++)
		{
			current = current->Next;
		}
		elem->Next = current;
		elem->Prev = current->Prev;
		current->Prev = elem;
		current = elem->Prev;
		current->Next = elem;
	}
	count++;
}

//Adds a new element to the end of the list
void List::push_back(int num)
{
	Node* elem = new Node();
	elem->Value = num;
	count++;
	if (head == NULL)
	{
		elem->Next = NULL;
		elem->Prev = NULL;
		head = elem;
		last = head;
	}
	else
	{
		set_last();
		elem->Prev = last;
		last->Next = elem;
		elem->Next = NULL;
		last = elem;
	}
}

//Prints choosen list to the console
void List::print_to_console()
{
	current = head;
	cout << "|";
	while (1)
	{
		if (isEmpty() != true)
		{
			cout << " List is empty";
			break;
		}
		if (current != NULL)
		{
			cout << current->Value << "|";
			current = current->Next;
		}
		if (current == NULL)
		{
			cout << "\n";
			break;
		}
	}
}

//Deletes last element of the list
void List::pop_back()
{
	if (count > 1)
	{
		set_last();
		current = last->Prev;
		last->Next = NULL;
		last->Prev = NULL;
		delete last;
		current->Next = NULL;
		last = current;
		count--;
	}
	else if (count == 1)
	{
		current = head;
		last = current;
		current->Next = NULL;
		current->Prev = NULL;
		delete current;
		count--;
	}
}

//Deletes element with choosen index
void List::remove(int IND)
{
	current = head;
	if (IND == 0 && count == 1)
	{
		current->Next = NULL;
		current->Prev = NULL;
		delete current;
		head = NULL;
	}
	else if (IND == 0 && count > 1)
	{
		head = current->Next;
		current->Next->Prev = NULL;
		current->Next = NULL;
		current->Prev = NULL;
		delete current;
	}
	else if (IND == count - 1)
	{
		for (int i = 0; i < IND; i++)
		{
			current = current->Next;
		}
		last = current->Prev;
		current->Prev->Next = NULL;
		current->Next = NULL;
		current->Prev = NULL;
		delete current;
	}
	else
	{
		for (int i = 0; i < IND; i++)
		{
			current = current->Next;
		}
		current->Prev->Next = current->Next;
		current->Next->Prev = current->Prev;
		current->Next = NULL;
		current->Prev = NULL;
		delete current;

	}
	count--;
}

//Returns element with choosen index
int List::at(int IND)
{
	current = head;
	for (int i = 0; i < IND; i++)
	{
		current = current->Next;
	}
	return current->Value;
}

//Replaces element with choosen index
void List::set(int IND, int INDV)
{
	current = head;
	for (int i = 0; i < IND; i++)
	{
		current = current->Next;
	}
	Node* elem = new Node();
	elem->Value = INDV;

	if (IND == 0)
	{
		elem->Next = current->Next;
		elem->Prev = NULL;
		current->Next->Prev = elem;
		current->Next = NULL;
		current->Prev = NULL;
		head = elem;
		delete current;
	}
	else if (IND == count - 1)
	{
		elem->Next = NULL;
		elem->Prev = current->Prev;
		current->Prev->Next = elem;
		current->Next = NULL;
		current->Prev = NULL;
		delete current;
	} 
	else
	{
		elem->Next = current->Next;
		elem->Prev = current->Prev;
		current->Prev->Next = elem;
		current->Next->Prev = elem;
		current->Next = NULL;
		current->Prev = NULL;
		delete current;
	}
}

//Deletes all elementes of the list
void List::clear()
{
	int i = count;
	for(int j = 0; j < i; j++)
	{
		current = head;
		head = head->Next;
		current->Next = NULL;
		current->Prev = NULL;
		delete current;
		count--;
	}
}

//Adds another list at the beginning
void List::push_frontL(List L2)
{
	L2.set_last();
	L2.current = L2.last;
	Node* elem = new Node();
	for (int i = 0; i < L2.count; i++)
	{
		elem->Value = L2.current->Value;
		count++;
		elem->Next = L2.head;
		L2.head->Prev = elem;
		elem->Prev = NULL;
		L2.head = elem;
		L2.current = L2.current->Prev;
	}
}

//Deletes first element of the list
void List::pop_front()
{
	if (count > 1)
	{
		current = head;
		head = head->Next;
		current->Prev = NULL;
		current->Next = NULL;
		delete current;
		head->Prev = NULL;
		count--;
	}
	else if (count == 1)
	{
		current = head;
		current->Next = NULL;
		current->Prev = NULL;
		delete current;
		count--;
	}
}

//Returns size of the list
size_t List::get_size()
{
	return count;
}

//Checks list for emptiness
bool List::isEmpty()
{
	return (count != 0);
}