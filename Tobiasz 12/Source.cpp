#include <iostream>
#include <stack>
#include <cmath>
#include <string>

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

int char_to_int(char c)
{
	return c - 48;
}

void bin_na_dzie(string str)
{
	int suma = 0;
	int potega = 1;

	// 10110011

	for (int i = str.size() - 1; i >= 0; --i)
	{
		suma += char_to_int(str[i]) * potega;
		potega *= 2;
	}

	cout << suma << endl;
}

int main()
{
	stack<int> stos;

	string str;

	cin >> str;

	bin_na_dzie(str);
}