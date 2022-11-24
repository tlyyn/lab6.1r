#include <iostream>
#include <time.h>
#include <Windows.h>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i)
{
	if (i < size)
	{
		a[i] = Low + rand() % (High - Low + 1);
		Create(a, size, Low, High, i + 1);
	}
}

void Print(int* a, const int size, int i)
{
	if (i < 1)
		cout << "Значення масиву : ";
	if (i < size)
	{
		cout << a[i] << " ";
		Print(a, size, i + 1);
	}
	else
		cout << endl;
}

int Num(int* a, const int size, int i, int n)
{
	if (i < 1)
		cout << "Значення масиву, які підходять критеріям : ";
	if (i < size)
	{
		if (a[i] > 0 || (i % 2) == 0)
		{
			n++;
			cout << a[i] << " ";
		}
		Num(a, size, i + 1, n);
	}
	else
	{
		cout << endl;
		return n;
	}
}

int Sum(int* a, const int size, int i, int s)
{
	if (i < size)
	{
		if (a[i] > 0 || (i % 2) == 0)
			s += a[i];
		Sum(a, size, i + 1, s);
	}
	else
		return s;
}

int* Zero(int* a, const int size, int i)
{
	if (i < size)
	{
		if (a[i] > 0 || (i % 2) == 0)
			a[i] = 0;
		Zero(a, size, i + 1);
	}
	else
		return a;
}

int main()
{
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	
	srand((unsigned)time(NULL));

	const int n = 25;
	int p[n], Low = -14, High = 10;

	Create(p, n, Low, High, 0);
	Print(p, n, 0);

	cout << "К-сть значень, які підходять критеріям : " << Num(p, n, 0, 0) << endl;
	cout << "Сума значень, які	 підходять критеріям : " << Sum(p, n, 0, 0) << endl;

	Print(Zero(p, n, 0), n, 0);

	return 0;
}