namespace Exersice1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter first number");
            int x = int.Parse(Console.ReadLine());
            Console.WriteLine("Enter second number");
            int y = int.Parse(Console.ReadLine());

            int greater = Utile.Greater(x, y);
            Console.WriteLine("The greater value is " + greater);
        }

        class Utile
        {
            public static int Greater(int a, int b)
            {
                if (a > b)
                    return a;
                else return b;
            }
        }
    }
}
