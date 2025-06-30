package laba_4.laba_42;

import java.util.Arrays;

public class third {
    public static void swapFirstLast(){
        int[] arr = {76654132, 6,9,8,7,5,65,498,4652, 7, 16};
        System.out.println("Array 1: " + Arrays.toString(arr));

        int temp = arr[0];
        arr[0] = arr[arr.length - 1];
        arr[arr.length - 1] = temp;

        System.out.println("Array 2: " + Arrays.toString(arr));
    }
}
