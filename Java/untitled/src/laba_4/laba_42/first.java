package laba_4.laba_42;

public class first {
    public static void sort(){
        int[] arr = {1, 3, 5, 7};

        boolean isSorted = true;
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] < arr[i - 1]) {
                isSorted = false;
                break;
            }
        }

        if (isSorted) {
            System.out.println("OK");
        } else {
            System.out.println("Please, try again");
        }
    }
}
