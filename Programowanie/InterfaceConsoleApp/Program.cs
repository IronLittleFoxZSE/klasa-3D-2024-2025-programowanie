internal class Program
{
    private static void Main(string[] args)
    {
        A firstA = new A();
        firstA.X = 5;

        A secondA = new A();
        secondA.X = 6;

        A thirdA = firstA;
        thirdA.X = 7;

        int number = 5;
        function0(ref number);
        Console.WriteLine(number); //bez ref: 5 ; z ref: 6

        firstA.X = 5;
        function1(firstA);
        Console.WriteLine(firstA.X); //6

        void function0(ref int x)
        {
            x++;
        }

        void function1(A a)
        {
            // a = new A();
            a.X++;
        }

        //-----------------------------------------
        X();
    }

    static void X()
    {
        A a = new A();
        a.X = 5;
        B b = new B();
        C c = new C();
        c.X = 6;

        f1(a);
        f1(c);
        f2(b);


        void f1(A a)
        {
            a.X++;
        }

        void f2(B b)
        {
            b.X++;
        }
    }

    static void Y()
    {
        A a = new A();
        B b = new B();
        C c = new C();

        Print(a);
        Print(c);

        Print(b);

        void Print(IPrintAll o)
        {
            o.PrintObject();
        }

    }

}

interface IPrintAll
{
    void PrintObject();
}

class A : Object, IPrintAll
{
    public int X { get; set; }

    public void PrintObject()
    {

    }
}

class B : IPrintAll
{
    public int X { get; set; }
    public int Y { get; set; }

    public void PrintObject()
    {

    }
}

class C : A//, IPrintAll
{

}