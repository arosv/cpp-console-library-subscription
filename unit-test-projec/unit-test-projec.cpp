#include "pch.h"
//#include "CppUnitTest.h"
//#include "../main-project/book_subscription.h"
//#include "../main-project/proces.h"
//
//using namespace Microsoft::VisualStudio::CppUnitTestFramework;
//
//namespace unittestproject
//{
//   
//	book_subscription* build_subscription(int start_chchcc, int start_mm, int start_cc, int finish_chchcc, int finish_mm, int finish_cc)
//	{
//		book_subscription* subscriptions = new book_subscription;
//		subscriptions->start.CHCHCC = start_chchcc;
//		subscriptions->start.MM = start_mm;
//		subscriptions->start.CC = start_cc;
//		subscriptions->finish.CHCHCC = finish_chchcc;
//		subscriptions->finish.MM= finish_mm;
//		subscriptions->finish.CC = finish_cc;
//		return subscriptions;
//	}
//
//	//       
//	void delete_subscription(book_subscription* array[], int size)
//	{
//		for (int i = 0; i < size; i++)
//		{
//			delete array[i];
//		}
//	}
//
//	TEST_CLASS(unittestproject)
//	{
//	public:
//		TEST_METHOD(TestMethod1) //     
//		{
//			book_subscription* subscriptions[3];
//			subscriptions[0] = build_subscription(15, 30, 15, 16, 10, 52); // 5 
//			subscriptions[1] = build_subscription(12, 12, 12, 13, 36, 32); // 7 
//			subscriptions[2] = build_subscription(12, 22, 23, 13, 22, 23); // 4 
//			Assert::AreEqual(674, process(subscriptions, 3));
//			delete_subscription(subscriptions, 3);
//		}
//
//		TEST_METHOD(TestMethod2) //        
//		{
//			book_subscription* subscriptions[3];
//			subscriptions[0] = build_subscription(15, 30, 15, 16, 10, 52); // 5 
//			subscriptions[1] = build_subscription(12, 12, 12, 13, 36, 32); // 7 
//			subscriptions[2] = build_subscription(12, 22, 23, 13, 22, 23); // 4 
//			Assert::AreEqual(19, process(subscriptions, 3));
//			delete_subscription(subscriptions, 3);
//		}
//
//		TEST_METHOD(TestMethod3) //         
//		{
//			book_subscription* subscriptions[3];
//			subscriptions[0] = build_subscription(25, 1, 2015, 4, 2, 2015); // 11 
//			subscriptions[1] = build_subscription(25, 2, 2015, 7, 3, 2015); // 11 
//			subscriptions[2] = build_subscription(25, 4, 2015, 4, 5, 2015); // 10 
//			Assert::AreEqual(11, process(subscriptions, 3));
//			delete_subscription(subscriptions, 3);
//		}
//
//		TEST_METHOD(TestMethod4) //         
//		{
//			book_subscription* subscriptions[3];
//			subscriptions[0] = build_subscription(15, 30, 15, 16, 10, 52); // 5 
//			subscriptions[1] = build_subscription(12, 12, 12, 13, 36, 32); // 7 
//			subscriptions[2] = build_subscription(12, 22, 23, 13, 22, 23); // 4 
//			Assert::AreEqual(12, process(subscriptions, 3));
//			delete_subscription(subscriptions, 3);
//		}
//
//		TEST_METHOD(TestMethod5) //          (2)
//		{
//			book_subscription* subscriptions[3];
//			subscriptions[0] = build_subscription(15, 30, 15, 16, 10, 52); // 5 
//			subscriptions[1] = build_subscription(12, 12, 12, 13, 36, 32); // 7 
//			subscriptions[2] = build_subscription(12, 22, 23, 13, 22, 23); // 4 
//			Assert::AreEqual(11, process(subscriptions, 3));
//			delete_subscription(subscriptions, 3);
//		}
//
//		TEST_METHOD(TestMethod6) //          (2)
//		{
//			book_subscription* subscriptions[3];
//			subscriptions[0] = build_subscription(15, 30, 15, 16, 10, 52); // 5 
//			subscriptions[1] = build_subscription(12, 12, 12, 13, 36, 32); // 7 
//			subscriptions[2] = build_subscription(12, 22, 23, 13, 22, 23); // 4 
//			Assert::AreEqual(12, process(subscriptions, 3));
//			delete_subscription(subscriptions, 3);
//		}
//
//		TEST_METHOD(TestMethod7) //     
//		{
//			book_subscription* subscriptions[3];
//			subscriptions[0] = build_subscription(15, 30, 15, 16, 10, 52); // 5 
//			subscriptions[1] = build_subscription(12, 12, 12, 13, 36, 32); // 7 
//			subscriptions[2] = build_subscription(12, 22, 23, 13, 22, 23); // 4 
//			Assert::AreEqual(70, process(subscriptions, 3));
//			delete_subscription(subscriptions, 3);
//		}
//
//		TEST_METHOD(TestMethod8) //    ,     
//		{
//			book_subscription* subscriptions[3];
//			subscriptions[0] = build_subscription(15, 30, 15, 16, 10, 52); // 5 
//			subscriptions[1] = build_subscription(12, 12, 12, 13, 36, 32); // 7 
//			subscriptions[2] = build_subscription(12, 22, 23, 13, 22, 23); // 4 
//			Assert::AreEqual(71, process(subscriptions, 3));
//			delete_subscription(subscriptions, 3);
//		}
//	};
//}
//

