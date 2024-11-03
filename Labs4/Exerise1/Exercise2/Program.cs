namespace Exercise2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter first number");
            int x = int.Parse(Console.ReadLine());
            Console.WriteLine("Enter second number");
            int y = int.Parse(Console.ReadLine());

            Console.WriteLine("Before swap: " + x + "," + y);
            Utils.Swap(ref x, ref y);
            Console.WriteLine("Affter swap: " + x + "," + y);


        }


        public class Utils
        {
            public static void Swap(ref int a, ref int b)
            {
                int temp = a;
                a = b;
                b = temp;
            }
        }
    }
}
