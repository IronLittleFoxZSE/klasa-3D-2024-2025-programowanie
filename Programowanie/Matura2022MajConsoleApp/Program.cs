


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

