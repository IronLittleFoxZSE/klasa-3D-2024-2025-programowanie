#include <iostream>

/*

DO-WHILE
* Napisz program, który policzy sumę cyfr podanej przez użytkownika liczby.
* Program wyświetlający na ekranie kwadraty liczb od 1 do 10 (np. 1, 4, 9, 16 itd.) dopóki suma tych kwadratów nie przekroczy 1000.

WHILE
* Miasto T. ma obecnie 100 tys. mieszkańców, ale jego populacja rośnie co roku o 3% rocznie. Miasto B. ma 300 tys. mieszkańców i ta liczba rośnie w tempie 2% na rok. Wykonaj symulację prezentującą liczbę mieszkańców w obu miastach i zatrzymującą się, gdy liczba mieszkańców miasta T. przekroczy liczbę z miasta B.
*
* Program sprawdzający czy podana liczba jest liczbą doskonałą (czyli taką, której suma dzielników (z wyłączeniem samej siebie) jest równa danej liczbie, np. 6 jest liczbą doskonałą, ponieważ 1 + 2 + 3 = 6).

FOR
* Program wyświetlający na ekranie kolejne liczby naturalne od 1 do 10
* Program obliczający sumę liczb od 1 do 100
* Program wyświetlający na ekranie kwadraty liczb od 1 do 10 (np. 1, 4, 9, 16 itd.)
* Program obliczający n!.
* Program wyświetlający na ekranie silnie z liczb od 1 do 10 (np. 1!, 2!, 3!, 4! itd.)
* Program wyświetlający na ekranie tabliczkę mnożenia od 1 do 9 (np. 1x1=1, 1x2=2, 1x3=3 itd.).
* Program wyświetlający na ekranie wszystkie liczby podzielne przez 3 z zakresu od 1 do 100
* Program obliczający sumę kwadratów liczb od 1 do 10
*
* Program, kóry wyświetli poniższe cztery zwory:
	****       54321        121212        122333
	***        65432        212121        223334444
	**         76543        121212        333444455555
	*          87654        212121        444455555666666

*

*/

//Napisz program, który pobiera od uzytkownika liczbę dopóki będzie ona różna od zera
void task1()
{
	int number;
	do
	{
		std::cout << "Podaj liczbę\n";
		std::cin >> number;
	} while (number != 0);
}

//Napisz program, który obliczy NWD dwóch liczb
void task2()
{
	int a, b;
	std::cout << "Podaj a\n";
	std::cin >> a;
	std::cout << "Podaj b\n";
	std::cin >> b;

	/*if (b != 0)
	{
		int tmp = b;
		b = a % b;
		a = tmp;
		if (b != 0)
		{
			int tmp = b;
			b = a % b;
			a = tmp;
			if (b != 0)
			{
				int tmp = b;
				b = a % b;
				a = tmp;
				if (b != 0)
				{
					int tmp = b;
					b = a % b;
					a = tmp;
					//....
				}
			}
		}
	}*/

	while (b != 0)
	{
		int tmp = b;
		b = a % b;
		a = tmp;
	}

	/*for (; b != 0; )
	{
		int tmp = b;
		b = a % b;
		a = tmp;
	}*/

	std::cout << "NWD = " << a << "\n";
}

//Napisz program który wyświetli na ekranie kolejne liczby naturalne od 1 do n
void task3()
{
	int number;
	std::cout << "Podaj liczbę\n";
	std::cin >> number;

	if (number > 0)
	{
		std::cout << "1, ";
		if (number > 1)
		{
			std::cout << "2, ";
			if (number > 2)
			{
				std::cout << "3, ";
				if (number > 3)
				{
					std::cout << "4, ";
					if (number > 4)
					{
						std::cout << "5, ";
						if (number > 5)
						{
							std::cout << "6, ";
							//dalej kolejne
						}
					}
				}
			}
		}
	}

	int i = 0;
	while (number > i)
	{
		std::cout << (i + 1) << ", ";
		i++;
	}
	std::cout << "\n";

	for (int i = 0; number > i; i++)
	{
		std::cout << (i + 1) << ", ";
	}
	std::cout << "\n";
}

//Napisz program, który wylosuje liczbę a uzytkownik ma zgodnąć ją.
void task4()
{
	srand(time(NULL));

	int secretNumber = rand() % 10;

	/*std::cout << "Zgadnij liczbe:\n";
	int number;
	std::cin >> number;
	if (number != secretNumber)
	{
		std::cout << "Zgadnij liczbe:\n";
		int number;
		std::cin >> number;
		if (number != secretNumber)
		{
			std::cout << "Zgadnij liczbe:\n";
			int number;
			std::cin >> number;
			if (number != secretNumber)
			{
				std::cout << "Zgadnij liczbe:\n";
				int number;
				std::cin >> number;
				if (number != secretNumber)
					....
			}
		}
	}*/

	int number;
	do
	{
		std::cout << "Zgadnij liczbe:\n";
		std::cin >> number;
	} while (number != secretNumber);
	std::cout << "Gratulacje\n";
}

