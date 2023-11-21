#include <iostream>

//Napisz program, który wczyta znak z klawiatury i sprawdzi czy jest to mała litera aldfabetu.
void task1()
{
    char signFromUser;
    //signFromUser = 'a';
    std::cout << "Podaj znak\n";
    std::cin >> signFromUser;

    std::cout << "Podałeś znak " << signFromUser << "\n";

    //if (signFromUser >= 97 && signFromUser <= 122)
    if (signFromUser >= 'a' && signFromUser <= 'z')
        std::cout << "Znak jest małą literą alfabetu\n";
    else
        std::cout << "Znak nie jest małą literą alfabetu\n";

    signFromUser = signFromUser + 2;
    std::cout << "Podałeś znak " << signFromUser << "\n";

    signFromUser = 'a' + 2;
    std::cout << "Podałeś znak " << signFromUser << "\n";
}


//Napisz program, który poprosi cie o twoje imię i cię przywita.
void task2()
{
    std::string userName;
    userName = "Ala";
    std::cout << "Podaj swoje imię:\n";
    std::cin >> userName;

    std::cout << "Witaj " << userName << " tutaj.\n";
}

int main()
{
    task2();
}

