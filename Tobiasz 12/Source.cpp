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
	int potega = 1; // 2^0

	// 10110011

	for (int i = str.size() - 1; i >= 0; --i)
	{
		suma += char_to_int(str[i]) * potega;
		potega *= 2;
	}

	cout << suma << endl;
}

void hex_to_dec(string str)
{
	//D6
	int suma = 0;
	int potega = 1; // 16^0

	int znak;

	for (int i = str.size() - 1; i >= 0; --i)
	{
		if (str[i] >= 65 && str[i] <= 70)
			znak = char_to_int(str[i]) - 7;
		else
			znak = char_to_int(str[i]);

		suma += znak * potega;
		potega *= 16;
	}

	cout << suma << endl;
}
void oct_na_dzie(string str)
{
	int suma=0;
	int potega=1;

	for(int i = str.size() - 1; i >= 0; --i)
	{
		suma+= char_to_int(str[i])* potega;
		potega*= 8;
	}
	cout<< suma<< endl;
}


int main()
{
	stack<int> stos;

	string str;

	cin >> str;

	//bin_na_dzie(str);
	//hex_to_dec(str);
	oct_na_dzie(str);
}