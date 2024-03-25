#include <iostream>

/*
Zdefiniuj klase opisującą prostokąt. Możliwości klasy:
* konstruktory
* metoda która zwórci obwód prostokąta
* metoda która pole prostokąta
* metodę która pokaże informacje o prostokącie.

Napisz program który zaprezentuje możliwości obiektu na podstawie tej klasy.
*/

/*
ZADANIE
Zdefiniuj klase opisujące konto bankowe. Możliwości klasy:
* konstruktory
* metoda która dokona wpłaty na konto
* metoda która wypłaty z konta
* metoda która wykona przelew na inne konto
* metodę która pokaże informacje o koncie.

Napisz program który zaprezentuje możliwości obiektu na podstawie tej klasy.
*/

class Point
{
private:
	int x;
	int y;
	int z;

public:
	Point()
	{
		x = 3;
		y = 7;
		z = 10;
	}

	Point(int xx)
	{
		x = xx;
		y = 7;
		z = 10;
	}

	Point(int xx, int yy, int zz)
	{
		x = xx;
		y = yy;
		z = zz;
	}

	//konstrukctor kopiujący
	Point(Point &p)
	{
		x = p.x;
		y = p.y;
		z = p.z;
	}

	~Point()
	{
		std::cout << "Tera działa destruktor\n";
	}

	void SetX(int value)
	{
		//x = abs(value);
		if (value >= 0)
			x = value;
		else
		{
			//reakcja na błąd
		}
	}

	int GetX()
	{
		//if (uprawnienia)

		return x;
	}

	double DistanceFromCenter()
	{
		double distance;
		distance = sqrt(x * x + y * y + z * z);
		return distance;
	}
};

void taksPoint()
{
	{
		Point firstPoint;
		//firstPoint.x = 3;
		firstPoint.SetX(-3);
		//firstPoint.y = 5;
		//firstPoint.z = 8;
		std::cout << "Odległość " << firstPoint.DistanceFromCenter() << "\n";
	}

	Point secondPiont(15);
	std::cout << "Odległość " << secondPiont.DistanceFromCenter() << "\n";

	Point thirdPoint(secondPiont);
	std::cout << "Odległość " << thirdPoint.DistanceFromCenter() << "\n";
}


class Rectangle
{
private:
	double sideA, sideB;
public:
	Rectangle()
	{
		sideA = 3.14;
		sideB = 7.25;
	}

	Rectangle(double a, double b)
	{
		sideA = a;
		sideB = b;
	}

	double GetPerimeter()
	{
		return 2 * sideA + 2 * sideB;
	}

	double GetArea()
	{
		return sideA * sideB;
	}

	void ShowInfo()
	{
		std::cout << "Informacja o prostokącie\n";
		std::cout << "Bok a = " << sideA << "\n";
		std::cout << "Bok b = " << sideB << "\n";
		std::cout << "Obwód = " << GetPerimeter() << "\n";
		std::cout << "Pole = " << GetArea() << "\n";
	}
};

class Parallelogram
{
private:
	double sideA, sideB;
	double height;
public:
	Parallelogram()
	{
		sideA = 3;
		sideB = 19.75;
		height = 12.5;
	}

	Parallelogram(double a, double b, double h)
	{
		sideA = a;
		sideB = b;
		height = h;
	}

	double GetPerimeter()
	{
		return 2 * sideA + 2 * sideB;
	}

	double GetArea()
	{
		return sideA * height;
	}

	void ShowInfo()
	{
		std::cout << "Informacja o równoległoboku\n";
		std::cout << "Bok a = " << sideA << "\n";
		std::cout << "Bok b = " << sideB << "\n";
		std::cout << "Wysokość = " << height << "\n";
		std::cout << "Obwód = " << GetPerimeter() << "\n";
		std::cout << "Pole = " << GetArea() << "\n";
	}
};

int main()
{
	
}
