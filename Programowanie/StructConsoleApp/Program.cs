//StructConsoleApp


Point firstPoint = new Point();
firstPoint.x = 5;
firstPoint.y = 10;
Point secondPoint = firstPoint;
secondPoint.x = 6;
secondPoint.y = 99;
Console.WriteLine(firstPoint.x);
Console.WriteLine(secondPoint.x);

double distance;

distance = CalculateDistanceFromCenter(ref firstPoint);

Console.WriteLine($"Odległość pierwszego punktu to {distance}");

distance = CalculateDistanceFromCenter(ref secondPoint);

Console.WriteLine($"Odległość drugiego punktu to {distance}");

double CalculateDistanceFromCenter(ref Point p)
{
    double d;
    d = Math.Sqrt(p.x * p.x + p.y * p.y);
    return d;
}