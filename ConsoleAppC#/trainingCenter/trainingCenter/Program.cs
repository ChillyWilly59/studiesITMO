namespace trainingCenter
{
    public abstract class Person
    {
        public string Surname { get; set; }
        public DateTime BirthDate { get; set; }

        public Person(string surname, DateTime birthDate)
        {
            Surname = surname;
            BirthDate = birthDate;
        }

        public int Age => DateTime.Now.Year - BirthDate.Year;

        public abstract void PrintInfo();
    }

    public interface IEmployee
    {
        decimal CalculateSalary();
        void PrintEmployeeInfo();
    }

    public class Administrator : Person, IEmployee
    {
        public string Laboratory { get; set; }

        public Administrator(string surname, DateTime birthDate, string laboratory)
            : base(surname, birthDate)
        {
            Laboratory = laboratory;
        }

        public decimal CalculateSalary()
        {
            return 50000m;
        }

        public override void PrintInfo()
        {
            Console.WriteLine($"Administrator: {Surname}, Age: {Age}, Laboratory: {Laboratory}");
        }

        public void PrintEmployeeInfo()
        {
            Console.WriteLine($"Administrator {Surname}, Salary: {CalculateSalary()}");
        }
    }
    public class Student : Person
    {
        public string Faculty { get; set; }
        public string Group { get; set; }

        public Student(string surname, DateTime birthDate, string faculty, string group)
            : base(surname, birthDate)
        {
            Faculty = faculty;
            Group = group;
        }

        public override void PrintInfo()
        {
            Console.WriteLine($"Student: {Surname}, Age: {Age}, Faculty: {Faculty}, Group: {Group}");
        }
    }

    public class Teacher : Person, IEmployee
    {
        public string Faculty { get; set; }
        public string Position { get; set; }
        public int Experience { get; set; }

        public Teacher(string surname, DateTime birthDate, string faculty, string position, int experience)
            : base(surname, birthDate)
        {
            Faculty = faculty;
            Position = position;
            Experience = experience;
        }

        public decimal CalculateSalary()
        {
            decimal baseSalary = 40000m;
            return baseSalary + (Experience * 1000); 
        }

        public override void PrintInfo()
        {
            Console.WriteLine($"Teacher: {Surname}, Age: {Age}, Faculty: {Faculty}, Position: {Position}, Experience: {Experience} years");
        }

        public void PrintEmployeeInfo()
        {
            Console.WriteLine($"Teacher {Surname}, Salary: {CalculateSalary()}");
        }
    }
    public class Manager : Person, IEmployee
    {
        public string Faculty { get; set; }
        public string Position { get; set; }

        public Manager(string surname, DateTime birthDate, string faculty, string position)
            : base(surname, birthDate)
        {
            Faculty = faculty;
            Position = position;
        }

        public decimal CalculateSalary()
        {
            return 45000m;
        }

        public override void PrintInfo()
        {
            Console.WriteLine($"Manager: {Surname}, Age: {Age}, Faculty: {Faculty}, Position: {Position}");
        }

        public void PrintEmployeeInfo()
        {
            Console.WriteLine($"Manager {Surname}, Salary: {CalculateSalary()}");
        }
    }

    class Program
    {
        static void Main()
        {
            List<Person> people = new List<Person>
        {
            new Administrator("Ivanov", new DateTime(1980, 5, 20), "Lab A"),
            new Student("Petrov", new DateTime(2000, 3, 15), "Engineering", "B1"),
            new Teacher("Sidorov", new DateTime(1975, 8, 10), "Mathematics", "Professor", 15),
            new Manager("Kuznetsova", new DateTime(1985, 12, 5), "Management", "Lead Manager")
        };

            foreach (var person in people)
            {
                person.PrintInfo();
                if (person is IEmployee employee)
                {
                    employee.PrintEmployeeInfo();
                }
                Console.WriteLine();
            }
        }
    }

}
