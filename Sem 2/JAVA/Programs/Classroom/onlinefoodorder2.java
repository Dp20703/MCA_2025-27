
/* Design a Java program for an Online Food Delivery Platform using constructor and menu-driven approach.
Requirements: Constructor to initialize order ID, customer name, food item, price
Menu options:
1. Place Order
2. Update Order Price
3. Display Order Details
4. Exit*/
import java.util.Scanner;

class foodorder {
	int order_ID;
	String customer_name;
	String food_item;
	float price;

	foodorder() {
		order_ID = 0;
		customer_name = "";
		food_item = "";
		price = 0.0f;
	}

	foodorder(int orderID, String customername, String fooditem, float fprice) {
		order_ID = orderID;
		customer_name = customername;
		food_item = fooditem;
		price = fprice;
	}

	void updateorder(float newprice) {

		price = newprice;
	}

	void displayorder() {
		System.out.println("orderid: " + order_ID +
				"\ncustomer name: " + customer_name +
				"\nfooditem: " + food_item +
				"\nfood price: " + price);
	}
}

class onlinefoodorder2 {
	public static void main(String args[]) {
		foodorder o1 = new foodorder(); // default constuctor
		while (true) {
			System.out.println("Menu options:\n");
			System.out.println("1. Place Order");
			System.out.println("2. Update Order Price");
			System.out.println("3. Display Order Details");
			System.out.println("4. Exit");
			int choice;
			Scanner sc = new Scanner(System.in);
			choice = sc.nextInt();
			switch (choice) {
				case 1:
					System.out.println("You choose:" + choice);
					System.out.println("Place Your Order");

					Scanner order_detail = new Scanner(System.in);

					System.out.println("Enter Food id");
					int id = order_detail.nextInt();
					order_detail.nextLine();

					System.out.println("Enter Customer Name");
					String cname = order_detail.nextLine();

					System.out.println("Enter food Name");
					String fname = order_detail.nextLine();

					System.out.println("Enter Food price");
					float price = order_detail.nextFloat();
					o1 = new foodorder(id, cname, fname, price);
					break;
				case 2:
					System.out.println("You choose:" + choice);
					System.out.println("Update Your Order price");

					Scanner updated_order_detail = new Scanner(System.in);

					System.out.println("Update Food Price");
					float newprice = updated_order_detail.nextFloat();

					System.out.println("Updated Order");
					o1.updateorder(newprice);
					break;
				case 3:
					System.out.println("You choose:" + choice);
					System.out.println("display Your Order");

					System.out.println("orderid: " + o1.order_ID + "\ncustomer name: " + o1.customer_name
							+ "\nfooditem: " + o1.food_item + "\nfood price: " + o1.price);

					break;
				case 4:
					System.out.println("You choose:" + choice);
					System.out.println("Thank you for using Online Food Delivery Platform!");
					// break;
					return;
				default:
					System.out.println("You choose:" + choice);
					System.out.println("Invalid choice. Try again.");
			}
		}
	}

}
