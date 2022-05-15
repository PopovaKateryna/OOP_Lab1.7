#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\KATERYNA\Desktop\OOP\Lab1.7\Lab1.7\Lab1.7\Bill.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Bill B1;
			B1.SetSurname("Popova");
			Assert::AreEqual("Popova", B1.GetSurname().c_str());
		}
	};
}
