package laba_2;

public class Book
{
    private String title;
    private String author;
    private int year;
    private int pages;


    public Book()
    {
        title = " ";
        author = "";
        year = 0;
        pages = 0;
    }

    public Book(String title,String author, int year,int pages)
    {
        title = title;
        author = author;
        year = year;
        pages = pages;
    }
}
