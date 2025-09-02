
int firstNumber, secondNumber, thirdNumber;
string errorMessage;

Console.WriteLine("Podaj pierwszą liczbę:");
firstNumber = int.Parse(Console.ReadLine());
Console.WriteLine("Podaj drugą liczbę:");
secondNumber = int.Parse(Console.ReadLine());

int result = 0;

//wersja 1
Console.WriteLine("Wersja 1");
if (secondNumber != 0)
{
    result = firstNumber / secondNumber;
    Console.WriteLine($"Wynik dzielenia: {result}");
}
else
    Console.WriteLine("Nie dziel przez zero");


//wersja 2

//komentarz dokumentujący
/*
Funkcja dzieli dwie liczby i zwraca wynik

Dane wchodzące:
a - pierwsza liczba
b - druga liczba

Dane wychodzace:
wynik dzielenia

Błędy:
* druga liczba nie może być zerem

*/
int Div(int a, int b)
{
    int r;
    r = a / b;
    return r;
}

Console.WriteLine("Wersja 2");
if (secondNumber != 0)
{
    result = Div(firstNumber, secondNumber);
    Console.WriteLine($"Wynik dzielenia: {result}");
}
else
    Console.WriteLine("Nie dziel przez zero");

//....

thirdNumber = 0;
if (thirdNumber != 0)
    Console.WriteLine($"Wynik dzielenia: {Div(43, thirdNumber)}");
else
    Console.WriteLine("Nie dziel przez zero");






//wersja 3

//komentarz dokumentujący
/*
Funkcja dzieli dwie liczby i zwraca wynik

Dane wchodzące:
a - pierwsza liczba
b - druga liczba

Dane wychodzace:
wynik dzielenia lub null jesli dzielimy przez zero


*/
int? DivV3(int a, int b)
{
    int r;
    if (b != 0)
    {
        r = a / b;
        return r;
    }
    else
        return null;
}

Console.WriteLine("Wersja 3");
int? resultV3 = DivV3(firstNumber, secondNumber);
if (resultV3 != null)
{
    Console.WriteLine($"Wynik dzielenia: {resultV3}");
}
else
    Console.WriteLine("Nie dziel przez zero");

//....

thirdNumber = 0;
resultV3 = DivV3(43, thirdNumber);
if (resultV3 != null)
    Console.WriteLine($"Wynik dzielenia: {resultV3}");
else
    Console.WriteLine("Nie dziel przez zero");



//wersja 4

//komentarz dokumentujący
/*
Funkcja dzieli dwie liczby i zwraca wynik

Dane wchodzące:
a - pierwsza liczba
b - druga liczba

Dane wychodzace:
wynik dzielenia

Błędy:
* druga liczba nie może być zerem

*/
bool TryDivV4(int a, int b, out int r)
{
    if (b != 0)
    {
        r = a / b;
        return true;
    }
    else
    {
        r = 0;
        return false;
    }
}

Console.WriteLine("Wersja 4");
if (TryDivV4(firstNumber, secondNumber, out result))
{
    Console.WriteLine($"Wynik dzielenia: {result}");
}
else
    Console.WriteLine("Nie dziel przez zero");

//....

thirdNumber = 0;
if (TryDivV4(43, thirdNumber, out result))
    Console.WriteLine($"Wynik dzielenia: {result}");
else
    Console.WriteLine("Nie dziel przez zero");

//wersja 5

Console.WriteLine("Wersja 5");
bool Operations(int a, int b, char sign, out int r, out string errorMessage)
{
    errorMessage = "";
    switch (sign)
    {
        case '+':
            r = a + b;
            return true;
        case '-':
            r = a - b;
            return true;
        case '*':
            r = a * b;
            return true;
        case '/':
            if (b != 0)
            {
                r = a / b;
                return true;
            }
            else
            {
                r = 0;
                errorMessage = "Nie dziel przez zero";
                return false;
            }
        default:
            r = 0;
            errorMessage = "Nieprawidłowy operator";
            return false;
    }
}

if (Operations(firstNumber, secondNumber, '?', out result, out errorMessage))
    Console.WriteLine($"Wynik operacji: {result}");
else
    Console.WriteLine(errorMessage);

//wersja 6

Console.WriteLine("Wersja 6");

bool resultOperation = Operations(firstNumber, secondNumber, '?', out result, out errorMessage);

if (resultOperation)
    Console.WriteLine($"Wynik operacji: {result}");
else if (/*!resultOperation && */  errorMessage == "Nie dziel przez zero")
    Console.WriteLine(errorMessage);
else
{
    //zapis do pliku
}


//wersja 7

Console.WriteLine("Wersja 7");

try
{
    result = firstNumber / secondNumber;
    Console.WriteLine($"Wynik dzielenia: {result}");
}
catch (Exception ex)
{
    //Console.WriteLine("Nie dziel przez zero");
    Console.WriteLine(ex.Message);
}


//wersja 8
int DivV8(int a, int b)
{
    int r = a / b;
    return r;
}

Console.WriteLine("Wersja 8");
try
{
    result = DivV8(firstNumber, secondNumber);
    result = DivV8(firstNumber, secondNumber + 1);
    Console.WriteLine($"Wynik dzielenia: {result}");
}
catch (Exception ex)
{
    //Console.WriteLine("Nie dziel przez zero");
    Console.WriteLine(ex.Message);
    Console.WriteLine(ex.StackTrace);
}


//wersja 9

Console.WriteLine("Wersja 9");
int OperationsV9(int a, int b, char sign)
{
    int r;
    switch (sign)
    {
        case '+':
            r = a + b;
            return r;
        case '-':
            r = a - b;
            return r;
        case '*':
            r = a * b;
            return r;
        case '/':
            r = a / b;
            return r;
        default:
            Exception e = new Exception("Nieprawidłowy operator");
            throw e;
    }
}

try
{
    result = OperationsV9(firstNumber, secondNumber, '?');
    Console.WriteLine($"Wynik operacji: {result}");
}
catch (Exception ex)
{
    //Console.WriteLine("Nie dziel przez zero");
    Console.WriteLine(ex.Message);
    Console.WriteLine(ex.StackTrace);
}