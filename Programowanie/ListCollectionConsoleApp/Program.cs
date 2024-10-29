//ListCollectionConsoleApp

//C++:
//int intArray[10];
//int *tab = new int[10];

//C#:
//int[] intArray = new int[10];
//intArray[0] = 9;
//intArray[1] = 2;
//intArray[2] = 5;
//intArray[3] = 8;


using System.Drawing;

List<int> intsCollection = new List<int>();
intsCollection.Add(15);
intsCollection.Add(18);

Console.WriteLine(intsCollection[0]);
Console.WriteLine(intsCollection[1]);

intsCollection.Add(5);

Console.WriteLine(intsCollection[0]);
Console.WriteLine(intsCollection[1]);
Console.WriteLine(intsCollection[2]);

intsCollection.RemoveAt(1);

Console.WriteLine(intsCollection[0]);
Console.WriteLine(intsCollection[1]);

intsCollection.Add(12);
intsCollection.Add(19);
intsCollection.Add(4);

Console.WriteLine("Elementy na kolekcji:");
for (int i = 0; i < intsCollection.Count; i++)
{
    Console.WriteLine(intsCollection[i]);
}

List<int> intsGreat10Collection = new List<int>();
for (int i = 0; i < intsCollection.Count; i++)
{
    if (intsCollection[i] > 10)
        intsGreat10Collection.Add(intsCollection[i]);
}
//select * form intsCollection where number > 10

intsGreat10Collection = FilterCollectionGreat10(intsCollection);

Console.WriteLine("Elementy na kolekcji wiekszych niż 10:");
for (int i = 0; i < intsGreat10Collection.Count; i++)
{
    Console.WriteLine(intsGreat10Collection[i]);
}

List<int> intsFrom5To7Collection = new List<int>();
for (int i = 0; i < intsCollection.Count; i++)
{
    if (intsCollection[i] >= 5
        && intsCollection[i] <= 7)
        intsFrom5To7Collection.Add(intsCollection[i]);
}

intsFrom5To7Collection = FilterCollectionForm5To7(intsCollection);

/*
List<int> intsDividet2Collection = new List<int>();
for (int i = 0; i < intsCollection.Count; i++)
{
    if (intsCollection[i] % 2 == 0)
        intsDividet2Collection.Add(intsCollection[i]);
}*/

List<int> FilterCollectionGreat10(List<int> collection)
{
    List<int> returnCollection = new List<int>();

    for (int i = 0; i < collection.Count; i++)
    {
        if (collection[i] > 10)
            returnCollection.Add(collection[i]);
    }

    return returnCollection;
}

List<int> FilterCollectionForm5To7(List<int> collection)
{
    List<int> returnCollection = new List<int>();

    for (int i = 0; i < collection.Count; i++)
    {
        if (collection[i] >= 5
            && collection[i] <= 7)
            returnCollection.Add(collection[i]);
    }

    return returnCollection;
}

bool Great10(int number)
{
    return number > 10;
}

bool Form5To7(int number)
{
    return number >= 5
            && number <= 7;
}

bool Even(int number)
{
    return number % 2 == 0;
}

List<int> FilterCollection(List<int> collection, Func<int, bool> check)
{
    List<int> returnCollection = new List<int>();

    for (int i = 0; i < collection.Count; i++)
    {
        if (check(collection[i]) == true)
            returnCollection.Add(collection[i]);
    }

    return returnCollection;
}

//select * form intsCollection where check(number) = true

List<int> result = FilterCollection(intsCollection, Even);

result = FilterCollection(intsCollection, (n) => n > 5);
result = FilterCollection(intsCollection, n => n % 2 == 0);
result = FilterCollection(intsCollection, n => n >= 5 && n <= 7);

result = intsCollection.Where(n => n % 2 == 0).ToList();

List<Point> OrderBy(List<Point> collection, Func<Point, double> predicat)
{
    List<Point> returnCollection = new List<Point>(collection);

    for (int i = 0; i < returnCollection.Count; i++)
        for (int j = 0; j < returnCollection.Count - 1; j++)
            if (predicat(returnCollection[j]) > predicat(returnCollection[j + 1]))
            {
                Point tmp = returnCollection[j];
                returnCollection[j] = returnCollection[j + 1];
                returnCollection[j + 1] = tmp;
            }

    return returnCollection;
}

List<Point> points = new List<Point>();
points.Add(new Point(0, 0));
points.Add(new Point(1, 5));
points.Add(new Point(2, 7));

List<Point> resultPoints;
resultPoints = OrderBy(points, p => p.X);
resultPoints = OrderBy(points, p => p.Y);
resultPoints = OrderBy(points, p => Math.Sqrt(p.X * p.X + p.Y * p.Y));

//result = OrderBy(intsCollection);

result = intsCollection.OrderBy(n => n).ToList();

void ShowMessage()
{
    Console.WriteLine("Hello world");
}

void ShowSimpleMessage(string message, int x)
{
    Console.WriteLine("Witaj świecie " + message);
}

int GetRandomNumber()
{
    return new Random().Next();
}

float GetRandomNumberV2(int x, string m)
{
    if (m == "zakres")
        return new Random().Next(2, 10);

    return new Random().Next();
}

ShowMessage();
ShowSimpleMessage("tutaj", 4);

Action method;
if (new Random().Next() % 2 == 0)
    method = ShowMessage;
else
    method = () => { Console.WriteLine("Hello world"); };
method();

Action<string, int> action;
action = ShowSimpleMessage;
action = (string s, int i) => Console.WriteLine("Witaj świecie " + s);
action(" komunikat", 2);

Func<int> func;
func = GetRandomNumber;

func = () => { return 2; };
int x = func();

Func<int, string, float> func1;
func1 = GetRandomNumberV2;
func1 = (i, s) => { return i + 3; };
func1 = (i, s) => i + 3;
float y = func1(58, "dsfgsdfg");

