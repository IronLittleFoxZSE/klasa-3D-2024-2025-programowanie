using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassConsoleApp
{
    class Point
    {
        public int x;
        public int y;

        public double CalculateDistanceFromCenter()
        {
            double d;
            d = Math.Sqrt(x * x + y * y);
            return d;
        }
    }
}
