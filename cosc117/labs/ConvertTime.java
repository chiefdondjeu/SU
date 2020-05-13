import java.util.Scanner;
public class ConvertTime {
	public static void main (String[] args) {
		
		Scanner keyboard=new Scanner(System.in);
		System.out.print("Input the number of minutes: ");
		long min=keyboard.nextLong();
		keyboard.close();
		
		long hr=min/60;
		int day=(int)hr/24;
		int yr=0;
		
		while(day>365) {
			day-=365;
			yr++;
		}
		System.out.println(min+" minutes is: approximately "+yr+" years and "+day+" days");
	}

}
