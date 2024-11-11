namespace ConsoleApp1;

public class Exercise4
{
    public static void Main(string[ ] args)
    {
        Console.WriteLine ("Please enter the first integer");
        int i = Convert.ToInt32(Console.ReadLine( ));
        Console.WriteLine("Please enter the second integer");
        int j = Convert.ToInt32(Console.ReadLine( ));
        int k = i / j;
        Console.WriteLine("The result of dividing {0} by {1} is {2}", i, j, k);
    }
}