StreamReader streamReader = new StreamReader("przyklad.txt");

string strNumberFromFile;
List<string> strNumbers = new List<string>();

while ((strNumberFromFile = streamReader.ReadLine()) != null)
{
    strNumbers.Add(strNumberFromFile);
}

streamReader.Close();

//Zadanie 4.1
var reverseDovidedBy17 = strNumbers
    .Where(s => int.Parse(string.Join("", s.Reverse())) % 17 == 0)
    .Select(s => string.Join("", s.Reverse()));

Console.WriteLine("Zdanie 4.1:");
foreach (var strNumber in reverseDovidedBy17)
    Console.WriteLine(strNumber);

//Zadanie 4.2
Console.WriteLine("Zdanie 4.2:");

string strMaxNumber = "";
int maxDiff = int.MinValue;
foreach (var strNumber in strNumbers)
{
    int dif = Math.Abs(int.Parse(strNumber) - int.Parse(string.Join("", strNumber.Reverse())));
    if (dif > maxDiff)
    {
        maxDiff = dif;
        strMaxNumber = strNumber;
    }
}

Console.WriteLine($"{strMaxNumber} {maxDiff}");

strMaxNumber = strNumbers.OrderBy(s => Math.Abs(int.Parse(s) - int.Parse(string.Join("", s.Reverse())))).Last();
maxDiff = Math.Abs(int.Parse(strMaxNumber) - int.Parse(string.Join("", strMaxNumber.Reverse())));

Console.WriteLine($"{strMaxNumber} {maxDiff}");