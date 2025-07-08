package laba_6;

import java.util.Scanner;

public class ExtendedUser extends User {
    public void getName(Scanner sc) {
        System.out.print("Введите имя: ");
        String name = sc.next();
        System.out.println("Имя: " + name);
    }
}
