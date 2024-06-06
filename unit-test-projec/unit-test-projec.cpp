#include "pch.h"
#include "CppUnitTest.h"
#include "../main-project/book_subscription.h"
#include "../main-project/proces.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
#include "pch.h"
#include "CppUnitTest.h"

#include "../main-project/book_subscription.h"
#include "../main-project/processing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
	//        
	//             ,
	//   ,     
	book_subscription* build_subscription(int start_chchcc, int start_mm, int start_cc, int finish_chchcc, int finish_mm, int finish_cc)
	{
		book_subscription* subscription = new book_subscription;
		subscription->start.CHCHCC = start_chchcc;
		subscription->start.MM = start_mm;
		subscription->start.CC = start_cc;
		subscription->finish.CHCHCC = finish_chchcc;
		subscription->finish.MM= finish_mm;
		subscription->finish.CC = finish_cc;
		return subscription;
	}

	//       
	void delete_subscription(book_subscription* array[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			delete array[i];
		}
	}

	TEST_CLASS(unittestproject)
	{
	public:
		TEST_METHOD(TestMethod1) //     
		{
			book_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(1, 1, 2015, 5, 1, 2015); // 5 
			subscriptions[1] = build_subscription(2, 1, 2015, 8, 1, 2015); // 7 
			subscriptions[2] = build_subscription(3, 1, 2015, 6, 1, 2015); // 4 
			Assert::AreEqual(7, proces(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}

		TEST_METHOD(TestMethod2) //        
		{
			book_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(20, 1, 2015, 3, 2, 2015); // 15 
			subscriptions[1] = build_subscription(22, 1, 2015, 9, 2, 2015); // 19 
			subscriptions[2] = build_subscription(19, 1, 2015, 1, 2, 2015); // 14 
			Assert::AreEqual(19, process(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}

		TEST_METHOD(TestMethod3) //         
		{
			book_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(25, 1, 2015, 4, 2, 2015); // 11 
			subscriptions[1] = build_subscription(25, 2, 2015, 7, 3, 2015); // 11 
			subscriptions[2] = build_subscription(25, 4, 2015, 4, 5, 2015); // 10 
			Assert::AreEqual(11, process(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}

		TEST_METHOD(TestMethod4) //         
		{
			book_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(25, 1, 2016, 4, 2, 2016); // 11 
			subscriptions[1] = build_subscription(25, 2, 2016, 7, 3, 2016); // 12 
			subscriptions[2] = build_subscription(25, 4, 2016, 4, 5, 2016); // 10 
			Assert::AreEqual(12, process(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}

		TEST_METHOD(TestMethod5) //          (2)
		{
			book_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(25, 1, 1900, 4, 2, 1900); // 11 
			subscriptions[1] = build_subscription(25, 2, 1900, 7, 3, 1900); // 11 
			subscriptions[2] = build_subscription(25, 4, 1900, 4, 5, 1900); // 10 
			Assert::AreEqual(11, process(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}

		TEST_METHOD(TestMethod6) //          (2)
		{
			book_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(25, 1, 2000, 4, 2, 2000); // 11 
			subscriptions[1] = build_subscription(25, 2, 2000, 7, 3, 2000); // 12 
			subscriptions[2] = build_subscription(25, 4, 2000, 4, 5, 2000); // 10 
			Assert::AreEqual(12, process(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}

		TEST_METHOD(TestMethod7) //     
		{
			book_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(25, 12, 2014, 4, 1, 2015); // 11 
			subscriptions[1] = build_subscription(25, 12, 2014, 7, 2, 2015); // 45 
			subscriptions[2] = build_subscription(25, 12, 2014, 4, 3, 2015); // 70 
			Assert::AreEqual(70, process(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}

		TEST_METHOD(TestMethod8) //    ,     
		{
			book_subscription* subscriptions[3];
			subscriptions[0] = build_subscription(25, 12, 2015, 4, 1, 2016); // 11 
			subscriptions[1] = build_subscription(25, 12, 2015, 7, 2, 2016); // 45 
			subscriptions[2] = build_subscription(25, 12, 2015, 4, 3, 2016); // 71 
			Assert::AreEqual(71, process(subscriptions, 3));
			delete_subscription(subscriptions, 3);
		}
	};
}

