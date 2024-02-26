#include <iostream>

class Point
{
private:
	int x;
	int y;
	int z;

public:
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
	Point firstPoint;
	//firstPoint.x = 3;
	firstPoint.SetX(-3);
	//firstPoint.y = 5;
	//firstPoint.z = 8;
	std::cout << "Odległość " << firstPoint.DistanceFromCenter() << "\n";

}
