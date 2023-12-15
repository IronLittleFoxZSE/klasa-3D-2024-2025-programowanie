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



int main()
{
	task1();
}