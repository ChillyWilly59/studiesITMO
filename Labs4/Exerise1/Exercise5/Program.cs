namespace Labs4._5;

using System;

public class QuadraticEquationSolver
{
    public static int FindRoots(double a, double b, double c, out double x1, out double x2)
    {
        x1 = x2 = 0;

        if (a == 0)
        {
            throw new ArgumentException("Коэффициент 'a' не может быть равен нулю.");
        }

        double discriminant = b * b - 4 * a * c;

        if (discriminant > 0)
        {
            x1 = (-b + Math.Sqrt(discriminant)) / (2 * a);
            x2 = (-b - Math.Sqrt(discriminant)) / (2 * a);
            return 1;
        }
        else if (discriminant == 0)
        {
            x1 = x2 = -b / (2 * a);
            return 0;
        }
        else
        {
            return -1;
        }
    }
}

public class Program
{
    public static void Main(string[] args)
    {
        Console.Write("Введите коэффициенты a, b, c через пробел: ");
        string[] coefficientsInput = Console.ReadLine().Split();

        double a = double.Parse(coefficientsInput[0]);
        double b = double.Parse(coefficientsInput[1]);
        double c = double.Parse(coefficientsInput[2]);

        double x1, x2;

        try
        {
            int result = QuadraticEquationSolver.FindRoots(a, b, c, out x1, out x2);
            switch (result)
            {
                case 1:
                    Console.WriteLine($"Корни уравнения с коэффициентами a = {a}, b = {b}, c = {c} один: x1 = {x1}, x2 = {x2}");
                    break;
                case 0:
                    Console.WriteLine($"Корни уравнения с коэффициентами a = {a}, b = {b}, c = {c} равны: x1 = x2 = {x1}");
                    break;
                case -1:
                    Console.WriteLine($"Корней уравнения с коэффициентами a = {a}, b = {b}, c = {c} нет.");
                    break;
            }
        }
        catch (ArgumentException ex)
        {
            Console.WriteLine(ex.Message);
        }
    }
}
