import java.util.Scanner;
public class SumDigits {
	public static void main (String[] args) {
		
		Scanner keyboard=new Scanner(System.in);
		System.out.print("Input an integer between 0 and 1000: ");
		int num1=keyboard.nextInt();
		keyboard.close();
		
		if(num1<=99) {
			int digit2=num1%10;
			int num2=num1-digit2;
			int digit1=num2/10;
			System.out.print("Sum of digits: "+ (digit1+digit2));
		}
		else if(num1>99 && num1<999) {
			int digit3=num1%10;
			int num2=num1-digit3;
			int num3=num2%100;
			int digit2=num3/10;
			int num4=num2-num3;
			int digit1=num4/100;
			System.out.print("Sum of digits: "+ (digit1+digit2+digit3));	
		}
		else {
			System.out.print("Sum of digits: 1");
		}
		
	}

}