#include "CppUnitTest.h"

#include <iostream>
#include <string>
#include "CppUnitTest.h"
#include "../main-project/book_subscription.h"
#include "../main-project/proces.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

book_subscription* build_subscription(int start_chchcc, int start_mm, int start_cc, int finish_chchcc, int finish_mm, int finish_cc)
	{
		book_subscription* subscriptions = new book_subscription;
		subscriptions->start.CHCHCC = start_chchcc;
		subscriptions->start.MM = start_mm;
		subscriptions->start.CC = start_cc;
		subscriptions->finish.CHCHCC = finish_chchcc;
		subscriptions->finish.MM= finish_mm;
		subscriptions->finish.CC = finish_cc;
		return subscriptions;
	}


void delete_book_subscription(book_subscription* array[], int size) {
    for (int i = 0; i < size; i++) {
        delete array[i];
    }
}


namespace unittestproject
{
    TEST_CLASS(unittestproject)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            book_subscription* subscriptions[3];
            subscriptions[0] = build_subscription(15, 30, 15, 16, 10, 52);
            subscriptions[1] = build_subscription(12, 12, 12, 13, 36, 32);
            subscriptions[2] = build_subscription(12, 22, 23, 13, 22, 23);

            Assert::AreEqual(60, calculate_marafon_duration(subscriptions, 3));
            delete_book_subscription(subscriptions, 3);
        }

       /* TEST_METHOD(TestMethod2)
        {
            session_result* results[3];
            results[0] = build_session_result(1, 12, 2019, "History", 10, "Ivan", "Ivanovich", "Ivanov");
            results[1] = build_session_result(15, 12, 2019, "Math", 9, "Petr", "Petrovich", "Petrov");
            results[2] = build_session_result(31, 12, 2019, "Physics", 8, "Sergey", "Sergeevich", "Sergeev");

            Assert::AreEqual(30, calculate_session_duration(results, 3));
            delete_session_results(results, 3);
        }

        TEST_METHOD(TestMethod3)
        {
            session_result* results[2];
            results[0] = build_session_result(25, 12, 2019, "Biology", 6, "Anna", "Anatolyevna", "Anisimova");
            results[1] = build_session_result(5, 1, 2020, "Chemistry", 7, "Elena", "Evgenevna", "Egorova");

            Assert::AreEqual(11, calculate_session_duration(results, 2));
            delete_session_results(results, 2);
        }

        TEST_METHOD(TestMethod4)
        {
            session_result* results[3];
            results[0] = build_session_result(1, 1, 2019, "Math", 9, "Ivan", "Ivanovich", "Ivanov");
            results[1] = build_session_result(1, 1, 2019, "Physics", 8, "Petr", "Petrovich", "Petrov");
            results[2] = build_session_result(1, 1, 2019, "Chemistry", 7, "Sergey", "Sergeevich", "Sergeev");

            Assert::AreEqual(0, calculate_session_duration(results, 3));
            delete_session_results(results, 3);
        }
        TEST_METHOD(TestMethod5)
        {
            session_result* results[1];
            results[0] = build_session_result(1, 1, 2021, "Physics", 10, "Vladimir", "Vladimirovich", "Volkov");

            Assert::AreEqual(0, calculate_session_duration(results, 1));
            delete_session_results(results, 1);
        }*/
    };
}

