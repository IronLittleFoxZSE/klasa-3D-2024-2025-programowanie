#include <iostream>

/*
Zdefiniuj klase opisującą prostokąt. Możliwości klasy:
* konstruktory
* metoda która zwórci obwód prostokąta
* metoda która pole prostokąta
* metodę która pokaże informacje o prostokącie.

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



int main()
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
}
