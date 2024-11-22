

using LinqTasksConsoleApp;

var tasks = new List<TaskItem>
{
    new TaskItem(1, "Buy groceries", true),
    new TaskItem(2, "Clean the house", false),
    new TaskItem(3, "Pay bills", true),
    new TaskItem(4, "Study LINQ", false),
    new TaskItem(5, "Exercise", true)
};

/*
var tasks = new List<TaskItem>();
tasks.Add(new TaskItem(1, "Buy groceries", true));
tasks.Add(new TaskItem(2, "Clean the house", false));
//itd.
*/

// Zadanie 1: Wyszukaj wszystkie zakończone zadania
/*
select *
from tasks
where IsCompleted == true
 */
Console.WriteLine("Zadanie 1");
List<TaskItem> complitedTasks = tasks.Where(t => t.IsCompleted == true).ToList();
foreach (var task in complitedTasks)
{
    Console.WriteLine(task);
}

// Zadanie 2: Znajdź pierwsze zadanie, które nie jest zakończone
/*
select *
from tasks
where IsCompleted == false
limit 1
*/
//TaskItem firstNotComplited = tasks.Where(t=> t.IsCompleted == false).First();
TaskItem firstNotComplited = tasks.First(t=> t.IsCompleted == false);
Console.WriteLine("Zadanie 2");
Console.WriteLine("Pierwsze niezakończone zadanie:");
Console.WriteLine(firstNotComplited);

// Zadanie 3: Posortuj zadania według nazwy
/*
select *
from tasks
order by Name
*/
Console.WriteLine("Zadanie 3");
var sortedTasksByName = tasks.OrderBy(t => t.Name);
foreach (var task in sortedTasksByName)
{
    Console.WriteLine(task);
}

// Zadanie 4: Policz zadania zakończone
/*
    select count(*)
    from tasks
    where IsCompleted == true
*/

Console.WriteLine("Zadanie 4");
//int countCoplitedTasks = tasks.Where(t=> t.IsCompleted == true).Count();
int countCoplitedTasks = tasks.Count(t=> t.IsCompleted == true);
Console.WriteLine($"Ilość zakończonych zadań {countCoplitedTasks}");

// Zadanie 5: Wybierz tylko nazwy zadań i wyświetl
/*
select name
from tasks
*/
Console.WriteLine("Zadanie 5");
List<string> names = tasks.Select(t=> t.Name).ToList();
foreach (string name in names)
{
    Console.WriteLine(name);
}

// Zadanie 6: Znalezienie nazw zakończonych zadań posortowanych według długości nazwy

//Zadanie 7: Zadania pogrupowane według stanu zakończenia, a następnie posortowane w grupach według nazwy

//Zadanie 8: Najkrótsza nazwa zadania niezakończonego

//Zadanie 9: Ilość liter w nazwach wszystkich zakończonych zadań

//Zadanie 10: Lista zadań z indeksami (zakończone zadania z numeracją)

//Zadanie 11: Zadania z najdłuższą nazwą w każdej grupie zakończonych i niezakończonych

//Zadanie 12: Zlicz, ile zadań w każdej grupie zawiera słowo „the” w nazwie

//Zadanie 13: Utwórz listę zakończonych zadań z ich numeracją oraz długością nazw

//Zadanie 14: Zadania posortowane według stanu zakończenia, a następnie alfabetycznie według nazw

//Zadanie 15: Sprawdź, czy w nazwach wszystkich zadań są co najmniej 2 różne samogłoski

//Zadanie 16: Znajdź wszystkie unikalne litery używane w nazwach zadań zakończonych