//Program obliczający sumę liczb od 1 do 100
void task5()
{
	int sum = 0;
	for (int i = 1; i <= 100; i++)
	{
		sum = sum + i;
	}

	std::cout << "Suma od 1  do 100 wynosi " << sum << "\n";
}

//Program wyświetlający na ekranie ciąg Fibonacciego do 20 elementu (ciąg Fibonacciego to ciąg gdzie każdy element jest sumą dwóch poprzednich, np. 0, 1, 1, 2, 3, 5, 8, 13 itd.)
void task6()
{
	std::cout << "0 , 1, ";

	int fib2 = 0;
	int fib1 = 1;
	for (int i = 0; i < 18; i++)
	{
		int fib = fib2 + fib1;
		std::cout << fib << ", ";
		fib2 = fib1;
		fib1 = fib;
	}
}

/*
* Program, kóry wyświetli poniższe cztery zwory:
	****       54321        121212        122333
	***        65432        212121        223334444
	**         76543        121212        333444455555
	*          87654        212121        444455555666666
*/
void task7()
{
	int numberOfLines = 5;

	//pierwsza
	for (int lineNumber = 0; lineNumber < numberOfLines; lineNumber++)
	{
		for (int numberOfStar = 0; numberOfStar < numberOfLines - lineNumber; numberOfStar++)
		{
			std::cout << "*";
		}
		std::cout << "\n";
	}

	for (int lineNumber = 0; lineNumber < numberOfLines; lineNumber++)
	{
		for (int numberOfStar = 0; numberOfStar <= lineNumber; numberOfStar++)
		{
			std::cout << "*";
		}
		std::cout << "\n";
	}

	//druga
	for (int lineNumber = 0; lineNumber < numberOfLines; lineNumber++)
	{
		for (int number = lineNumber + 5; number > lineNumber; number--)
		{
			std::cout << number;
		}
		std::cout << "\n";
	}

	//trzecia
	for (int lineNumber = 0; lineNumber < numberOfLines; lineNumber++)
	{
		for (int number = 0; number < 6; number++)
		{
			std::cout << (number + lineNumber) % 2 + 1;
		}
		std::cout << "\n";
	}

	//czwarta
	for (int lineNumber = 0; lineNumber < numberOfLines; lineNumber++)
	{
		for (int number = lineNumber + 1; number <= lineNumber + 3; number++)
		{
			for (int i = 0; i < number; i++)
				std::cout << number;
		}
		std::cout << "\n";
	}
}

//Napisz program, który poprosi użytkownika o wprowadzenie dowolnej liczby całkowitej. Następnie program powinien obliczyć i wyświetlić liczbę cyfr.
void task8()
{
	int number = 11;

	//wersja 1
	int howManyDigits = 1;
	int upperRange = 10;
	number = abs(number);
	while (number > upperRange)
	{
		howManyDigits++;
		upperRange *= 10;
	}
	std::cout << howManyDigits << "\n";

	//wersja 2
	howManyDigits = 1;
	int tmpNumber = abs(number);
	while (tmpNumber > 10)
	{
		tmpNumber /= 10;
		howManyDigits++;
	}

	std::cout << howManyDigits << "\n";

	//wersja 3 ile cyfr binarnie
	howManyDigits = 1;
	tmpNumber = abs(number);
	while (tmpNumber > 1)
	{
		tmpNumber >>= 1;
		howManyDigits++;
	}

	std::cout << howManyDigits << "\n";
}

//Oblicz sumę szeregu 1/1^2 + 1/2^2 + 1/3^2 + ... +1/n^2. Jeżeli się nie pomylisz, to dla odpowiednio dużej wartości n po przemnożeniu jej przez 6 i spierwiastkowaniu powinieneś otrzymać wartość liczby π (suma szeregu jest równa π2/6). Zwróć uwagę, że pierwsza wartość indeksu to 1, a nie 0. Dokładność obliczeń można sprawdzić porównując z wartością odczytaną z własności Math.PI.
void task9()
{
	double sum = 0;
	int n = 2;
	/*if (n > 1)
	{
		sum = sum + 1 / (1.0 * 1.0);
		if (n > 2)
		{
			sum = sum + 1 / (2.0 * 2.0);
			if (n > 3)
			{
				sum = sum + 1 / (3.0 * 3.0);
				if (n > 4)
				{
					sum = sum + 1 / (4.0 * 4.0);
					//....
				}
			}
		}
	}*/

	double i = 1;
	while (n > i)
	{
		sum = sum + 1 / (i * i);
		i++;
	}

	std::cout << "Suma " << sum << "\n";
}

int main()
{
	task8();
}