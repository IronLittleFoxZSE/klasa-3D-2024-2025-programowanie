// GeometryConsoleApplication.cpp

#include <iostream>

/*

* Dla poniższych klas ułóż drzewko dziedziczenia.
- Tiger (Tygrys), Dog (Pies), Fish (Ryba), Eagle (Orzeł), Mammal (Ssak), Lion (Lew), Sparrow (Wróbel), Reptile (Gad), Trout (Pstrąg), Cat (Kot), Salmon (Łosoś), Animal (Zwierzę), Snake (Wąż), Bird (Ptak), Turtle (Żółw)
- SUV (SUV), Pickup Truck (Pick-up), Truck (Ciężarówka), Car (Samochód), Sedan (Sedan), Motorcycle (Motocykl), Vehicle (Pojazd), Semi-Truck (Ciągnik siodłowy)
- Smartphone (Smartfon), Android Phone (Telefon z systemem Android), Electronic Device (Urządzenie elektroniczne), LED TV (Telewizor LED), Laptop (Laptop), iPhone (iPhone), Television (Telewizor), Smart TV (Telewizor Smart)
*/

//Napisz klasy, które będą opisywać kwadrat, prostokąt, trapez

class Triangle
{
protected:
	double sideA, sideB, sideC, height;
public:
	Triangle(double firstSide,
		double secondSide,
		double thirdSide,
		double h)
	{
		sideA = firstSide;
		sideB = secondSide;
		sideC = thirdSide;
		height = h;
	}
};

class Quadrangle:public Triangle
{
protected:
	double sideD;
public:
	Quadrangle(double firstSide,
		double secondSide,
		double thirdSide,
		double fourthSide,
		double h):Triangle(firstSide, secondSide, thirdSide, height)
	{
		sideD = fourthSide;
	}

	double GetPerimeter()
	{
		return sideA + sideB + sideC + sideD;
	}
};

class Rectangle : public Quadrangle
{
protected:

public:
	Rectangle(double firstSide, double secondSide) :Quadrangle(firstSide, secondSide, firstSide, secondSide, secondSide)
	{
		//sideA = sideC = firstSide;
		//height = sideB = sideD = secondSide;
	}

	double GetArea()
	{
		return sideA * sideB;
	}
};

class Square :public Rectangle
{
protected:

public:
	Square(double side) :Rectangle(side, side)
	{
		//height = sideA = sideB = sideC = sideD = side;
	}
};

class Trapeze : public Quadrangle
{
protected:

public:
	Trapeze(double firstSide,
		double secondSide,
		double thirdSide,
		double fourthSide,
		double h) : Quadrangle(firstSide, secondSide, thirdSide, fourthSide, h)
	{
		//sideA = firstSide;
		//sideB = secondSide;
		//sideC = thirdSide;
		//sideD = fourthSide;
		//height = h;
	}

	double GetArea()
	{
		return (sideA + sideC) * height / 2;
	}
};

int main()
{
	Quadrangle q(3, 2, 5, 4, 2);

	Rectangle r(10, 5);
	std::cout << r.GetArea() << "\n";

	Square s(6);
	std::cout << s.GetArea() << "\n";

	Trapeze t(10, 6, 4, 5, 3);
	std::cout << t.GetArea() << "\n";
}