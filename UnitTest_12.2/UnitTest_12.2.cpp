#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12.2.rec/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest122
{
	TEST_CLASS(UnitTest122)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            Elem* first = NULL;
            Elem* last = NULL;
            Elem* K;

            int index = 4, x = 6;
            Enqueue(first, last, index, x);

            K = first;
            Print(K, 0, x, index);

            K = first;
            int z = 6;
            Process(K, z, 0);
            K = first;
            int l = K->inf;
            Assert::AreEqual(l, 10);
		}
	};
}
