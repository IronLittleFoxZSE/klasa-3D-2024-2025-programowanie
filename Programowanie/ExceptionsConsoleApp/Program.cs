
Result GetDiv(int x, int y)
{
    int r;
    if (y == 0)
    {
        return new Result(0, true, "Dzielenie przez zero");
    }
    if (x < 0)
    {
        return new Result(0, true, "Pierwiastek z liczby ujemnej");
    }

    r = x / y + (int)Math.Sqrt(x);
    return new Result(r, false, "");
}


int firstNumber = 50;
int secondNumber = 0;

Result result = GetDiv(firstNumber, secondNumber);

if (result.isException == false)
    Console.WriteLine($"Wynik: {result.value}");
else
    Console.WriteLine(result.ExceptionMessage);


//-----------------------------------------------------------------------

try
{
    Console.WriteLine(firstNumber / secondNumber);
    Console.WriteLine();
}
catch(Exception e)
{
    Console.WriteLine(e.Message);
}


//-------------------------------------------------------------------------
int GetDivV2(int x, int y)
{
    int r;
    r = x / y + (int)Math.Sqrt(x);
    return r;
}

try
{
    int secondResult = GetDivV2(firstNumber, secondNumber);
    Console.WriteLine($"Wynik: {secondResult}");
}
catch (Exception e)
{
    Console.WriteLine(e.Message);
}



struct Result
{
    public int value;
    public bool isException;
    public string ExceptionMessage;
    public Result(int v, bool e, string m)
    {
        value = v;
        isException = e;
        ExceptionMessage = m;
    }
    
}

