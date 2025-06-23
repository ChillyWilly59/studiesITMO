package laba_3;

public class Car {
    private String color;
    private String name;
    private double weight;


    public Car() {
        this.color = "";
        this.name = "";
        this.weight = 0;
    }

    public Car(String color) {
        this.color = color;
        this.name = "";
        this.weight = 0;
    }

    public Car(String color, double weight) {
        this.color = color;
        this.weight = weight;
        this.name = "";
    }

    public void setColor(String color) {
        this.color = color;
    }

    public void setWeight(double weight) {
        this.weight = weight;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void showInfo() {
        System.out.println("Название: " + name);
        System.out.println("Цвет: " + color);
        System.out.println("Вес: " + weight + " кг");
    }

    public static void main(String[] args) {
        Car car1 = new Car("Black", 2000);
        car1.setName("GAZ");
        car1.showInfo();


        Car car2 = new Car("Green");
        car2.setName("Lada");
        car2.setWeight(1000);
        car2.showInfo();

        Car car = new Car();
        car.showInfo();
    }
}
