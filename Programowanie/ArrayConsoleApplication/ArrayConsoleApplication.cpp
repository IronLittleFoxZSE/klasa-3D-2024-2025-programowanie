#include <iostream>

//Napisz program, który wczyta 5 liczb a następnie je wyświetli na konsoli
//w odwrotnej kolejności
void task1()
{
	const int SIZE_OF_ARRAY = 5;
	int numbers[SIZE_OF_ARRAY];

	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		std::cout << "Podaj liczbe\n";
		std::cin >> numbers[i];
	}

	for (int i = SIZE_OF_ARRAY - 1; i >= 0; i--)
		std::cout << "Podana liczba " << numbers[i] << "\n";
}

//Napisz program, który uzupełni tablicę liczbami losowymi 
//a następnie znajdzie minimum oraz maksimum.
void task2()
{
	const int UPPER_RANGE = 100;
	const int LOWER_RANGE = 5;

	const int SIZE_OF_ARRAY = 100;
	int numbers[SIZE_OF_ARRAY];

	srand(time(NULL));

	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		numbers[i] = rand() % (UPPER_RANGE - LOWER_RANGE + 1) + LOWER_RANGE;
	}

	for (int i = 0; i < SIZE_OF_ARRAY; i++)
		std::cout << numbers[i] << ", ";
	std::cout << "\n";

	//szukanie maksimum
	int max = numbers[0];
	for (int i = 1; i < SIZE_OF_ARRAY; i++)
		if (numbers[i] > max)
			max = numbers[i];

	//szukanie min
	int min = numbers[0];
	for (int i = 1; i < SIZE_OF_ARRAY; i++)
		if (numbers[i] < min)
			min = numbers[i];

	std::cout << "Największa to: " << max << "\n";
	std::cout << "Najmniejsza to: " << min << "\n";
}

//Napisz program obliczający średnią arytmetyczną elementów w tablicy liczb całkowitych.
void task3()
{
	const int UPPER_RANGE = 10;
	const int LOWER_RANGE = 5;

	const int SIZE_OF_ARRAY = 3;
	int numbers[SIZE_OF_ARRAY];

	srand(time(NULL));

	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		numbers[i] = rand() % (UPPER_RANGE - LOWER_RANGE + 1) + LOWER_RANGE;
	}

	for (int i = 0; i < SIZE_OF_ARRAY; i++)
		std::cout << numbers[i] << ", ";
	std::cout << "\n";

	int sum = 0;
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		sum = sum + numbers[i];
	}

	double average = sum * 1.0 / SIZE_OF_ARRAY;
	std::cout << "Średnia liczb to " << average << "\n";
}

//Napisz program, która zlicza ilość wystąpień danej liczby w tablicy.
void task4()
{
	const int LOWER_RANGE = -12000;
	const int UPPER_RANGE = 10000;

	const int SIZE_OF_ARRAY = 5;
	int numbers[SIZE_OF_ARRAY];

	srand(time(NULL));

	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		numbers[i] = rand() % (UPPER_RANGE - LOWER_RANGE + 1) + LOWER_RANGE;
	}

	for (int i = 0; i < SIZE_OF_ARRAY; i++)
		std::cout << numbers[i] << ", ";
	std::cout << "\n";

	//wersja 1
	for (int numberFromRange = LOWER_RANGE; numberFromRange <= UPPER_RANGE; numberFromRange++)
	{
		int numberOfOccurrences = 0;
		for (int j = 0; j < SIZE_OF_ARRAY; j++)
		{
			if (numbers[j] == numberFromRange)
				numberOfOccurrences++;
		}
		if (numberOfOccurrences != 0)
			std::cout << "liczba " << numberFromRange << " wystapiła " << numberOfOccurrences << " razy\n";
	}

	//wersja 2
	std::cout << "\nWersja 2\n";
	int numbersOfOccurrences[UPPER_RANGE - LOWER_RANGE + 1];
	for (int i = 0; i < UPPER_RANGE - LOWER_RANGE + 1; i++)
	{
		numbersOfOccurrences[i] = 0;
	}

	for (int j = 0; j < SIZE_OF_ARRAY; j++)
	{
		numbersOfOccurrences[numbers[j] - LOWER_RANGE]++;
	}

	for (int i = 0; i < UPPER_RANGE - LOWER_RANGE + 1; i++)
	{
		if (numbersOfOccurrences[i] != 0)
			std::cout << "liczba " << i + LOWER_RANGE << " wystapiła " << numbersOfOccurrences[i] << " razy\n";
	}
}

//Napisz program, który wyznaczy wszystkie liczby pierwsze od 2 do zadeklarowanego zakresu. Metoda sito Eratostenesa.
void task5()
{
	const int UPPER_RANGE = 1000000;

	//wersja 1
	/*for (int numberToCheck = 2; numberToCheck <= UPPER_RANGE; numberToCheck++)
	{
		bool isPrime = true;
		for (int i = 2; i <= sqrt(numberToCheck); i++)
		{
			if (numberToCheck % i == 0)
			{
				isPrime = false;
				break;
			}
		}

		if (isPrime)
			std::cout << numberToCheck << ", ";
	}
	std::cout << "\n";*/

	//wersja 2
	bool primeNumbers[UPPER_RANGE + 1];
	for (int i = 2; i < UPPER_RANGE + 1; i++)
	{
		primeNumbers[i] = true;
	}

	for (int i = 2; i < UPPER_RANGE + 1; i++)
	{
		if (primeNumbers[i])
		{
			for (int j = i + i; j < UPPER_RANGE + 1; j = j + i)
			{
				primeNumbers[j] = false;
			}
		}
	}

	for (int i = 2; i < UPPER_RANGE + 1; i++)
	{
		if (primeNumbers[i])
			std::cout << i << ", ";
	}
	std::cout << "\n";
}

int main()
{
	task5();
}