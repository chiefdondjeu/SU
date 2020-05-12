import java.util.Scanner;
public class IsEqual {
	public static void main (String[] args) {
		
		Scanner keyboard = new Scanner(System.in);
		System.out.print("Enter three integers seperated by space: ");
		int num1=keyboard.nextInt();
		int num2=keyboard.nextInt(); 
		int num3=keyboard.nextInt();
		keyboard.close();
		
		boolean t=true;
		boolean f=false;
		
		if(num1==num2 && num3==num2) {
			System.out.println("IsEqual: "+t);
		}
		else if(num1+num2==num3) {
			System.out.println("IsEqual: "+t);
		}
		else if(num1+num3==num2) {
			System.out.println("IsEqual: "+t);
		}
		else if(num2+num3==num1) {
			System.out.println("IsEqual: "+t);
		}
		else {
			System.out.println("IsEqual: "+f);
		}
		
		
	}

}
