#include "stdafx.h"
#include "CppUnitTest.h"
int __declspec(dllimport) start_server();
bool __declspec(dllimport)  isPrime(int n);
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_Server
{		
	TEST_CLASS(UnitTest1)
	{
	public:
#if(0)
		TEST_METHOD(TestMethod1)
		{
			int result = start_server();
			Assert::AreEqual(0, result, L"message", LINE_INFO());
		}
#endif
		TEST_METHOD(TestMethod1)
		{
			bool result = isPrime(149);
			Assert::AreEqual(true, result, L"message", LINE_INFO());
		}
		TEST_METHOD(TestMethod2)
		{
			bool result = isPrime(223);
			Assert::AreEqual(true, result, L"message", LINE_INFO());
		}
		TEST_METHOD(TestMethod3)
		{
			bool result = isPrime(269);
			Assert::AreEqual(true, result, L"message", LINE_INFO());
		}

	};
}

