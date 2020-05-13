import java.util.*;
public class BankAccount {
	
	private double balance;
	
	public BankAccount() {
		balance=0;
	}
	public BankAccount(double InitialBalance) {
		balance=InitialBalance;
	}
	public double deposit(double dep) {
		return balance+=dep;
	}
	public double withdraw(double wit) {
		if(wit <= balance) {
			return balance-=wit;
			}
		else{
			return -1;
		}
	}
	public double getBalance() {
		return balance;
	}
	public static void main (String[] args) {
		
		Scanner input=new Scanner(System.in);
		System.out.print("What is your initial balance: ");
		double IB= input.nextDouble();
		System.out.print("How much would you like to deposit: ");
		double dep=input.nextDouble();
		System.out.print("How much would you like to withdraw: ");
		double wit=input.nextDouble();
		
		BankAccount florent=new BankAccount(IB);
		florent.deposit(dep);
		if(florent.withdraw(wit)>=0) {
			System.out.print("\nYour current balance is: "+ florent.withdraw(wit));
		}
		if(florent.withdraw(wit)==-1) {
			System.out.print("\nNot enough balance");
		}
		input.close();
	}

}
