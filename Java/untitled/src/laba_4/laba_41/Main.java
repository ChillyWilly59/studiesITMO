package laba_4.laba_41;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        printOddNumbers();
        printDivisibleNumbers();

        Scanner scanner = new Scanner(System.in);

        System.out.println("\nЗадание 3: Проверка суммы двух чисел");
        System.out.print("Введите первое число: ");
        int a = scanner.nextInt();
        System.out.print("Введите второе число: ");
        int b = scanner.nextInt();
        System.out.print("Введите третье число: ");
        int c = scanner.nextInt();
        System.out.println("Результат: " + checkSum(a, b, c));

        System.out.println("\nЗадание 4: Проверка возрастающей последовательности");
        System.out.print("Введите первое число: ");
        int num1 = scanner.nextInt();
        System.out.print("Введите второе число: ");
        int num2 = scanner.nextInt();
        System.out.print("Введите третье число: ");
        int num3 = scanner.nextInt();
        System.out.println("Результат: " + isIncreasingSequence(num1, num2, num3));

        System.out.println("\nЗадание 5: Проверка первого/последнего элемента массива");
        int[] array1 = {3, -3, 7, 4, 5, 4, 3};
        System.out.println("Результат для массива 1: " + startsOrEndsWithThree(array1));
        int[] array2 = {1, 2, 3};
        System.out.println("Результат для массива 2: " + startsOrEndsWithThree(array2));

        System.out.println("\nЗадание 6: Проверка наличия 1 или 3 в массиве");
        int[] array3 = {5, 2, 4, 3};
        System.out.println("Результат для массива 3: " + containsOneOrThree(array3));
        int[] array4 = {0, 2, 4, 5};
        System.out.println("Результат для массива 4: " + containsOneOrThree(array4));

        scanner.close();
    }

    public static void printOddNumbers() {
        System.out.println("Задание 1: Нечетные числа от 1 до 99");
        for (int i = 1; i < 100; i += 2) {
            System.out.println(i);
        }
    }

    public static void printDivisibleNumbers() {
        System.out.println("\nЗадание 2: Числа, делящиеся на 3, 5 или оба");
        System.out.print("Делится на 3: ");
        for (int i = 1; i <= 100; i++) {
            if (i % 3 == 0 && i % 5 != 0) {
                System.out.print(i + " ");
            }
        }

        System.out.print("\nДелится на 5: ");
        for (int i = 1; i <= 100; i++) {
            if (i % 5 == 0 && i % 3 != 0) {
                System.out.print(i + " ");
            }
        }

        System.out.print("\nДелится на 3 и на 5: ");
        for (int i = 1; i <= 100; i++) {
            if (i % 15 == 0) {
                System.out.print(i + " ");
            }
        }
        System.out.println();
    }

    public static boolean checkSum(int a, int b, int c) {
        return (a + b) == c;
    }

    public static boolean isIncreasingSequence(int a, int b, int c) {
        return b > a && c > b;
    }

    public static boolean startsOrEndsWithThree(int[] array) {
        if (array == null || array.length < 2) {
            return false;
        }
        return array[0] == 3 || array[array.length - 1] == 3;
    }

    public static boolean containsOneOrThree(int[] array) {
        if (array == null) {
            return false;
        }
        for (int num : array) {
            if (num == 1 || num == 3) {
                return true;
            }
        }
        return false;
    }
}