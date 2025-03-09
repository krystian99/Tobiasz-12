#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;
stack<int> stos_liczb;
stack<int> stos_operatorow;

// 1000 3000000 +

int char_to_int(char c)
{
	return c - 48;
}

int string_to_int(string tmp)
{
	// 1000

	int potega = 1;
	int suma = 0;

	for (int i = tmp.size() - 1; i >= 0; i--)
	{
		int l = char_to_int(tmp[i]);

		suma += l * potega;
		potega *= 10;
	}

	return suma;
}

// 1000 3000000 +
// + -> wniosek: musza byc dwie liczby na poczatku

bool czy_cyfra(char c)
{
	return c >= 48 && c <= 57;
}

bool czy_operator(char c)
{
	switch (c)
	{
	case '+': return true;
	case '-': return true;
	case '*': return true;
	case '/': return true;
	case '^': return true;
	default: return false;
	}
}

int pobierzZeStos(stack<int> & stos)
{
	int tmp = stos.top();
	stos.pop();

	return tmp;
}

// (10 + 53) ^ 2 / 10
// 
// I: 10^2 + 3 * 4 / 6 = 102
// I.2: 134 - 20/5 + 234 / 2 - 2 * 3 * 4 / 6 = 
// II: (10 / 5) * (2 - 1) - 15 / 3
// III: [(10 / 5) * (2 - 1) - 15 / 3]^2

// 3 5 *
// 1000 3 *
void notacja(string str)
{
	string tmp;

	// petla g³ówna -> algorytm leci po wszystkich znakach w calej linii
	for (int i = 0; i <= str.size(); ++i)
	{
		// I: 1000 30 *
		// 1) tmp.empty() = true, czy_cyfra(str[i]) = true, str[i] = 1
		// 2) tmp.empty() = false, 10

		// II: 1000 30 3 * +
		if (tmp.empty()) // jezeli wczytalem poprzednia liczbe badz poprzedni operator, napotkalem spacje badz zaczynam od poczatku
		{
			// 1000 30 *
			if (czy_cyfra(str[i]))
			{
				// algorytm leci po wszystkich cyfrach dopoki nie napotka spacji
				for (int j = i; j <= str.size(); ++j)
				{
					if (str[j] == ' ')
					{
						i = j; // i = 4
						break;
					}
					tmp += str[j];
				}
			}
			else // jest operatorem
			{
				char c = str[i];
				int a = pobierzZeStos();
				int b = pobierzZeStos();

				int wynik;

				switch (c)
				{
				case '+': wynik = a + b; break;
				case '-': wynik = a - b; break;
				case '*': wynik = a * b; break;
				case '/': wynik = a / b; break;
				case '^': wynik = pow(a, b); break;
				}
				
				stos.push(wynik);

				i++;

				continue;
			}
		}
		if (str[i] == ' ')
		{
			int l = string_to_int(tmp);
			stos.push(l);
			tmp.clear();
			continue;
		}
		/*else if ()
		else
			tmp += str[i];*/
	}

	cout << "Wynik to: " << stos.top() << endl;

	stos.pop();

	/*while (i <= str.size())
	{
		if (str[i] == ' ')
		{
			tmp.clear();

			continue;
		}
		else
	}*/


}

// test 1: 2 + 4 + 3
// test 2: (2 + 4) * 3 -> wszystkie elementy po spacji -> ( 2 + 4 ) * 3 -> ograniczamy siê do sprawdzania czy wczytany znak to liczba czy operator

int wynikW(string str)
{
	// wersje etapowo: ³atwy(test1), œredni, trudny

	// wersja 1: bez nawiasów
	for (int i = 0; i < str.size(); ++i)
	{
		// akcja1, warunek -> stos liczb: 2, stos operatorow: nic -> dodawaj dalej bo brak dwóch liczb na stosie i brak operatora
		if ()
		{

		}

		// akcja2, warunek-> stos liczb: 2, stos operatorow: + -> dodawaj dalej bo brak dwóch liczb na stosie(mamy operator na stosie)
		if ()
		{

		}
		// akcja3, warunek-> stos liczb: 2, 4, stos operatorow: + -> zdejmij ze stosu i wypisz kolejno liczby i operatory
		if ()
		{
			cout << pobierzZeStos(stos_liczb) << pobierzZeStos(stos_liczb) << pobierzZeStos(stos_operatorow);
		}

	}
}

int main()
{
	int x;

	string str;
	getline(cin, str); // wyrazenie w postaci


	//notacja(str);
}