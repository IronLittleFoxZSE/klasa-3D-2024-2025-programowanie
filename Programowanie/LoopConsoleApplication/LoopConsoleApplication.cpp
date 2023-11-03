#include <iostream>

/*

DO-WHILE
* Napisz program, który policzy sumę cyfr podanej przez użytkownika liczby.
* Program wyświetlający na ekranie kwadraty liczb od 1 do 10 (np. 1, 4, 9, 16 itd.) dopóki suma tych kwadratów nie przekroczy 1000.
 
WHILE
* Miasto T. ma obecnie 100 tys. mieszkańców, ale jego populacja rośnie co roku o 3% rocznie. Miasto B. ma 300 tys. mieszkańców i ta liczba rośnie w tempie 2% na rok. Wykonaj symulację prezentującą liczbę mieszkańców w obu miastach i zatrzymującą się, gdy liczba mieszkańców miasta T. przekroczy liczbę z miasta B.
* Napisz program, który poprosi użytkownika o wprowadzenie dowolnej liczby całkowitej. Następnie program powinien obliczyć i wyświetlić liczbę cyfr.
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

* Oblicz sumę szeregu 1/1^2 + 1/2^2 + 1/3^2 + ... +1/n^2. Jeżeli się nie pomylisz, to dla odpowiednio dużej wartości n po przemnożeniu jej przez 6 i spierwiastkowaniu powinieneś otrzymać wartość liczby π (suma szeregu jest równa π2/6). Zwróć uwagę, że pierwsza wartość indeksu to 1, a nie 0. Dokładność obliczeń można sprawdzić porównując z wartością odczytaną z własności Math.PI.

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

int main()
{
	task6();
}