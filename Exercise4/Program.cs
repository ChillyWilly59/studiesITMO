namespace Exercise4
{
    using System;

    class Triangle
    {
        private double sideA;
        private double sideB;
        private double sideC;

        public Triangle(double sideA, double sideB, double sideC)
        {
            this.sideA = sideA;
            this.sideB = sideB;
            this.sideC = sideC;
        }

        public double GetPerimeter()
        {
            return sideA + sideB + sideC;
        }

        public double GetArea()
        {
            if (!IsValidTriangle())
            {
                throw new InvalidOperationException("Треугольник с такими сторонами не существует.");
            }

            double semiPerimeter = GetPerimeter() / 2;
            return Math.Sqrt(semiPerimeter * (semiPerimeter - sideA) * (semiPerimeter - sideB) * (semiPerimeter - sideC));
        }

        public bool IsValidTriangle()
        {
            return (sideA + sideB > sideC) && (sideA + sideC > sideB) && (sideB + sideC > sideA);
        }

        public void DisplaySides()
        {
            Console.WriteLine($"Стороны треугольника: {sideA}, {sideB}, {sideC}");
        }

    }

    class Program
    {
        static void Main()
        {
            try
            {
                Console.WriteLine("Введите стороны треугольника:");
                Console.Write("Сторона A: ");
                double sideA = double.Parse(Console.ReadLine());
                Console.Write("Сторона B: ");
                double sideB = double.Parse(Console.ReadLine());
                Console.Write("Сторона C: ");
                double sideC = double.Parse(Console.ReadLine());

                Triangle triangle = new Triangle(sideA, sideB, sideC);

                if (triangle.IsValidTriangle())
                {
                    triangle.DisplaySides();
                    Console.WriteLine($"Периметр треугольника: {triangle.GetPerimeter()}");
                    Console.WriteLine($"Площадь треугольника: {triangle.GetArea()}");
                }
                else
                {
                    Console.WriteLine("Треугольник с такими сторонами не существует.");
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("Ошибка: " + ex.Message);
            }
        }
    }

}
