namespace Labs8
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

            if (!IsValidTriangle(sideA, sideB, sideC))
            {
                throw new ArgumentException("Треугольник с такими сторонами не существует.");
            }
        }

        public Triangle(double side)
        {
            this.sideA = side;
            this.sideB = side;
            this.sideC = side;
        }

        public double GetPerimeter()
        {
            return sideA + sideB + sideC;
        }

        public double GetArea()
        {
            double semiPerimeter = GetPerimeter() / 2;
            return Math.Sqrt(semiPerimeter * (semiPerimeter - sideA) * (semiPerimeter - sideB) * (semiPerimeter - sideC));
        }
        
        private bool IsValidTriangle(double sideA, double sideB, double sideC)
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
        static void Main(string[] args)
        {
            Console.WriteLine("Выберите тип треугольника:");
            Console.WriteLine("1. Треугольник с заданными длинами сторон");
            Console.WriteLine("2. Равносторонний треугольник");

            int choice = int.Parse(Console.ReadLine());

            try
            {
                switch (choice)
                {
                    case 1:
                        Console.WriteLine("Введите длину стороны A:");
                        double a = double.Parse(Console.ReadLine());

                        Console.WriteLine("Введите длину стороны B:");
                        double b = double.Parse(Console.ReadLine());

                        Console.WriteLine("Введите длину стороны C:");
                        double c = double.Parse(Console.ReadLine());

                        Triangle triangle1 = new Triangle(a, b, c);
                        Console.WriteLine("Треугольник 1:");
                        triangle1.DisplaySides();
                        Console.WriteLine("Периметр: " + triangle1.GetPerimeter());
                        Console.WriteLine("Площадь: " + triangle1.GetArea());
                        break;

                    case 2:
                        Console.WriteLine("Введите длину стороны равностороннего треугольника:");
                        double side = double.Parse(Console.ReadLine());

                        Triangle triangle2 = new Triangle(side);
                        Console.WriteLine("Треугольник 2:");
                        triangle2.DisplaySides();
                        Console.WriteLine("Периметр: " + triangle2.GetPerimeter());
                        Console.WriteLine("Площадь: " + triangle2.GetArea());
                        break;

                    default:
                        Console.WriteLine("Некорректный выбор.");
                        break;
                }
            }
            catch (ArgumentException ex)
            {
                Console.WriteLine(ex.Message);
            }
            catch (FormatException)
            {
                Console.WriteLine("Некорректный ввод. Пожалуйста, введите число.");
            }
        }

    }

}