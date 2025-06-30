package laba_4.laba_42;

public class fourth {
    public static void firstUnique() {
        int[] arr = {1, 2, 3, 1, 2, 4};

        for (int i = 0; i < arr.length; i++) {
            boolean isUnique = true;
            for (int j = 0; j < arr.length; j++) {
                if (i != j && arr[i] == arr[j]) {
                    isUnique = false;
                    break;
                }
            }
            if (isUnique) {
                System.out.println("First unique: " + arr[i]);
                return;
            }
        }

        System.out.println("No unique number found.");
    }
}
