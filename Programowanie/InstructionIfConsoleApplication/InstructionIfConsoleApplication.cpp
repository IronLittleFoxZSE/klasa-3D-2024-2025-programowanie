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

int main()
{
    setlocale(LC_CTYPE, "polish");

    task1();
}