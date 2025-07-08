package laba_6;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Client client = new Client("Иван", "Иванов", "Сбербанк");
        BankEmployee employee = new BankEmployee("Петр", "Петров", "ВТБ");
        client.infoOutput();
        System.out.println("\n");
        employee.infoOutput();

        System.out.println("\n");
        ClientWithInterface client2 = new ClientWithInterface("Анна", "Сидорова", "Тинькофф");
        client2.infoOutput();


        System.out.println("\n");
        Truck truck = new Truck(5000, "Volvo", 'B', 90.5f, 6, 10000);
        truck.outPut();
        truck.newWheels(10);


        System.out.println("\n");
        Child child = new Child(95);
        child.printNumber();


        System.out.println("\n");
        Scanner scanner = new Scanner(System.in);
        ExtendedUser user = new ExtendedUser();
        user.getName(scanner);
        user.getAge(scanner);
    }
}




