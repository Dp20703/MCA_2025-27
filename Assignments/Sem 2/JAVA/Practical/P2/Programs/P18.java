// Unit-8
// Q13

import java.time.LocalDate;
import java.time.LocalTime;

public class P18 {

    public static void main(String[] args) {

        // Get current date
        LocalDate currentDate = LocalDate.now();

        // Get current time
        LocalTime loginTime = LocalTime.now();

        // Display attendance message
        System.out.println(
                "Employee logged in on "
                        + currentDate
                        + " at "
                        + loginTime);
    }
}
