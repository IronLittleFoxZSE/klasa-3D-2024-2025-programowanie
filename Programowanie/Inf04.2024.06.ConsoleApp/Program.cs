using System;

string repeatAgain;

do 
{
    int numberOfDiece;

    do
    {

        Console.WriteLine("Ile kostek chcesz rzucić?(3-10)");
        string strNumberOfDiece = Console.ReadLine();
        if (!int.TryParse(strNumberOfDiece, out numberOfDiece))
            numberOfDiece = 0;
    } while (numberOfDiece < 3 || numberOfDiece > 10);

    int[] throwResults = GetThrowResults(numberOfDiece);

    for (int i = 0; i < throwResults.Length; i++) 
    {
        Console.WriteLine($"Kostka {i + 1}: {throwResults[i]}");
    }

    Console.WriteLine($"Liczba uzyskanych punktów: {GetScore(throwResults)}");

    do
    {
        Console.WriteLine("Czy jeszcze raz? (t/n)");
        repeatAgain = Console.ReadLine();
    } while (repeatAgain != "t" && repeatAgain != "n");
} while (repeatAgain == "t");

/*
************************************************
 nazwa: GetThrowResults
 opis: Funkcja zwraca wylosowane wartości na kostkach
 parametry: numberOfDiece - ilość kostek którymi rzucamy
...
 zwracany typ i opis: int - wyrzucone oczka(wartości) na kostkach
 autor: 1234567898
************************************************
*/
int[] GetThrowResults(int numberOfDiece)
{
    int[] throwResults = new int[numberOfDiece];
    Random random = new Random();
    for (int i = 0; i < numberOfDiece; i++)
        throwResults[i] = random.Next(1, 7);
    return throwResults;
}

int GetScore(int[] throwResults)
{
    int result = 0;
    /*
    int[] tabPoints = new int[7];
    foreach (int value in throwResults)
    {
        tabPoints[value]++;
    }
    for (int i = 1; i < tabPoints.Length; i++)
        if (tabPoints[i] > 1)
            result += i * tabPoints[i];
    */

    result = throwResults.GroupBy(n => n).Where(g => g.Count() > 1).Sum(g => g.Sum());
    return result;
}