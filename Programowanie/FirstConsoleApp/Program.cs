// See https://aka.ms/new-console-template for more information
Console.Write("Hello, World!");
Console.Write("Hello, World!\n");
Console.WriteLine("Hello, World!");
Console.WriteLine("Hello, World!");

string name = "Jan";
string surname = "Kowalski";
Console.WriteLine("Witaj " + name + " " + surname + " tutaj!!!");
Console.WriteLine("Witaj {0} {1} tutaj",name, surname);
Console.WriteLine($"Witaj {name} {surname} tutaj");

Console.WriteLine("Prędkość to km\\h");
Console.WriteLine(@"Prędkość to km\h");

int number = 5;
int secondNumber = number;
secondNumber = 6;
Console.WriteLine($"number = {number}");
Console.WriteLine($"secondNumber = {secondNumber}");

void ParameterTest_v1(int p)
{
    p++;
    Console.WriteLine($"ParameterTest_v1: p = {p}");
}

void ParameterTest_v2(ref int p)
{
    p++;
    Console.WriteLine($"ParameterTest_v2: p = {p}");
}

void ParameterTest_v3(out int p)
{
    p = 9;
    p++;
    Console.WriteLine($"ParameterTest_v3: p = {p}");
}

ParameterTest_v1(number);
Console.WriteLine($"number = {number}");

ParameterTest_v2(ref number);
Console.WriteLine($"number = {number}");

int thirdNumber;
ParameterTest_v3(out thirdNumber);
Console.WriteLine($"thirdNumber = {thirdNumber}");

//---------------------------------------------------------
Console.WriteLine("Podaj liczbę");
string strNumber = Console.ReadLine()!;

//int convertNumber = int.Parse(strNumber);
int convertNumber;
if (int.TryParse(strNumber, out convertNumber))
    Console.WriteLine($"Dwa razy większa podana liczba: {convertNumber * 2}");