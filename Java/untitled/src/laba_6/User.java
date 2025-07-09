package laba_6;

import java.util.Scanner;

public class User {
    protected int age;

    public void getAge(Scanner sc) {
        System.out.print("Введите возраст: ");
        age = sc.nextInt();
        System.out.println("Возраст: " + age);
    }
}

