
package laba_1;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        first();
        second();
        third();
        fourth();
        fifth();
        sixth();
    }

    public static void first() {
        System.out.println("Я\nхорошо\nзнаю\nJava ");
    }

    public static void second() {
        int result1 = ((46 + 10) * (10 / 3));
        int result2 = (29) * (4) * (-15);

        System.out.printf("(46+10)*(10/3) = %s\n" +
                "(29)*(4)*(-15) = %s%n", result1, result2);
    }

    public static void third() {
        int number = 10500;
        int result = (number / 10) / 10;

        System.out.println(result);
    }

    public static void fourth() {
        double x = 3.6;
        double y = 4.1;
        double z = 5.9;
        double result = x * y * z;
        System.out.println(result);
    }

    public static void fifth() {
        Scanner a = new Scanner(System.in);

        int num_1 = a.nextInt();
        int num_2 = a.nextInt();
        int num_3 = a.nextInt();

        System.out.printf("%s\n%s\n%s%n", num_1, num_2, num_3);
    }

    public static void sixth() {
        Scanner scanner = new Scanner(System.in);

        int b = scanner.nextInt();

        if (b % 2 != 0) {
            System.out.println("нечетное");
        } else {
            if (b > 100) {
                System.out.println("выход за пределы диапозона");
            } else {
                System.out.println("четное");
            }
        }

        scanner.close();
    }
}
