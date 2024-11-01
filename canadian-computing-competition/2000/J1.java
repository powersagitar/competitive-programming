import java.util.Scanner;

public class Main {
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        final int startingDay = scanner.nextInt();
        final int daysInMonth = scanner.nextInt();

        System.out.println("Sun Mon Tue Wed Thr Fri Sat");
        System.out.print("    ".repeat(startingDay - 1));

        for (int i = 1, dayOfWeek = startingDay; i <= daysInMonth; ++i) {
            System.out.print(padLeft(String.valueOf(i), 3));

            if (dayOfWeek >= 7) {
                System.out.println();
                dayOfWeek = 1;
            } else if (i < daysInMonth) {
                System.out.print(" ");
                ++dayOfWeek;
            } else {
                System.out.println();
            }
        }
    }

    static String padLeft(String s, int n) {
        return String.format("%" + n + "s", s);
    }
}
