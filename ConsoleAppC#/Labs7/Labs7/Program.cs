namespace Labs7
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Book[] books = new Book[3];
            books[0] = new Book();
            books[0].SetBook("Author1", "Title1", 200, 2000);
            books[1] = new Book();
            books[1].SetBook("Author2", "Title2", 300, 1990);
            books[2] = new Book();
            books[2].SetBook("Author3", "Title3", 250, 2010);

            Array.Sort(books);

            foreach (Book book in books)
            {
                book.Show();
            }
        }
    }

    public class Book : IComparable
    {
        private string author;
        private string title;
        private int year;
        private int pages;

        public void SetBook(string author, string title, int pages, int year)
        {
            this.author = author;
            this.title = title;
            this.pages = pages;
            this.year = year;
        }
        public void Show()
        {
            Console.WriteLine("\nКнига:\n Автор: {0}\n Название: {1}\n Год издания: {2}\n {3} стр.\n", author, title, year, pages);
        }

        public int CompareTo(object obj)
        {
            Book it = (Book)obj;
            if (this.year == it.year) return 0;
            else if (this.year > it.year) return 1;
            else return -1;
        }
    }
}
