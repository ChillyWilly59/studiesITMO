package laba_4.laba_42;

import java.util.Scanner;
import java.util.Random;

public class Main {
    public static void main(String[] args) {

        int[] sortedArray = {1, 2, 3, 4, 5};
        int[] unsortedArray = {1, 3, 2, 4, 5};
        System.out.println("Проверка сортировки массива");
        System.out.println("Первый массив: " + checkArraySorted(sortedArray));
        System.out.println("Второй массив: " + checkArraySorted(unsortedArray));

        System.out.println("\nВвод массива с клавиатуры");
        int[] userArray = createArrayFromInput();
        System.out.println("Введенный массив: " + arrayToString(userArray));

        // Задание 3
        System.out.println("\nОбмен первого и последнего элемента");
        int[] array = {5, 6, 7, 2};
        System.out.println("Исходный массив: " + arrayToString(array));
        swapFirstAndLastElements(array);
        System.out.println("Измененный массив: " + arrayToString(array));

        // Задание 4
        System.out.println("\nПоиск первого уникального числа");
        int[] numbers = {1, 2, 3, 1, 2, 4};
        System.out.println("Первый уникальный элемент: " + findFirstUnique(numbers));

        // Задание 5
        System.out.println("\nСортировка слиянием");
        int[] randomArray = generateRandomArray(10);
        System.out.println("Исходный массив: " + arrayToString(randomArray));
        mergeSort(randomArray);
        System.out.println("Отсортированный массив: " + arrayToString(randomArray));
    }

    public static String checkArraySorted(int[] array) {
        for (int i = 0; i < array.length - 1; i++) {
            if (array[i] > array[i + 1]) {
                return "Please, try again";
            }
        }
        return "OK";
    }

    public static int[] createArrayFromInput() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Введите длину массива: ");
        int length = scanner.nextInt();

        int[] array = new int[length];
        System.out.println("Введите элементы массива:");
        for (int i = 0; i < length; i++) {
            array[i] = scanner.nextInt();
        }

        return array;
    }

    public static void swapFirstAndLastElements(int[] array) {
        if (array.length > 1) {
            int temp = array[0];
            array[0] = array[array.length - 1];
            array[array.length - 1] = temp;
        }
    }

    public static Integer findFirstUnique(int[] array) {
        for (int i = 0; i < array.length; i++) {
            boolean isUnique = true;
            for (int j = 0; j < array.length; j++) {
                if (i != j && array[i] == array[j]) {
                    isUnique = false;
                    break;
                }
            }
            if (isUnique) {
                return array[i];
            }
        }
        return null;
    }

    public static void mergeSort(int[] array) {
        if (array.length <= 1) return;

        int mid = array.length / 2;
        int[] left = new int[mid];
        int[] right = new int[array.length - mid];

        System.arraycopy(array, 0, left, 0, mid);
        System.arraycopy(array, mid, right, 0, array.length - mid);

        mergeSort(left);
        mergeSort(right);

        merge(array, left, right);
    }

    private static void merge(int[] result, int[] left, int[] right) {
        int i = 0, j = 0, k = 0;

        while (i < left.length && j < right.length) {
            if (left[i] <= right[j]) {
                result[k++] = left[i++];
            } else {
                result[k++] = right[j++];
            }
        }

        while (i < left.length) {
            result[k++] = left[i++];
        }

        while (j < right.length) {
            result[k++] = right[j++];
        }
    }

    private static int[] generateRandomArray(int size) {
        Random random = new Random();
        int[] array = new int[size];
        for (int i = 0; i < size; i++) {
            array[i] = random.nextInt(100);
        }
        return array;
    }

    private static String arrayToString(int[] array) {
        StringBuilder sb = new StringBuilder("[");
        for (int i = 0; i < array.length; i++) {
            sb.append(array[i]);
            if (i < array.length - 1) {
                sb.append(", ");
            }
        }
        sb.append("]");
        return sb.toString();
    }
}