#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

stack<int> stos;

void clear_stack()
{
	while (!stos.empty())
		stos.pop();
}

void zdejmij_zeStos_wypisz()
{

}

void na_binarny(int l)
{
	clear_stack();

	while (l != 0)
	{
		int r = l % 2;
		stos.push(r);

		l /= 2;
	}

	while (!stos.empty())
	{
		cout << stos.top();
		stos.pop();
	}

	cout << endl;
}

void na_osmekowy(int l)
{
	clear_stack();

	while (l != 0)
	{
		int r = l % 8;
		stos.push(r);

		l /= 8;
	}

	while (!stos.empty())
	{
		cout << stos.top();
		stos.pop();
	}

	cout << endl;
}

void na_szesnastkowy(int l)
{
	clear_stack();

	while (l != 0 )
	{
		int r = l % 16;
		stos.push(r);

		l /= 16;
        

	}

	while (!stos.empty())
	{
		int x = stos.top();

		if (x == 10)
			cout << 'A';
		else if (x == 11)
			cout << 'B';
		else if (x == 12)
			cout << 'C';
		else if (x == 13)
			cout << 'D';
		else if (x == 14)
			cout << 'E';
		else if (x == 15)
			cout << 'F';
		else
			cout << stos.top();

		stos.pop();
	}

	cout << endl;
}

void bin_na_dzie(int z)
{
	int suma = 0;
	int potega = 1;

	while (z != 0)
	{
		int r = z % 10;
		suma += r * potega;

		potega *= 2;
		z /= 10;
	}

	cout << suma << endl;
}

int main()
{
	stack<int> stos;

	int l,z;

	cin >> l;

	bin_na_dzie(l);
}