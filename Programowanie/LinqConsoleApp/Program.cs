using LinqConsoleApp;

List<Person> people = new List<Person>();

#region Uzupełnienie kolekcji

Person person = new Person();
person.Name = "Ewa";
person.Surname = "Kowalska";
person.Age = 32;

people.Add(person);

person = new Person();
person.Name = "Jan";
person.Surname = "Nowak";
person.Age = 12;

people.Add(person);

person = new Person();
person.Name = "Karol";
person.Surname = "Krawczyk";
person.Age = 52;

people.Add(person);

person = new Person();
person.Name = "Paweł";
person.Surname = "Nowakowski";
person.Age = 35;

people.Add(person);

person = new Person();
person.Name = "Paweł";
person.Surname = "Nowak";
person.Age = 5;

people.Add(person);

person = new Person();
person.Name = "Karol";
person.Surname = "Nowak";
person.Age = 23;

people.Add(person);

#endregion


Console.WriteLine("Główna kolekcja:");
/*
for (int i = 0; i < people.Count; i++)
{
    Console.WriteLine($"Imię: {people[i].Name} Nazwisko: {people[i].Surname} Wiek: {people[i].Age}");
}
*/

foreach (Person p in people)
{
    Console.WriteLine($"Imię: {p.Name} Nazwisko: {p.Surname} Wiek: {p.Age}");
    //people.Remove(p);  //NIEPOPRAWNA OPERACJA
}


List<Person> sortedPeopleByAge = people.OrderBy(p => p.Age).ToList();
Console.WriteLine("Kolekcja posortowana po wieku:");
foreach (Person p in sortedPeopleByAge)
{
    Console.WriteLine($"Imię: {p.Name} Nazwisko: {p.Surname} Wiek: {p.Age}");
}

sortedPeopleByAge = people.OrderByDescending(p => p.Age).ToList();
Console.WriteLine("Kolekcja posortowana po wieku malejąco:");
foreach (Person p in sortedPeopleByAge)
{
    Console.WriteLine($"Imię: {p.Name} Nazwisko: {p.Surname} Wiek: {p.Age}");
}

Console.WriteLine();
int maxAge = people.Max(p => p.Age);
Console.WriteLine($"Najstarsza osoba ma {maxAge} lat.");
Console.WriteLine();

double avgAge = people.Average(p => p.Age);
Console.WriteLine($"Średnia wieku {avgAge} lat.");
Console.WriteLine();

Console.Clear();

List<Person> sortedPeople = people.OrderBy(p => p.Surname).ThenByDescending(p => p.Age).ToList();
/*
select *  
from people
order by Surname asc, Age desc
*/
Console.WriteLine("Kolekcja posortowana:");
foreach (Person p in sortedPeople)
{
    Console.WriteLine($"Imię: {p.Name} Nazwisko: {p.Surname} Wiek: {p.Age}");
}
Random rnd = new Random();
List<Person> mixedPeople = people.OrderBy(p => rnd.Next()).ToList();

/*
select *  
from people
where Age < 18
 */

//if (people.Where(p => p.Age < 18).Count() > 0)
if (people.Any(p => p.Age < 18))
{
    Console.WriteLine("Są osoby niepełnoletnie");
}

if (people.All(p => p.Age >= 18))
{
    Console.WriteLine("Wszystkie osoby są pełnoletnie");
}

Person firstPerson = people.FirstOrDefault(p => p.Name.Length == 3);
//if (firstPerson != null) // jeżeli typ Person jest klasą
if (firstPerson.Equals(default(Person)) == false) // sprawdzenie dla typu wartościowego
{
    Console.WriteLine("Osoba z imieniem większym niż trzy litery");
    Console.WriteLine($"{firstPerson.Name}");
}

/*
select Surname, count(*), max(Age)
from people
grooup by Surname
*/

var groupBySurname = people.GroupBy(p => p.Surname);
Console.WriteLine("Pogrupowana kolekcja po nazwiskach");
foreach(var group in groupBySurname)
{
    Console.WriteLine($"Nazwisko w grupie {group.Key} ");
    Console.WriteLine($"Ilość osób w grupie: {group.Count()}");
    Console.WriteLine($"Najstarsza odoba ma lat: {group.Max(p => p.Age)}");
    Console.WriteLine("Elementy grupy:");
    var sortGroup = group.OrderBy(group => group.Name);
    foreach(Person p in sortGroup)
    {
        Console.WriteLine($"Imię: {p.Name} Nazwisko: {p.Surname} Wiek: {p.Age}");
    }
}



Console.Clear();
