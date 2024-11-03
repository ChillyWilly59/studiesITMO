namespace Exircise3
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(args.Length);

            foreach (string arg in args)
            {
                Console.WriteLine(arg);
            }
        }
    }
}
