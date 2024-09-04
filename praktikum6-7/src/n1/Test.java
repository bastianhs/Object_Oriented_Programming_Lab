import java.util.Scanner;

public class Test {
    public static void main(String[] args) {
        String input = new Scanner(System.in).next();
        try {
            new DataParser().parseEmail(input);
        } catch (InvalidEmailUserException | InvalidEmailDomainException e) {
            System.err.println(e.getMessage());
        }
    }
}
