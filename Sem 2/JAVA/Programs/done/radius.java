import java.util.*;

public class radius {
	public static void main(String args[]) {

		double radius, area;

		System.out.println(" Enter the value of radius");
		Scanner sc = new Scanner(System.in);

		radius = sc.nextDouble();

		area = radius * radius * 3.14;
		System.out.println("area of the circle " + area);

	}
}