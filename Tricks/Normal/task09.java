/* Given a string that represents a base X number, convert it to an equivalent string in base Y, 2 <= X. Y <= 36.
 * For example: "FF" in base X = 16 (hexadecimal) is "255" in base
 * Y = 10 (decimal) and "11111111" in base Y = 2 (binary).
 * */
import java.math.*;

class Main {
	public static void main(String[] args){
		String str = "FF"; int X = 16, Y = 10;
		System.out.println(new BigInteger(str, X).toString(Y));
	
	}
	

}
