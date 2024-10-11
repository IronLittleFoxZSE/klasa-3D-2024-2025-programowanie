#include <iostream>
#include <sys/stat.h>

struct point
{
	int x;
	int y;
	int z;
	std::string name;
};

double DistanceFromCenter(int x, int y, int z)
{
	double distance;
	distance = sqrt(x * x + y * y + z * z);
	return distance;
}

double DistanceFromCenter(point p)
{
	double distance;
	distance = sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
	return distance;
}

int main()
{
	setlocale(LC_CTYPE, "polish");

	int x, y, z;

	std::cout << "Podaj x\n";
	std::cin >> x;
	std::cout << "Podaj y\n";
	std::cin >> y;
	std::cout << "Podaj z\n";
	std::cin >> z;

	std::cout << "Odległość " << DistanceFromCenter(x, y, z) << "\n";

	int x1, y1;
	int x2, y2;

	int xx[50], yy[50], zz[50];
	xx[3] = 5;
	yy[3] = 7;
	zz[3] = 77;

	point firstPoint;
	firstPoint.x = 3;
	firstPoint.y = 5;
	firstPoint.z = 8;
	firstPoint.name = "Dom";
	std::cout << "Odległość " << DistanceFromCenter(firstPoint.x, firstPoint.y, firstPoint.z) << "\n";
	std::cout << "Odległość " << DistanceFromCenter(firstPoint) << "\n";

	point tabOfPoints[15];
	tabOfPoints[2].y = 68;
}
