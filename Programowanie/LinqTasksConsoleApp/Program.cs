

using LinqTasksConsoleApp;


var tasks = new List<TaskItem>
{
    new TaskItem { TaskId = 1, Name = "Buy groceries", CategoryId = 1, IsCompleted = true },
    new TaskItem { TaskId = 2, Name = "Pay bills", CategoryId = 2, IsCompleted = false },
    new TaskItem { TaskId = 3, Name = "Exercise", CategoryId = 1, IsCompleted = true },
    new TaskItem { TaskId = 4, Name = "Clean house", CategoryId = 3, IsCompleted = false }
};

List<Category> categories = new List<Category>
{
    new Category { CategoryId = 1, CategoryName = "Shopping" },
    new Category { CategoryId = 2, CategoryName = "Bills" },
    new Category { CategoryId = 3, CategoryName = "Housework" },
    new Category { CategoryId = 4, CategoryName = "Health" }
};

/*
 select *
from tasks t
join categories c on c.CategoryId = t.CategoryId
order by t.Name

select *
from (select t.Name, c.CategoryName
        from tasks t
        join categories c on c.CategoryId = t.CategoryId ) x
order by x.Name
*/

var joinCollection = tasks
    //.Where(t => t.IsCompleted)
    .Join(categories, t => t.CategoryId, c => c.CategoryId, (t, c) => new { Name = t.Name, CategoryName = c.CategoryName })
    .OrderBy(x => x.Name);

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
TaskItem firstNotComplited = tasks.First(t => t.IsCompleted == false);
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
int countCoplitedTasks = tasks.Count(t => t.IsCompleted == true);
Console.WriteLine($"Ilość zakończonych zadań {countCoplitedTasks}");

// Zadanie 5: Wybierz tylko nazwy zadań i wyświetl
/*
select name
from tasks
*/
Console.WriteLine("Zadanie 5");
List<string> names = tasks.Select(t => t.Name).ToList();
foreach (string name in names)
{
    Console.WriteLine(name);
}

// Zadanie 6: Znalezienie nazw zakończonych zadań posortowanych według długości nazwy
/*
select Name
from tasks
where IsCompleted == true
order by Length(Name)    
*/
Console.WriteLine("Zadanie 6");
var complitedTaskNames = tasks.Where(t => t.IsCompleted).OrderBy(t => t.Name.Length).Select(t => t.Name);
foreach (string name in complitedTaskNames)
{
    Console.WriteLine(name);
}


//Zadanie 7: Zadania pogrupowane według stanu zakończenia, a następnie posortowane w grupach według nazwy
/*
select *
from tasks
order by IsCompleted, Name
*/
Console.WriteLine("Zadanie 7");
var sortedTasks = tasks.OrderBy(t => t.IsCompleted).ThenBy(t => t.Name);
foreach (TaskItem task in sortedTasks)
{
    Console.WriteLine(task);
}


//Zadanie 8: Najkrótsza nazwa zadania niezakończonego
/*
select name
form tasks
where IsCompleted == false
order by Length(Name)       
limit 1
*/
Console.WriteLine("Zadanie 8");
string minName = tasks.Where(t => !t.IsCompleted).OrderBy(t => t.Name.Length).Select(t => t.Name).FirstOrDefault();
if (minName != null)
{
    Console.WriteLine(minName);
}

//Zadanie 9: Ilość liter w nazwach wszystkich zakończonych zadań
Console.WriteLine("Zadanie 9");
int sumOfNamesLength = tasks.Where(t => t.IsCompleted).Select(t => t.Name.Length).Sum();
Console.WriteLine(sumOfNamesLength);

//Zadanie 10: Lista zadań z indeksami (zakończone zadania z numeracją)

Console.WriteLine("Zadanie 10");
/*
var x = tasks.Where(t => t.IsCompleted);
for (int i = 0; i < x.Count(); i++)
{
    Console.WriteLine($"{i + 1}:");
    Console.WriteLine(x.ElementAt(i));
}
*/

/*
List<Result> completedTasksWidthIndex = tasks.Where(t => t.IsCompleted)
    .Select((t, index) => new Result() {Index = index + 1, Task = t } )
    .ToList();
foreach (Result r in completedTasksWidthIndex)
{
    Console.WriteLine($"{r.Index}:");
    Console.WriteLine(r.Task);
}

class Result
{
    public int Index { get; set; }
    public TaskItem Task { get; set; }
}
*/

var completedTasksWidthIndex = tasks.Where(t => t.IsCompleted)
    .Select((t, index) => new { Index = index + 1, Task = t });
foreach (var r in completedTasksWidthIndex)
{
    Console.WriteLine($"{r.Index}:");
    Console.WriteLine(r.Task);
}

//Zadanie 11: Zadania z najdłuższą nazwą w każdej grupie zakończonych i niezakończonych
Console.WriteLine("Zadanie 11");

/*
var groupTasks = tasks.GroupBy(t => t.IsCompleted);
foreach (var group in groupTasks)
{
    Console.WriteLine($"Grupa zakończona: {group.Key}");
    var maxName = group.OrderByDescending(t => t.Name.Length).First().Name;
    Console.WriteLine($"Najdłuższa nazwa w grupie: {maxName}");
}
*/
var groupTasks = tasks.GroupBy(t => t.IsCompleted)
    .Select(g => new { GroupVaule = g.Key, MaxName = g.OrderByDescending(t => t.Name.Length).First().Name });
foreach (var group in groupTasks)
{
    Console.WriteLine($"Grupa zakończona: {group.GroupVaule}");
    Console.WriteLine($"Najdłuższa nazwa w grupie: {group.MaxName}");
}

//Zadanie 12: Zlicz, ile zadań w każdej grupie zakończonych i niezakończonych zawiera słowo „the” w nazwie

//Zadanie 13: Utwórz listę zakończonych zadań z ich numeracją oraz długością nazw

//Zadanie 14: Zadania posortowane według stanu zakończenia, a następnie alfabetycznie według nazw

//Zadanie 15: Sprawdź, czy w nazwach wszystkich zadań są co najmniej 2 różne samogłoski

var x = tasks.All(t => t.Name.ToLower().Where(c => "aeiouy".Contains(c)).Distinct().Count() >= 2 );

//Zadanie 16: Znajdź wszystkie unikalne litery używane w nazwach zadań zakończonych
Console.WriteLine("Zadanie 16");
//var y = tasks.Where(t => t.IsCompleted).SelectMany(t => t.Name.ToLower().Where(c => c >= 'a' && c <='z')).Distinct();
var y = tasks.Where(t => t.IsCompleted).SelectMany(t => t.Name.ToLower().Where(c => char.IsLetter(c))).Distinct();

Console.WriteLine(string.Join(", ", y));

