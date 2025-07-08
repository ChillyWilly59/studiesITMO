package laba_6;

public class Truck extends Car {
    public int wheels;
    public int maxWeight;

    public Truck(int w, String m, char c, float s, int wheels, int maxWeight) {
        super(w, m, c, s);
        this.wheels = wheels;
        this.maxWeight = maxWeight;
    }

    public void newWheels(int newCount) {
        this.wheels = newCount;
        System.out.println("Новое количество колес: " + wheels);
    }
}
