
namespace ConsoleApp1;

abstract class Exercise5
{
    private static void Main()
    {
        Console.WriteLine("Введите сторону равностороннего треугольника:");

        double side = Convert.ToDouble(Console.ReadLine());

        double p = side * 3 / 2;

        double s = Math.Sqrt(p * (p - side) * (p - side) * (p - side));

        Console.WriteLine("Сторона\tПлощадь");
        Console.WriteLine($"{side}\t{s:F2}");
        Console.ReadKey();
    }
}