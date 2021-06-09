#include "pch.h"
#include "CppUnitTest.h"
#include "../CourseWork/Graph.h"
#include "../CourseWork/List.h"
#include "../CourseWork/Graph.cpp"
#include "../CourseWork/List.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ALgoTest
{
	TEST_CLASS(BiListTest)
	{
	public:
		BiList<int> Empty;
		BiList<int> NotEmpty;
		TEST_METHOD_INITIALIZE(SetUp)
		{
			for (size_t i = 0; i < 3; i++)
				NotEmpty.push_back(i + 1);
		}
		TEST_METHOD(IsEmpty_for_NotEmpty)
		{
			Assert::AreEqual(NotEmpty.isEmpty(), false);
		}
		TEST_METHOD(IsEmpty_for_Empty)
		{
			Assert::AreEqual(Empty.isEmpty(), true);
		}
		TEST_METHOD(Get_Size_for_Empty)
		{
			size_t real_size = 0;
			Assert::AreEqual(Empty.get_size(), real_size);
		}
		TEST_METHOD(Get_Size_for_NotEmpty)
		{
			size_t real_size = 3;
			Assert::AreEqual(NotEmpty.get_size(), real_size);
		}
		TEST_METHOD(at_correct_index)
		{
			Assert::AreEqual(NotEmpty.at(2), 3);
		}
		TEST_METHOD(at_incorrect_index)
		{
			try
			{
				Empty.at(4);
			}
			catch (const char* error)
			{
				Assert::AreEqual(error, "Incorrect index.");
			}
		}
		TEST_METHOD(Push_Back_NotEmpty)
		{
			NotEmpty.push_back(5);
			Assert::AreEqual(NotEmpty.at(3), 5);
		}
		TEST_METHOD(Push_Front_NotEmpty)
		{
			NotEmpty.push_front(0);
			Assert::AreEqual(NotEmpty.at(0), 0);
		}
		TEST_METHOD(remove_correct_index)
		{
			int temp = NotEmpty.at(2);
			NotEmpty.remove(1);
			Assert::AreEqual(NotEmpty.at(1), temp);
		}
		TEST_METHOD(Pop_Back_for_NotEmpty)
		{
			size_t real_size = NotEmpty.get_size() - 1;
			NotEmpty.pop_back();
			Assert::AreEqual(NotEmpty.get_size(), real_size);
		}
		TEST_METHOD(Pop_Back_for_Empty)
		{
			Empty.pop_back();
			Assert::AreEqual(Empty.isEmpty(), true);
		}
		TEST_METHOD(Pop_Front_for_NotEmpty)
		{
			size_t real_size = NotEmpty.get_size() - 1;
			NotEmpty.pop_front();
			Assert::AreEqual(NotEmpty.get_size(), real_size);
		}
		TEST_METHOD(insert_correct_index)
		{
			NotEmpty.insert(4, 1);
			Assert::AreEqual(NotEmpty.at(1), 4);
		}
		TEST_METHOD(insert_incorrect_index)
		{
			try
			{
				Empty.insert(2, 0);
			}
			catch (const char* error)
			{
				Assert::AreEqual("Incorrect index.", error);
			}
		}
		TEST_METHOD(remove_incorrect_index)
		{
			try
			{
				Empty.remove(2);
			}
			catch (const char* error)
			{
				Assert::AreEqual("Incorrect index.", error);
			}
		}
		TEST_METHOD(reverse_for_NotEmpty)
		{
			int last_inf = NotEmpty.at(NotEmpty.get_size() - 1);
			NotEmpty.reverse();
			Assert::AreEqual(NotEmpty.at(0), last_inf);
		}
		TEST_METHOD(Pop_Front_for_Empty)
		{
			Empty.pop_front();
			Assert::AreEqual(Empty.isEmpty(), true);
		}
		TEST_METHOD(set_correct_index)
		{
			NotEmpty.set(2, 3);
			Assert::AreEqual(NotEmpty.at(2), 3);
		}
		TEST_METHOD(set_incorrect_index)
		{
			try
			{
				NotEmpty.set(10000000, 2);
			}
			catch (const char* error)
			{
				Assert::AreEqual(error, "Incorrect index.");
			}
		}
		TEST_METHOD(Test_Clear_NotEmpty)
		{
			NotEmpty.clear();
			size_t real_size = 0;
			Assert::AreEqual(NotEmpty.get_size(), real_size);
		}
		TEST_METHOD(Test_Clear_Empty)
		{
			Empty.clear();
			size_t real_size = 0;
			Assert::AreEqual(Empty.get_size(), real_size);
		}
		TEST_METHOD(Push_Back_Empty)
		{
			Empty.push_back(5);
			Assert::AreEqual(Empty.at(0), 5);
			Empty.pop_back();
		}
		TEST_METHOD(Push_Front_Empty)
		{
			Empty.push_front(0);
			Assert::AreEqual(Empty.at(0), 0);
		}
	};
	TEST_CLASS(ALgoTest)
	{
	public:
		
		TEST_METHOD(HardTest)
		{
			setlocale(LC_ALL, "Rus");
			Graph Test;
			Test.input("C:\\Users\\fastf\\Desktop\\ПРОГА\\4 семестр\\АиСД\\CourseWork\\CourseWork\\test.txt");
			Assert::AreEqual(Test.EdmondsKarp(), 30);
		}
		TEST_METHOD(EasyTest)
		{
			setlocale(LC_ALL, "Rus");
			Graph Test;
			Test.input("C:\\Users\\fastf\\Desktop\\ПРОГА\\4 семестр\\АиСД\\CourseWork\\CourseWork\\easy.txt");
			Assert::AreEqual(Test.EdmondsKarp(), 5);
		}
	};
}
