package laba_5;

public class Main {

    public static void main(String[] args) {

        System.out.println("1. Самое длинное слово: " + findLongestWord("Это тестовый текст для проверки"));
        System.out.println("2. Является ли 'казак' палиндромом: " + isPalindrome("казак"));
        System.out.println("3. Цензура: " + censorBaka("Не говори бяка! Бяка это плохо."));
        System.out.println("4. Количество вхождений 'aba' в 'ababababa': " +
                countSubstringOccurrences("ababababa", "aba"));
        System.out.println("5. Инвертированные слова:");
        String input = "This is a test string";
        System.out.println("Исходная строка: " + input);
        System.out.println("Результат: " + reverseWords(input));
    }

    public static String findLongestWord(String text) {
        String[] words = text.split("\\s+");
        String longestWord = "";
        for (String word : words) {
            if (word.length() > longestWord.length()) {
                longestWord = word;
            }
        }
        return longestWord;
    }

    public static boolean isPalindrome(String word) {
        String cleanWord = word.replaceAll("\\s+", "").toLowerCase();
        int length = cleanWord.length();
        for (int i = 0; i < length / 2; i++) {
            if (cleanWord.charAt(i) != cleanWord.charAt(length - 1 - i)) {
                return false;
            }
        }
        return true;
    }


    public static String censorBaka(String text) {
        return text.replaceAll("бяка", "[вырезано цензурой]");
    }

    public static int countSubstringOccurrences(String text, String substring) {
        int count = 0;
        int lastIndex = 0;
        while (lastIndex != -1) {
            lastIndex = text.indexOf(substring, lastIndex);
            if (lastIndex != -1) {
                count++;
                lastIndex += substring.length();
            }
        }
        return count;
    }

    public static String reverseWords(String str) {
        String[] words = str.split(" ");
        StringBuilder reversedString = new StringBuilder();
        for (String word : words) {
            StringBuilder reversedWord = new StringBuilder(word).reverse();
            reversedString.append(reversedWord).append(" ");
        }
        return reversedString.toString().trim();
    }
}