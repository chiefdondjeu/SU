import java.util.Scanner;

public class MinOfThree {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner num = new Scanner(System.in);
		
		System.out.print("Enter the first number: " + '\t');
		int num1 = num.nextInt();
		System.out.print("Enter the second number: " + '\t');
		int num2 = num.nextInt();
		System.out.print("Enter the third number: " + '\t');
		int num3 = num.nextInt();
		
		num.close();
		
		if(num1 <= num2 && num1 <= num3) {
			System.out.print('\n' + "The minimum number is: " + num1);
		}
		
		else if (num2 <= num1 && num2 <= num3) {
			System.out.print('\n' + "The minimum number is: " + num2);
		}
		
		else if (num3 <= num1 && num3 <= num2) {
			System.out.print('\n' + "The minimum number is: " + num3);
		}
		
		else {
			System.out.print('\n' + "There was an error with your inputs. Please try with different numbers.");
			
		}
	}
	

}
