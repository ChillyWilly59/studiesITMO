package laba_4.laba_41;

import java.util.Scanner;

public class fourth {
    public fourth(){
        Scanner scanner = new Scanner(System.in);

        System.out.println("Введите первое число: ");
        int a = scanner.nextInt();

        System.out.println("Введите второе число: ");
        int b = scanner.nextInt();

        System.out.println("Введите третье число: ");
        int c = scanner.nextInt();

        boolean result = (b>a && c > b);
        System.out.println("Результат: " + result);

    }
}
