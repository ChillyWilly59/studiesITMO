namespace Algoritm
{
    internal class Program
    {
        static void Main(string[] args)
        {
            double target = 2021;
            double res = Sqrt(target);
            Conclusion(res);
            Console.ReadKey();
        }

        static double Sqrt(double x)
        {
            double oldx = x;

            do
            {
                oldx = (oldx + x/ oldx)/2;
            }
            while (Math.Abs(oldx - (oldx + x / oldx) / 2) > 0.1);

            return oldx;
        }

        static void Conclusion(double x)
        {
            Console.WriteLine("x = "+ x);
            Console.WriteLine("x^2 = " + (x*x));
        }
    }
}
