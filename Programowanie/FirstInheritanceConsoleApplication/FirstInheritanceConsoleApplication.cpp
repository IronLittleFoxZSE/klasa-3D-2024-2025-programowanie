// FirstInheritanceConsoleApplication.cpp

#include <iostream>

class C
{
protected:
    int fieldA;

public:
    int GetFieldA()
    {
        return fieldA;
    }
};

class A: public C
{
private:

public:
    A()
    {
        fieldA = 5;
    }

    void ShowInfo()
    {
        std::cout << "Informacja na temat klasy A\n";
        std::cout << "Field A = " << fieldA << "\n";
    }
};

class B : public C
{
private:
    //int fieldA;
    int fieldB;

public:
    B()
    {
        fieldA = 5;
        fieldB = 4;
    }

    /*int GetFieldA()
    {
        return fieldA;
    }*/

    int GetFieldB()
    {
        return fieldB;
    }

    void ShowInfo()
    {
        std::cout << "Informacja na temat klasy B\n";
        std::cout << "Field A = " << fieldA << "\n";
        std::cout << "Field B = " << fieldB << "\n";
    }
};

int main()
{
    A a;
    a.
}
