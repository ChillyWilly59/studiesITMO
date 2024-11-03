namespace Labs4;

class Exercise4
{
    static void Main(string[] args)
    {
        Console.WriteLine("Выберите тип треугольника (1 - равносторонний, 2 - произвольный): ");
        int choice = int.Parse(Console.ReadLine());

        if (choice == 1)
        {
            Console.Write("Введите длину стороны: ");
            double side = double.Parse(Console.ReadLine());
            double area = Operation.TriangleSqr(side);
            Console.WriteLine($"Площадь равностороннего треугольника: {area}");
        }
        else if (choice == 2)
        {
            Console.Write("Введите длины сторон a, b, c через пробел: ");
            string[] sidesInput = Console.ReadLine().Split();
            double a = double.Parse(sidesInput[0]);
            double b = double.Parse(sidesInput[1]);
            double c = double.Parse(sidesInput[2]);

            try
            {
                double area = Operation.Geron(a, b, c);
                Console.WriteLine($"Площадь треугольника: {area}");
            }
            catch (ArgumentException ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
        else
        {
            Console.WriteLine("Некорректный выбор типа треугольника.");
        }

    }
}

public class Operation
{
    public static double Geron(double x, double y, double z)
    {
        double Sqrt;

        double p = (x + y + z) / 2;

        Sqrt = Math.Sqrt(p * (p - x) * (p - y) * (p - z));

        return Sqrt;
    }

    private static bool Treangle(int x, int y, int z)
    {
        if (x + y > z && x + z > y && z + y > x)
            return true;
        else return false;
    }

    public static double TriangleSqr(double side)
    {
        double p = side * 3 / 2;
        double s = Math.Sqrt(p * Math.Pow((p - side), 3));
        return s;
    }
}