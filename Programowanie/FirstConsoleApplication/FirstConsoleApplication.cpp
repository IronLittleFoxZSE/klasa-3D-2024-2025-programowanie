// FirstConsoleApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _USE_MATH_DEFINES
#include <iostream>

void test() 
{
    std::cout << "Hello World!\n";
    std::cout << -59.5 << 'x' << "ghfghjfghj" << true << false << '\n';

    //typ nazwa;
    int number;
    number = 5;

    int secondNumber;
    secondNumber = number + 2;
    /*
    Priorytet operatorów:

    (, )
    +, - (unarne)
    *, /, %
    +, -
    =

    */
    std::cout << "Komuinikat \n";
    std::cin >> secondNumber >> number;
}

/*
Podstawy programowania:

1. 
2. Program obliczający pole prostokąta.
3. Program obliczający objętość stożka.
4. Program obliczający pole koła.
5. Program obliczający wartość wyrażenia a^2 + b^2
6. Program obliczający pole trójkąta o podstawie b i wysokości h
7. Program obliczający objętość kuli o promieniu r
8. Program obliczający pole trapezu o podstawach a i b oraz wysokości h
9. Program obliczający średnią ważoną trzech liczb z podanymi odpowiednimi wagami w1, w2 i w3.
*/

//Program obliczający średnią arytmetyczną dwóch liczb.
void task1() 
{
    double firstNumber, secondNumber;

    std::cout << "Podaj pierwszą liczbę:\n";\
    std::cin >> firstNumber;
    std::cout << "Podaj drugą liczbę:\n";
    std::cin >> secondNumber;

    double avarageOfNumbers = (firstNumber + secondNumber) / 2;

    std::cout << "Średnia tych liczb to: " << avarageOfNumbers << "\n";
}

int main()
{
    setlocale(LC_CTYPE, "polish");
    //test();
    task1();
    //task2();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
