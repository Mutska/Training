/* Given a date, determine the day of the week of that day
 */
import java.util.*;

class Main {
	public static void main(String[] args) {
		String[] names = new String[]
		{ "", "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
	//We give 9 August 2010
	Calendar that_day = new GregorianCalendar(2010, 7, 9);
	//Note that month starts from 0, so we need to put 7 instead of 8
	System.out.println(names[that_day.get(Calendar.DAY_OF_WEEK)]);
	long today = new Date().getTime(); // today
	long diff = (today - that_day.getTime().getTime()) / (24*60*1000);
	
	System.out.println(diff + " day(s) ago");// ans grows over time	
	
	}
}
