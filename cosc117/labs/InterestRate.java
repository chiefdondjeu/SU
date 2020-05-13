import java.util.Scanner;

public class InterestRate {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner deposit = new Scanner (System.in);
		
		System.out.print("Time left on deposit: ");
		double year = deposit.nextDouble();
		
		deposit.close();
		
		int num1 = 1;
		int num2 = 2;
		int num3 = 3;
		int num4 = 4;
		int num5 = 5;
		
		if(year >= num5) {
		System.out.print("Your interest rate is: 0.0475");
		}
		else if(year < num5 && year >= num4) {
			System.out.print("Your interest rate is: 0.045");
		}
		else if(year < num4 && year >= num4) {
			System.out.print("Your interest rate is: 0.040");
		}
		else if(year < num3 && year >= num2) {
			System.out.print("Your interest rate is: 0.035");
		}
		else if(year < num2 && year >= num1) {
			System.out.print("Your interest rate is: 0.030");
		}
		else if(year < num1) {
			System.out.print("Your interest rate is: 0.025");
		}
	
	}

	
}
