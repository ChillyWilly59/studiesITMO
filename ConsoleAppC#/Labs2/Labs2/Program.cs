namespace Labs2
{

    struct Distanse
    {
        public int feet;
        public int inch;

        public Distanse(int feet, int inch)
        {
            this.feet = feet;
            this.inch = inch;
        }
        public static Distanse operator +(Distanse d1, Distanse d2)
        {
            int totalFeet = d1.feet + d2.feet; 
            int totalInches = d1.inch + d2.inch; 

            if (totalInches >= 12)
            {
                totalFeet += totalInches / 12; 
                totalInches = totalInches % 12; 
            }

            return new Distanse(totalFeet, totalInches);
        }

        public override string ToString()
        {
            return $"{feet}' {inch}\"";
        }
    }
    internal class Program
    {
        static void Main(string[] args)
        {
            Distanse d1, d2, d3;

            // Ввод первых значений
            Console.WriteLine("Введите первое расстояние (футы и дюймы):");
            Console.Write("Футы: ");
            int feet1 = int.Parse(Console.ReadLine());
            Console.Write("Дюймы: ");
            int inch1 = int.Parse(Console.ReadLine());
            d1 = new Distanse(feet1, inch1);

            // Ввод вторых значений
            Console.WriteLine("Введите второе расстояние (футы и дюймы):");
            Console.Write("Футы: ");
            int feet2 = int.Parse(Console.ReadLine());
            Console.Write("Дюймы: ");
            int inch2 = int.Parse(Console.ReadLine());
            d2 = new Distanse(feet2, inch2);

            d3 = d1 + d2;

            Console.WriteLine($"Сумма: {d3}");
        }
    }
}
