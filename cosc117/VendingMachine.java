import java.util.Scanner;

public class VendingMachine {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner money = new Scanner(System.in);
		
		System.out.print("Enter bill Value (1= $1 bill, 5= $5 bill, ect.) ");
		double bill = money.nextDouble();
		
		System.out.print("Enter the number of quaters: ");
		double quaters = money.nextDouble();
		
		System.out.print("Enter the item price in pennies: ");
		double price = money.nextDouble();
		
		money.close();
		System.out.println();
		
		double bip = bill * 100;
		double qip = quaters * 25;
		double sumip = bip + qip;
		
		double change = sumip-price;
		
		int Dc = (int)change/100;
		System.out.println("Dollar coins: " + '\t' + Dc);
		
		int dtp = 100;
		int qtp = 25;
		
		double Q1 = change - (dtp * Dc);
		int Q2 = (int)Q1 / qtp;

		System.out.println("Quaters: " + '\t' + Q2);
		
		
	}

}
