#include "Header.h"
#include <iomanip>
#include <iostream>

using namespace std;

//Main function
void main()
{
	int choise, value, index, LST;

	List* LST1 = new List;
	List* LST2 = new List;

	while (1)
	{
		cout << "\n\n1: Add a new element to the end of the list\n2: Add a new element to the beginning of the list\n3: Delete last element of the list\n4: Delete first element of the list\n5: Add a new element before choosen index\n6: Return element with choosen index\n7: Delete element with choosen index\n8: Return size of the list\n9: Print choosen list to the console\n10: Delete all elementes of the list\n11: Replace element with choosen index\n12: Check list for emptiness\n13: Add another list at the beginning\n14: Exit";
		cout << "\n\nChoose one of the following options (numbers from 1 to 14) : ";
		cin >> choise;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());

		if (choise == 1)
		{
			cout << "\n\nChoose List to work with (1 or 2): ";
			cin >> LST;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "\n\nEnter value of the new element: ";
			cin >> value;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			if (LST == 1)
			{
				LST1->push_back(value);
				cout << "List 1 after change: ";
				LST1->print_to_console();
			}
			else if (LST == 2)
			{
				LST2->push_back(value);
				cout << "List 2 after change: ";
				LST2->print_to_console();
			}
			else
			{
				cout << "\n\nWrong list. Choose list 1 or 2.\n\n";
			}
		}
		else if (choise == 2)
		{
			cout << "\n\nChoose List to work with (1 or 2): ";
			cin >> LST;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "\n\nEnter value of the new element: ";
			cin >> value;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			if (LST == 1)
			{
				LST1->push_front(value);
				cout << "List 1 after change: ";
				LST1->print_to_console();
			}
			else if (LST == 2)
			{
				LST2->push_front(value);
				cout << "List 2 after change: ";
				LST2->print_to_console();
			}
			else
			{
				cout << "\n\nWrong list. Choose list 1 or 2.\n\n";
			}

		}
		else if (choise == 3)
		{
			cout << "\n\nChoose List to work with (1 or 2): ";
			cin >> LST;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			if (LST == 1)
			{
				LST1->pop_back();
				cout << "List 1 after change: ";
				LST1->print_to_console();
			}
			else if (LST == 2)
			{
				LST2->pop_back();
				cout << "List 2 after change: ";
				LST2->print_to_console();
			}
			else
			{
				cout << "\n\nWrong list. Choose list 1 or 2.\n\n";
			}

		}
		else if (choise == 4)
		{
			cout << "\n\nChoose List to work with (1 or 2): ";
			cin >> LST;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			if (LST == 1)
			{
				LST1->pop_front();
				cout << "List 1 after change: ";
				LST1->print_to_console();
			}
			else if (LST == 2)
			{
				LST2->pop_front();
				cout << "List 2 after change: ";
				LST2->print_to_console();
			}
			else
			{
				cout << "\n\nWrong list. Choose list 1 or 2.\n\n";
			}

		}
		else if (choise == 5)
		{
			cout << "\n\nChoose List to work with (1 or 2): ";
			cin >> LST;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "\n\nEnter value of the new element: ";
			cin >> value;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "\n\nEnter index of element: ";
			cin >> index;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			if ((LST == 1) && (index < LST1->get_size()))
			{
				LST1->insert(index, value);
				cout << "List 1 after change: ";
				LST1->print_to_console();
			}
			else if ((LST == 2) && (index <= LST2->get_size()))
			{
				LST2->insert(index, value);
				cout << "List 2 after change: ";
				LST2->print_to_console();
			}
			else
			{
				if (LST != (1 || 2))
				{
					cout << "\n\nWrong list. Choose list 1 or 2.\n\n";

				}
				else
				{
					cout << "\n\nChoose index lesser than list size";
				}
			}

		}
		else if (choise == 6)
		{
			cout << "\n\nChoose List to work with (1 or 2): ";
			cin >> LST;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "\n\nEnter index of element: ";
			cin >> index;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());

			if ((LST == 1) && (index < LST1->get_size()))
			{
				cout << "Element with choosen index: " << LST1->at(index);
			}
			else if ((LST == 2) && (index <= LST2->get_size()))
			{
				cout << "Element with choosen index: " << LST2->at(index);
			}
			else
			{
				if (LST != (1 || 2))
				{
					cout << "\n\nWrong list. Choose list 1 or 2.\n\n";

				}
				else
				{
					cout << "\n\nChoose index lesser than list size";
				}
			}
		}
		else if (choise == 7)
		{
			cout << "\n\nChoose List to work with (1 or 2): ";
			cin >> LST;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "\n\nEnter index of element: ";
			cin >> index;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());

			if ((LST == 1) && (index < LST1->get_size()))
			{
				LST1->remove(index);
				cout << "List 1 after change: ";
				LST1->print_to_console();
			}
			else if ((LST == 2) && (index <= LST2->get_size()))
			{
				LST2->remove(index);
				cout << "List 2 after change: ";
				LST2->print_to_console();
			}
			else
			{
				if (LST != (1 || 2))
				{
					cout << "\n\nWrong list. Choose list 1 or 2.\n\n";
	
				}
				else
				{
					cout << "\n\nChoose index lesser than list size";
				}
			}

		}
		else if (choise == 8)
		{
			cout << "\n\nChoose List to work with (1 or 2): ";
			cin >> LST;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());

			if (LST == 1)
			{
				cout << "List 1 size: " << LST1->get_size();
			}
			else if (LST == 2)
			{
				cout << "List 2 size: " << LST2->get_size();
			}
			else
			{
				cout << "\n\nWrong list. Choose list 1 or 2.\n\n";
			}

		}
		else if (choise == 9)
		{
			cout << "\n\nChoose List to work with (1 or 2): ";
			cin >> LST;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			if (LST == 1)
			{
				cout << "List 1: ";
				LST1->print_to_console();
			}
			else if (LST == 2)
			{
				cout << "List 2: ";
				LST2->print_to_console();
			}
			else
			{
				cout << "\n\nWrong list. Choose list 1 or 2.\n\n";
			}


		}
		else if (choise == 10)
		{
			cout << "\n\nChoose List to work with (1 or 2): ";
			cin >> LST;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			if (LST == 1)
			{
				LST1->clear();
				cout << "List 1 was cleared.";
			}
			else if (LST == 2)
			{
				LST2->clear();
				cout << "List 2 was cleared.";
			}
			else
			{
				cout << "\n\nWrong list. Choose list 1 or 2.\n\n";
			}

		}
		else if (choise == 11)
		{
			cout << "\n\nChoose List to work with (1 or 2): ";
			cin >> LST;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "\n\nEnter value of the new element: ";
			cin >> value;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "\n\nEnter index of element for change: ";
			cin >> index;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			if ((LST == 1) && (index < LST1->get_size()))
			{
				LST1->set(index, value);
				cout << "List 1 after change: ";
				LST1->print_to_console();
			}
			else if ((LST == 2) && (index <= LST2->get_size()))
			{
				LST2->set(index, value);
				cout << "List 2 after change: ";
				LST2->print_to_console();
			}
			else
			{
				if (LST != (1 || 2))
				{
					cout << "\n\nWrong list. Choose list 1 or 2.\n\n";
				}
				else
				{
					cout << "\n\nChoose index lesser than list size";
				}
			}

		}
		else if (choise == 12)
		{
			cout << "\n\nChoose List to work with (1 or 2): ";
			cin >> LST;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			if (LST == 1)
			{
				if (LST1->isEmpty() == true)
				{
					cout << "List 1 is not empty.";
				}
				else
				{
					cout << "List 1 is empty.";
				}
			}
			else if (LST == 2)
			{
				if (LST2->isEmpty() == true)
				{
					cout << "List 2 is not empty.";
				}
				else
				{
					cout << "List 2 is empty.";
				}

			}
			else
			{
				cout << "\n\nWrong list. Choose list 1 or 2.\n\n";
			}
		}
		else if (choise == 13)
		{
			cout << "\n\nChoose List to work with (1 or 2): ";
			cin >> LST;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			if (LST == 1)
			{
				LST1->push_frontL(*LST2);
				cout << "List 1 after change: ";
				LST1->print_to_console();
			}
			else if (LST == 2)
			{
				LST2->push_frontL(*LST1);
				cout << "List 2 after change: ";
				LST2->print_to_console();
			}
			else
			{
				cout << "\n\nWrong list. Choose list 1 or 2.\n\n";
			}

		}
		else if (choise == 14)
		{
			exit(1);
		}
		else
		{
			cout << "Wrong number. Choose one of the following options (numbers from 1 to 13)";
		}
	}
}