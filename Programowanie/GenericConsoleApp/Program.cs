
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

int firstNumber = 2, secondNumber = 5;
Swap(ref firstNumber, ref secondNumber);

string firstText = "Ala", secondText = "Ola";
Swap(ref firstText, ref secondText);