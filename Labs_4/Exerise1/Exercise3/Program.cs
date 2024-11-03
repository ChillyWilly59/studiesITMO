namespace Exercise3
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int f;
            bool ok;

            Console.WriteLine("Enter number for factorial:");
            int x = int.Parse(Console.ReadLine());
            //Console.WriteLine("Enter second number");
            //int y = int.Parse(Console.ReadLine());

            ok = Utils.Factorial(x, out f);
            if (ok) Console.WriteLine("Factorial(" + x + ") = " + f);
        }

        public class Utils
        {
            public static bool Factorial(int n, out int answer)
            {
                int k;
                int f;
                bool ok = true;

                if (n < 0) ok = false;

                try
                {
                    checked
                    {
                        f = 1;
                        for (k = 2; k <= n; k++)
                        {
                            f = f * k;
                        }
                    }
                }
                catch (Exception)
                {
                    f = 0;
                    ok = false;
                }
                answer = f;

                return ok;
            }
        }
    }
}
