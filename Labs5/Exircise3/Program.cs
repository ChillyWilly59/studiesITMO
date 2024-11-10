namespace Exircise3
{
    class Program
    {
        static void Main()
        {
            Console.Write("Введите размер массива: ");
            int size = int.Parse(Console.ReadLine());
            int[] array = new int[size];

            for (int i = 0; i < size; i++)
            {
                Console.Write($"Введите элемент {i}: ");
                array[i] = int.Parse(Console.ReadLine());
            }

            int sum = CalculateSum(array);
            double average = CalculateAverage(array);
            (int negativeSum, int positiveSum) = CalculateNegativeAndPositiveSum(array);
            (int oddSum, int evenSum) = CalculateOddAndEvenSum(array);
            (int maxValue, int maxIndex, int minValue, int minIndex) = FindMaxAndMin(array);
            int productBetweenMaxAndMin = CalculateProductBetweenMaxAndMin(array, maxIndex, minIndex);

            Console.WriteLine($"Сумма всех элементов массива: {sum}");
            Console.WriteLine($"Среднее значение массива: {average}");
            Console.WriteLine($"Сумма отрицательных элементов: {negativeSum}");
            Console.WriteLine($"Сумма положительных элементов: {positiveSum}");
            Console.WriteLine($"Сумма элементов с нечетными номерами: {oddSum}");
            Console.WriteLine($"Сумма элементов с четными номерами: {evenSum}");
            Console.WriteLine($"Максимальный элемент: {maxValue} (индекс: {maxIndex})");
            Console.WriteLine($"Минимальный элемент: {minValue} (индекс: {minIndex})");
            Console.WriteLine($"Произведение элементов между максимальным и минимальным элементами: {productBetweenMaxAndMin}");
        }

        static int CalculateSum(int[] array)
        {
            int sum = 0;
            foreach (int num in array)
            {
                sum += num;
            }
            return sum;
        }

        static double CalculateAverage(int[] array)
        {
            int sum = CalculateSum(array);
            return (double)sum / array.Length;
        }

        static (int negativeSum, int positiveSum) CalculateNegativeAndPositiveSum(int[] array)
        {
            int negativeSum = 0;
            int positiveSum = 0;
            foreach (int num in array)
            {
                if (num < 0)
                {
                    negativeSum += num;
                }
                else if (num > 0)
                {
                    positiveSum += num;
                }
            }
            return (negativeSum, positiveSum);
        }

        static (int oddSum, int evenSum) CalculateOddAndEvenSum(int[] array)
        {
            int oddSum = 0;
            int evenSum = 0;
            for (int i = 0; i < array.Length; i++)
            {
                if (i % 2 == 0)
                {
                    evenSum += array[i];
                }
                else
                {
                    oddSum += array[i];
                }
            }
            return (oddSum, evenSum);
        }

        static (int maxValue, int maxIndex, int minValue, int minIndex) FindMaxAndMin(int[] array)
        {
            int maxValue = array[0];
            int maxIndex = 0;
            int minValue = array[0];
            int minIndex = 0;

            for (int i = 1; i < array.Length; i++)
            {
                if (array[i] > maxValue)
                {
                    maxValue = array[i];
                    maxIndex = i;
                }
                if (array[i] < minValue)
                {
                    minValue = array[i];
                    minIndex = i;
                }
            }

            return (maxValue, maxIndex, minValue, minIndex);
        }

        static int CalculateProductBetweenMaxAndMin(int[] array, int maxIndex, int minIndex)
        {
            int startIndex = Math.Min(maxIndex, minIndex) + 1;
            int endIndex = Math.Max(maxIndex, minIndex);
            int product = 1;

            for (int i = startIndex; i < endIndex; i++)
            {
                product *= array[i];
            }

            return product;
        }
    }

}
