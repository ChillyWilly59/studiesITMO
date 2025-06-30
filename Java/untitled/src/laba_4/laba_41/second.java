package laba_4.laba_41;

public class second {
    public second() {
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
            if (i % 3 == 0 && i % 5 == 0) {
                System.out.print(i + " ");
            }
        }
    }
}
