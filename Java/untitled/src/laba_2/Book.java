package laba_2;

public class Book {
    private String title;
    private String author;
    private int year;
    private int pages;


    public Book() {
        title = "";
        author = "";
        year = 0;
        pages = 0;
    }

    public Book(String title, String author, int year, int pages) {
        title = title;
        author = author;
        year = year;
        pages = pages;
    }

    public String getTitle() {
        return title;
    }

    public String getAuthor() {
        return author;
    }

    public int getPages() {
        return pages;
    }

    public int getYear() {
        return year;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public void setYear(int year) {
        this.year = year;
    }

    public void setPages(int pages) {
        this.pages = pages;
    }

    public String toString() {
        return "Книга: " + title + "\n" +
                "Автор: " + author + "\n" +
                "Год издания: " + year + "\n" +
                "Количество страниц: " + pages;
    }
}