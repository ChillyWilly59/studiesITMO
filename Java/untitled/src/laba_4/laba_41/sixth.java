package laba_4.laba_41;

public class sixth {
    public sixth() {
        int[] array = {5, 2, 4, 3};

        boolean result = false;
        for (int num : array) {
            if (num == 1 || num == 3) {
                result = true;
                break;
            }
        }

        System.out.println(result);
    }
}
