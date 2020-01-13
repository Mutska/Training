/* Read in a double echo it, but with a minimum field
 * width of 7 and 3 digits after the decimal point.
 *
 * */
import java.util.*;

class Main {
	public static void  main(String[] args) {
		Scanner sc = new Scanner(System.in);
		double d = sc.nextDouble();
		System.out.printf("%7.3f\n", d);
	
	}
}
