#include "pch.h"
#include "CppUnitTest.h"
#include "../Project6.1r/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void Test(int* a, int* p, const int size, int i, int n, int s)
{
	if (i < size)
	{
		if (a[i] > 0 || (i % 2) == 0)
		{
			n++;
			s += p[i];
			a[i] = 0;
		}
		Assert::AreEqual(a[i], p[i]);
		Test(a, p, size, i + 1, n, s);
	}
	else
	{
		Assert::AreEqual(n, Num(p, size, 0, 0));
		Assert::AreEqual(s, Sum(p, size, 0, 0));
	}
}

namespace UnitTestLab061Recur
{
	TEST_CLASS(UnitTestLab061Recur)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			const int n = 25;
			int p[n], Low = -14, High = 10;

			Create(p, n, Low, High, 0);

			int* a = Zero(p, n, 0);

			Test(a, p, n, 0, 0, 0);
		}
	};
}