//ListCollectionConsoleApp

//C++:
//int intArray[10];

//C#:
//int[] intArray = new int[10];
//intArray[0] = 9;


List<int> intsCollection = new List<int>();
intsCollection.Add(15);
intsCollection.Add(18);
intsCollection.Add(5);
intsCollection.Add(12);
intsCollection.Add(19);
intsCollection.Add(4);

for (int i = 0; i < intsCollection.Count; i++)
{
    Console.WriteLine(intsCollection[i]);
}
