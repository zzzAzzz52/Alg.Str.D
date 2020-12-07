#include "Header.h"
#include <iomanip>
#include <iostream>

using namespace std;

//Adds a new element to the beginning of the list
void List::push_front(int num)
{
	Node* elem = new Node(); //Создаем новый элемент списка
	elem->Value = num; //Присваиваем новому элементу заданное значение
	count++; //Увеличиваем счетчик количества элементов в списке на один

	if (head == NULL) //В случае если список пуст
	{
		elem->Next = NULL; 
		elem->Prev = NULL; //Переставляем указатели на следующий и предыдущий элемент
		head = elem;
		last = elem; //Присваиваем новому элементу указатели на начало и конец списка
	}
	else //В случае если список не пуст
	{
		elem->Next = head; 
		head->Prev = elem;
		elem->Prev = NULL;
		head = elem; //Добавляем элемент перед первым элементом списка и переставляем на него указатель на первый элемент списка
	}
}

//Sets the "last" pointer at the end of the list
void List::set_last()
{
	last = head; //Переставляем указатель на последний элемент в начало списка
	while (1)
	{
		if (last->Next != NULL) //пока не достигнем конца списка
		{
			last = last->Next; //Переставляем указатель на последний элемент на следующий элемент
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
	Node* elem = new Node(); //Создаем новый элемент списка
	elem->Value = INDV; //Присваиваем новому элементу заданное значение
	current = head; //Переставляем указатель на текущий элемент в начало списка
	if (IND == 0) //Если выбранный индекс равен 0
	{
		elem->Next = current;
		elem->Prev = NULL;
		current->Prev = elem;
		head = elem; //Вставляем элемент в начало списка и переставляем указатель на начало списка
	}
	else
	{
		for (int i = 0; i < IND; i++) //Находим элемент с нужным индексом
		{
			current = current->Next;
		}
		elem->Next = current;
		elem->Prev = current->Prev;
		current->Prev = elem;
		current = elem->Prev;
		current->Next = elem; //Вставляем элемент в нужное место перед выбранным индексом
	}
	count++;
}

//Adds a new element to the end of the list
void List::push_back(int num)
{
	Node* elem = new Node(); //Создаем новый элемент списка
	elem->Value = num; //Присваиваем новому элементу заданное значение
	count++; //Увеличиваем счетчик количества элементов в списке на один
	if (head == NULL) //В случае если список пуст
	{
		elem->Next = NULL;
		elem->Prev = NULL; //Переставляем указатели на следующий и предыдущий элемент
		head = elem;
		last = head; //Присваиваем новому элементу указатели на начало и конец списка
	}
	else //В случае если список не пуст
	{
		set_last(); //Устанавливаем указатель на конец списка на нужное место
		elem->Prev = last;
		last->Next = elem;
		elem->Next = NULL;
		last = elem; //Добавляем элемент в конец списка с помощью замены указателей на следующий предыдущий элемент
	}
}

//Prints choosen list to the console
void List::print_to_console()
{
	current = head; //Переставляем указатель на текущий элемент в начало списка
	cout << "|";
	while (1) //Выводим значения списка
	{
		if (isEmpty() != true) //проверка на пустоту списка
		{
			cout << " List is empty";
			break;
		}
		if (current != NULL) //Вывод очередного элемента
		{
			cout << current->Value << "|";
			current = current->Next;
		}
		if (current == NULL) //Конец если достигли конца списка
		{
			cout << "\n";
			break;
		}
	}
}

//Deletes last element of the list
void List::pop_back()
{
	if (count > 1) //В случае если в списке больше одного элемента
	{
		set_last(); //Устанавливаем указатель на конец списка на нужное место
		current = last->Prev; //Устанавливаем указатель на текущий элемент перед последним элементом
		last->Next = NULL;
		last->Prev = NULL;
		delete last; //Удаляем последний элемент
		current->Next = NULL;
		last = current; //Переставляем указатель на последний элемент
		count--; //Уменьшаем счетчик количества элементов в списке
	}
	else if (count == 1) //В случае если в списке один элемент
	{
		current = head; //Переставляем указатель на текущий элемент в начало списка
		last = current; //Переставляем указатель на последний элемент в начало списка
		current->Next = NULL;
		current->Prev = NULL; //Удаляем цказатели на следующие и предыдущие элементы списка
		delete current; //Удаляем текущий элемент
		count--; //Уменьшаем счетчик количества элементов в списке
	}
}

//Deletes element with choosen index
void List::remove(int IND)
{
	current = head; //Переставляем указатель на текущий элемент в начало списка
	if (IND == 0 && count == 1) //Если выбранный индекс равен 0 и в списке всего один элемент
	{
		current->Next = NULL;
		current->Prev = NULL;
		delete current; //Удаляем нужный элемент
		head = NULL; //Обнуляем указатель на первый элемент списка
	}
	else if (IND == 0 && count > 1) //Если выбранный индекс равен 0 и в списке больше одного элемента
	{
		head = current->Next; //Переставляем указатель на первый элемент на один элемент вперед
		current->Next->Prev = NULL;
		current->Next = NULL;
		current->Prev = NULL;
		delete current; //Удаляем нужный элемент
	}
	else if (IND == count - 1) //Если выбранный индекс равен последнему элементу
	{
		for (int i = 0; i < IND; i++) //Переставляем указатель на текущий элемет в конец списка
		{
			current = current->Next;
		}
		last = current->Prev; //Переставляем указатель на последний элемент на предпоследний элемент
		current->Prev->Next = NULL;
		current->Next = NULL;
		current->Prev = NULL;
		delete current; //Удаляем последний элемент
	}
	else //В остальных случаях
	{
		for (int i = 0; i < IND; i++) //Переставляем указатель на текущий элемет в конец списка
		{
			current = current->Next;
		}
		current->Prev->Next = current->Next;
		current->Next->Prev = current->Prev;
		current->Next = NULL;
		current->Prev = NULL; //Переставляем указатели на следующие и предыдущие элементы
		delete current; //Удаляем элемент с нужным индексом

	}
	count--; //Уменьшаем счетчик количества элементов в списке
}

//Returns element with choosen index
int List::at(int IND)
{
	current = head; //Переставляем указатель на текущий элемент в начало списка
	for (int i = 0; i < IND; i++) //Перемещаемся к элементу с нужным индексом
	{
		current = current->Next;
	}
	return current->Value; //Возвращаем элемент с нужным индексом
}

//Replaces element with choosen index
void List::set(int IND, int INDV)
{
	current = head; //Переставляем указатель на текущий элемент в начало списка
	for (int i = 0; i < IND; i++) //Перемещаемся к элементу с нужным индексом
	{
		current = current->Next;
	}
	Node* elem = new Node(); //Создаем новый элемент списка
	elem->Value = INDV; //Присваиваем новому элементу заданное значение

	if (IND == 0) //Если выбранный индекс равен 0
	{
		elem->Next = current->Next;
		elem->Prev = NULL;
		current->Next->Prev = elem;
		current->Next = NULL;
		current->Prev = NULL; //Переставляем указатели на следующие и предыдущие элементы
		head = elem; //Переставляем указатель на начало списка на новый элемент
		delete current; //Удаляем текущий элемент
	}
	else if (IND == count - 1) //если выбранный индекс равен последнему элементу
	{
		elem->Next = NULL;
		elem->Prev = current->Prev;
		current->Prev->Next = elem;
		current->Next = NULL;
		current->Prev = NULL; //Переставляем указатели на следующие и предыдущие элементы
		delete current; //Удаляем текущий элемент
	} 
	else //В остальных случаях
	{
		elem->Next = current->Next;
		elem->Prev = current->Prev;
		current->Prev->Next = elem;
		current->Next->Prev = elem;
		current->Next = NULL;
		current->Prev = NULL; //Переставляем указатели на следующие и предыдущие элементы
		delete current; //Удаляем текущий элемент
	}
}

//Deletes all elementes of the list
void List::clear()
{
	int i = count;
	for(int j = 0; j < i; j++) //Поочередно удаляем элементы списка
	{
		current = head; //Переставляем указатель на текущий элемент в начало списка
		head = head->Next; //Переставляем указатель на начало списка на следующий элемент
		current->Next = NULL;
		current->Prev = NULL; //Переставляем указатели на следующие и предыдущие элементы
		delete current; //Удаляем текущий элемент
		count--; //Уменьшаем счетчик количества элементов в списке
	}
}

//Adds another list at the beginning
void List::push_frontL(List L2)
{
	L2.set_last(); //Устанавливаем указатель на последний элемент в списке который добавляем в начало нужного списка
	L2.current = L2.last; //Устанавливаем указатель на текущий элемент в конец списка
	Node* elem = new Node(); //Создаем новый элемент списка
	for (int i = 0; i < L2.count; i++) //Добавляем второй список в начало первого списка
	{
		elem->Value = L2.current->Value; //Переносим значение из элемента второго списка в новый элемент
		count++; //Увеличиваем счетчик количества элементов в списке
		elem->Next = L2.head;
		L2.head->Prev = elem; 
		elem->Prev = NULL; //Переставляем указатели на следующий и предыдущий элементы
		L2.head = elem;
		L2.current = L2.current->Prev;
	}
}

//Deletes first element of the list
void List::pop_front()
{
	if (count > 1) //Если в списке больше одного элемента
	{
		current = head; //Переставляем указатель на текущий элемент в начало списка
		head = head->Next; //Переставляем указатель на начало списка на следующий элемент
		current->Prev = NULL;
		current->Next = NULL; //Переставляем указатели на следующие и предыдущие элементы
		delete current; //Удаляем текущий элемент
		head->Prev = NULL;
		count--; //Уменьшаем счетчик количества элементов в списке
	}
	else if (count == 1) //Если в списке ровно один элемент
	{
		current = head; //Переставляем указатель на текущий элемент в начало списка
		current->Next = NULL;
		current->Prev = NULL; //Переставляем указатели на следующие и предыдущие элементы
		delete current; //Удаляем текущий элемент
		count--; //Уменьшаем счетчик количества элементов в списке
	}
}

//Returns size of the list
size_t List::get_size()
{
	return count; //Возвращаем размер списка
}

//Checks list for emptiness
bool List::isEmpty()
{
	return (count != 0); //Проверяем список на пустоту
}
