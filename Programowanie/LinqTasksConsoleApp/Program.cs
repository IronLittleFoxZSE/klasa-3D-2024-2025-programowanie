

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

// Zadanie 2: Znajdź pierwsze zadanie, które nie jest zakończone

// Zadanie 3: Posortuj zadania według nazwy

// Zadanie 4: Policz zadania zakończone

// Zadanie 5: Wybierz tylko nazwy zadań i wyświetl

// Zadanie 6: Znalezienie nazw zakończonych zadań posortowanych według długości nazwy

//Zadanie 7: Zadania pogrupowane według stanu zakończenia, a następnie posortowane w grupach według nazwy

//Zadanie 8: Najkrótsza nazwa zadania niezakończonego

//Zadanie 9: Ilość liter w nazwach wszystkich zakończonych zadań

//Zadanie 10: Lista zadań z indeksami (zakończone zadania z numeracją)