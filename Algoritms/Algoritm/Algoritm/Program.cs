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
            double num = x;
            double oldx;

            do
            {
                oldx = num;
                num = (oldx + x/ oldx)/2;
            }
            while (Math.Abs(oldx - num)>0.1);

            return num;
        }

        static void Conclusion(double x)
        {
            Console.WriteLine("x = "+ x);
            Console.WriteLine("x^2 = " + (x*x));
        }
    }
}
