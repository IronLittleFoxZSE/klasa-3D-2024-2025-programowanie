
/*
void ShowValue(string value)
{
    Console.WriteLine(value);
}
void ShowValue(int value)
{
    Console.WriteLine(value);
}
void ShowValue(bool value)
{
    Console.WriteLine(value);
}
*/

using System.Collections.Generic;

void ShowValue<T>(T value)
{
    Console.WriteLine(value);
}

string text = "Ala";
ShowValue<string>(text);

int number = 9;
ShowValue/*<int>*/(number);

bool boolValue = true;
ShowValue(boolValue);


//--------------------------------------
/*
void Swap(ref int x, ref int y)
{
    int tmp = x; 
    x = y;
    y = tmp;
}

void Swap(ref string x, ref string y)
{
    string tmp = x;
    x = y;
    y = tmp;
}
*/

void Swap<T>(ref T x, ref T y)
{
    T tmp = x;
    x = y;
    y = tmp;
}

int firstNumber = 2;
int secondNumber = 5;
Swap(ref firstNumber, ref secondNumber);

string firstText = "Ala", secondText = "Ola";
Swap(ref firstText, ref secondText);


//-------------------------------------------

/*
class MyClass
{
    int value;
    public void MyMethod(string s)
    {

    }

    //pozostała część klasy
}

class MyClass
{
    bool value;
    public void MyMethod(int s)
    {

    }

    //pozostała część klasy
}
*/

MyClass<string, int> myClass = new MyClass<string, int>();

MyClass<bool, int> myClass2 = new MyClass<bool, int>();

class MyClass<T1, T2>
{
    T1 value;

    public void MyMethod(T2 s)
    {

    }

    //pozostała część klasy
}



