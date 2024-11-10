namespace Labs6
{
    internal class Program
    {
        public enum AccountType { Checking, Deposit }

        static void Main(string[] args)
        {
            Console.WriteLine("Hello, World!");
        }

        public class BankAccount
        {
            public void Populate(long number, decimal balance)
            {
                accNo = number;
                accBal = balance;
                accType = AccountType.Checking;
            }

            public long Number()
            {
                return accNo;
            }

            public decimal Balance()
            {
                return accBal;
            }

            public string Type()
            {
                return accType.ToString();
            }

            public static long NextNumver()
            {
                return nextAccNo++;
            }

            private long accNo;
            private decimal accBal;
            private AccountType accType;

            private static long nextAccNo;
        }
    }
}
