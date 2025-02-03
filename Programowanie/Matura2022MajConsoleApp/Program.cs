


//Matura2022MajConsoleApp

StreamReader streamReader = new StreamReader("przyklad.txt");

string strNumberFromFile;
List<string> strNumbers = new List<string>();

while ((strNumberFromFile = streamReader.ReadLine()) != null)
{
    strNumbers.Add(strNumberFromFile);
}

streamReader.Close();

//zadanie 4.1
int counter4_1 = strNumbers.Where(s => s[0] == s[s.Length - 1]).Count();
string firstNumber4_1 = strNumbers.First(s => s[0] == s[s.Length - 1]);
Console.WriteLine($"{counter4_1} {firstNumber4_1}");

//zadanie 4.2
int maxCountPrimeFactors = 0;
string maxNumberPrimeFactors = "";

int maxCountDifferentPrimeFactors = 0;
string maxNumberDifferentPrimeFactors = "";
foreach (string strNumber in strNumbers)
{
    //Console.WriteLine(strNumber);
    int number = int.Parse(strNumber);
    int div = 2;

    List<int> primeFactors = new List<int>();
    while (number != 1)
    {
        if (number % div == 0)
        {
            //Console.Write($"{div}, ");
            primeFactors.Add(div);
            number = number / div;
        }
        else
            div++;
    }

    if (primeFactors.Count() > maxCountPrimeFactors)
    {
        maxCountPrimeFactors = primeFactors.Count();
        maxNumberPrimeFactors = strNumber;
    }

    if (primeFactors.Distinct().Count() > maxCountDifferentPrimeFactors)
    {
        maxCountDifferentPrimeFactors = primeFactors.Distinct().Count();
        maxNumberDifferentPrimeFactors = strNumber;
    }

    //Console.WriteLine();
}
Console.WriteLine($"Zadanie 4.2 {maxNumberPrimeFactors} {maxCountPrimeFactors} {maxNumberDifferentPrimeFactors} {maxCountDifferentPrimeFactors}");

//zadanie 4.3

List<int> numbers = strNumbers.Select(strNumber => int.Parse(strNumber)).OrderBy(n => n).Distinct().ToList();

for (int i = 0; i < numbers.Count(); i++)
{
    for (int j = i+1; j < numbers.Count(); j++)
    {
        if (/*numbers[i] < numbers[j]
            && */numbers[j] % numbers[i] == 0)
        {
            for (int k = j+1; k < numbers.Count(); k++)
            {
                if (/*numbers[j] < numbers[k]
                    && */numbers[k] % numbers[j] == 0)
                    for (int l = k + 1; l < numbers.Count(); l++)
                    {
                        if (/*numbers[k] < numbers[l]
                        && */numbers[l] % numbers[k] == 0)
                            Console.WriteLine($"{numbers[i]} {numbers[j]} {numbers[k]} {numbers[l]}");
                    }
            }
            
        }
    }
}