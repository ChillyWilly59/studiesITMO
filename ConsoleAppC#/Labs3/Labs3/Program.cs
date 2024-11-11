namespace Labs3;

class Program
{
    private static void Main()
    {
        const int centerX = 0;
        const int centerY = 0;

        double[] radii = { 1, 2, 3 }; 
        int[] scores = { 10, 5, 1 };

        int totalScore = 0;

        Console.WriteLine("Игра началась! У вас 3 выстрела!");

        for (int i = 0; i < 3; i++)
        {
            Console.WriteLine($"\nВыстрел {i + 1}:");

            Console.WriteLine("Введите координату x:");
            int x = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine("Введите координату y:");
            int y = Convert.ToInt32(Console.ReadLine());

            double distance = Math.Sqrt(Math.Pow((x - centerX), 2) + Math.Pow((y - centerY), 2));

            int score = Shot(distance, radii, scores);
            totalScore += score;
        }

        Console.WriteLine($"\nВаш общий счет: {totalScore}");
    }

    private static int Shot(double distance, double[] radii, int[] scores)
    {
        for (int i = 0; i < radii.Length; i++)
        {
            if (distance <= radii[i])
            {
                Console.WriteLine($"Попадание в зону с радиусом {radii[i]} - {scores[i]} очков!");
                return scores[i]; 
            }
        }
        Console.WriteLine("Мимо! 0 очков.");
        return 0;
    }
}