#include "stdafx.h"
#include "CppUnitTest.h"
int __declspec(dllimport) start_server();
bool __declspec(dllimport)  isPrime(unsigned int n);
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_Server
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			int result = start_server();
			Assert::AreEqual(0, result, L"server successfully started", LINE_INFO());
		}
		TEST_METHOD(TestMethod2)
		{
			bool result = isPrime(149);
			Assert::AreEqual(true, result, L"prime number computation test1 passed", LINE_INFO());
		}
		TEST_METHOD(TestMethod3)
		{
			bool result = isPrime(223);
			Assert::AreEqual(true, result, L"prime number computation test2 passed", LINE_INFO());
		}
		TEST_METHOD(TestMethod4)
		{
			bool result = isPrime(269);
			Assert::AreEqual(true, result, L"prime number computation test3 passed", LINE_INFO());
		}

	};
}

