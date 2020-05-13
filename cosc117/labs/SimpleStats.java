import java.util.Scanner;
public class SimpleStats {
	public static void main (String[] args) {
		
		Scanner keyboard = new Scanner(System.in);
		
		System.out.println("Enter a sequence of nonnegative numbers followed by -1: ");
		
		float num, max, min, c, avg, T;
		num = keyboard.nextInt();
		max=0;
		min=num;
		c=0;
		T=0;
		
		while(num!=-1) {
			T=T+num;
			if (num>max) {
				max=num;
			}
			else if(num<min) {
				min=num;
				}
			c++;
			num = keyboard.nextInt();
			}
		
		keyboard.close();
		avg= T/c;
		System.out.format("Min: %.2f\n", min);
		System.out.format("Max: %.2f\n", max);
		System.out.format("Avg: %.2f\n", avg);
		
		}
		
	}
