package laba_3;

public class Stydy {
    private final String course;

    public Stydy(String course) {
        this.course = course;
    }


    public String printCourse() {
        return this.course;
    }
}

class JavaProgram {
    public static void main(String[] args) {
        Stydy stydy = new Stydy("Изучение Java - это просто!");

        System.out.println(stydy.printCourse());
    }
}
