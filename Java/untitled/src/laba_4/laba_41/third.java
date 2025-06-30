package laba_4.laba_41;

import java.util.Scanner;

public class third {
    public third(){
        Scanner scanner = new Scanner(System.in);

        System.out.println("Введите первое число: ");
        int a = scanner.nextInt();

        System.out.println("Введите второе число: ");
        int b = scanner.nextInt();

        System.out.println("Введите третье число: ");
        int c = scanner.nextInt();

        boolean result = (a + b == c);
        System.out.println("Результат: " + result);
    }
}
