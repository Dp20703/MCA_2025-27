
// Friend
class Friend {
    String name;
    String email;

    // Default constructor
    Friend() {
        name = "default";
        email = "default email";
    }

    // Parameterized constructor
    Friend(String name, String email) {
        this.name = name;
        this.email = email;
    }

    // Copy constructor
    Friend(Friend f) {
        this.name = f.name;
        this.email = f.email;
    }

    // Display
    void display() {
        System.out.println("Name:" + name);
        System.out.println("Email:" + email);
    }
}

// Buddy
class Buddy extends Friend {
    String dob;
    String mno;
    String address;

    Buddy() {
        super();
        dob = "default dob";
        mno = "default mno";
        address = "default address";
    }

    Buddy(String name, String email, String dob, String mno, String address) {
        super(name, email);
        this.dob = dob;
        this.mno = mno;
        this.address = address;
    }

    Buddy(Friend f, Buddy b) {
        super(f);
        this.dob = b.dob;
        this.mno = b.mno;
        this.address = b.address;
    }

    void display() {
        super.display();
        System.out.println("Dob:" + dob);
        System.out.println("Mobile no:" + mno);
        System.out.println("Address:" + address);
    }
}

public class Inheritance2 {
    public static void main(String[] args) {
        Friend f = new Buddy("tinal", "t@t.com", "10-05-79", "12345", "Ahmedabad");
        f.display();
    }
}
