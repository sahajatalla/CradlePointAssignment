#include "stdafx.h"
#include "CppUnitTest.h"
int __declspec(dllimport) excercise_server( char *host);
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_Client
{		
	TEST_CLASS(UnitTest1)
	{
	public:
#if(0)
		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
			int result = excercise_server("localhost");
				Assert::AreEqual(0, result, L"message", LINE_INFO());

		}
#endif

	};
}