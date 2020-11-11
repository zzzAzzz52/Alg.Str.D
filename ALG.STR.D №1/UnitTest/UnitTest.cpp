#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept>
#include "../ALG 1/Header.h"
#include "\Users\zzzAzzz\source\repos\ALG 1\Funct.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(HeaderTests)
	{
	public:
		List* lst;
		List* lst2;
		//before each test
		TEST_METHOD_INITIALIZE(setUp)
		{
			lst = new List();
			lst2 = new List();
		}
		//after each test
		TEST_METHOD_CLEANUP(cleanUP)
		{
			delete lst;
		}

		TEST_METHOD(correct_push_back)
		{
			lst->push_back(3);
			lst2->push_back(1);
			Assert::AreEqual(lst->get_size(), lst2->get_size());
		}

		TEST_METHOD(correct_push_front)
		{
			lst->push_front(3);
			lst2->push_front(1);
			Assert::AreEqual(lst->get_size(), lst2->get_size());
		}

		TEST_METHOD(correct_pop_back)
		{
			lst->push_back(1);
			lst->push_back(2);
			lst->push_back(3);
			lst2->push_back(1);
			lst2->push_back(2);
			lst->pop_back();
			Assert::AreEqual(lst->get_size(), lst2->get_size());
		}

		TEST_METHOD(correct_pop_front)
		{
			lst->push_back(1);
			lst->push_back(2);
			lst->push_back(3);
			lst2->push_back(1);
			lst2->push_back(2);
			lst->pop_front();
			Assert::AreEqual(lst->get_size(), lst2->get_size());
		}

		TEST_METHOD(correct_insert)
		{
			size_t size = 3;
			lst->push_front(1);
			lst->push_front(3);
			lst->insert(1, 2);
			Assert::AreEqual(lst->get_size(), size);
		}


		TEST_METHOD(correct_index_at)
		{
			lst->push_back(1);
			lst->push_back(2);
			lst->push_back(3);
			Assert::AreEqual(lst->at(1), 2);
		}

		TEST_METHOD(correct_remove)
		{
			size_t size = 1;
			lst->push_front(1);
			lst->push_front(3);
			lst->remove(1);
			Assert::AreEqual(lst->get_size(), size);
		}


		TEST_METHOD(correct_get_size)
		{
			lst->push_back(1);
			lst->push_back(2);
			lst->push_back(3);
			size_t b = 3;
			Assert::AreEqual(lst->get_size(), b);
		}

		TEST_METHOD(correct_clear)
		{
			size_t size = 0;
			lst->push_front(12);
			lst->push_front(11);
			lst->push_front(10);
			lst->clear();
			Assert::AreEqual(lst->get_size(), size);
		}

		TEST_METHOD(correct_set)
		{
			size_t size = 3;
			lst->push_front(12);
			lst->push_front(11);
			lst->push_front(10);
			lst->set(1, 3);
			Assert::AreEqual(lst->get_size(), size);
		}


		TEST_METHOD(correct_isEmpty)
		{
			lst->push_front(12);
			lst->push_front(11);
			lst->push_front(10);
			Assert::AreEqual(lst->isEmpty(), true);

		}

		TEST_METHOD(correct_push_front_list)
		{
			size_t size = 6;

			lst->push_front(9);
			lst->push_front(8);
			lst->push_front(10);
			lst2->push_front(1);
			lst2->push_front(2);
			lst2->push_front(3);

			lst->push_frontL(*lst2);

			Assert::AreEqual(lst->get_size(), size);
		}

	};
}
