#include <iostream>
/*
Operatory porównania:
== - równości
!= - różności
>
<
>=
<=

*/

/*
1.
2. Program sprawdzający czy podana liczba jest dodatnia, ujemna czy równa zero
3. Program sprawdzający czy podany rok jest rokiem przestępnym
4. Program wyświetlający odpowiedni komunikat w zależności od podanej oceny (np. "bardzo dobry" dla oceny 5, "dobry" dla oceny 4 itd.)
5. Program sprawdzający czy podane hasło jest poprawne (np. jeśli hasło jest "abc123", program powinien wyświetlić "hasło poprawne", jeśli jest inne, powinien wyświetlić "hasło niepoprawne").
6. Program sprawdzający czy podana data jest poprawna (np. sprawdzając, czy dzień jest z zakresu od 1 do 31, miesiąc od 1 do 12 itd.)
7. Program wyświetlający odpowiedni komunikat w zależności od podanej temperatury (np. "ciepło" dla temperatury powyżej 20 stopni Celsjusza, "chłodno" dla temperatury poniżej 10 stopni Celsjusza itd.)
8. Program sprawdzjący czy podana liczba jest z przediału <1;15)
9. Program sprawdzający czy osoba jest pełnoletnia.
10. Program, który sprawdzi czy z podanych długości boków można zrobić trójkąt.

11. Napisz program, który będzie działać jako prosty kalkulator matematyczny, umożliwiając użytkownikowi wybór operacji (dodawanie, odejmowanie, mnożenie, dzielenie) i wprowadzanie liczb do obliczeń.
12. Napisz program, który wczyta numer miesiąca i wyświetli jego słowny odpowiednik.
13. Napisz program, który na podstawie współczynników równania kwadratowego (a, b, c) sprawdzi, czy to równanie ma rozwiązania rzeczywiste, i jeśli tak, to je obliczy.

*/


//Napisz funkcję, która podzieli dwie liczby.
void task1()
{
	int firstNumber, secondNumber;

	std::cout << "Podaj pierwszą liczbę:\n";
	std::cin >> firstNumber;
	std::cout << "Podaj drugą liczbę (byle nie zero):\n";
	std::cin >> secondNumber;

	if (secondNumber != 0)
	{
		double quotient = firstNumber / secondNumber;
		std::cout << "Wynik dzielenia: " << quotient << "\n";
	}
	else
	{
		std::cout << "Dzielenie przez zero!!!\n";
	}
}

//Program sprawdzający czy podana liczba jest parzysta czy nieparzysta
void task2()
{

}

//Program sprawdzający czy podana data jest poprawna (np. sprawdzając, czy dzień jest z zakresu od 1 do 31, miesiąc od 1 do 12 itd.)
void task3()
{
	int day, month, year;
	std::cout << "Podaj dzień\n";
	std::cin >> day;
	std::cout << "Podaj miesiąc\n";
	std::cin >> month;
	std::cout << "Podaj rok\n";
	std::cin >> year;

	bool isLeapYear = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

	if (day < 1
		|| day > 31

		|| month < 1
		|| month > 12

		|| (day == 31
			&& (month == 4
				|| month == 6
				|| month == 9
				|| month == 11))

		|| (month == 2
			&& day > 29)

		|| (month == 2
			&& day == 29
			&& !isLeapYear)
		)
	{
		std::cout << "Nie istnieje taka data\n";
		return;
	}

	std::cout << "Poprawna data\n";
}

void task4()
{
	int number;
	std::cout << "Podaj liczbe\n";
	std::cin >> number;

	if (number == 1)
	{
		std::cout << "Jeden\n";
	}
	else if (number == 2
		|| number == 85)
	{
		std::cout << "Dwa\n";
		//number = number * 2;
	}
	else if (number == 5)
	{
		std::cout << "Pięć\n";
		//number = number / 2;
	}
	else
	{
		std::cout << "Inna opcja\n";
	}

	switch (number)
	{
	case 1:
		std::cout << "Jeden\n";
		break;
	case 2:
	case 85:
		std::cout << "Dwa\n";
		//number = number * 2;
		break;
	case 5:
		std::cout << "Pięć\n";
		//number = number / 2;
		break;
	default:
		std::cout << "Inna opcja\n";
	}


}

int main()
{
	setlocale(LC_CTYPE, "polish");

	//task1();
	task3();
}