import java.util.Scanner;

public class SimplePay {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner mn= new Scanner(System.in);
		
		System.out.print("Enter the hours worked: ");
		double hours = mn.nextDouble();
		
		System.out.print("Enter the pay rate per hour: ");
		double pay = mn.nextDouble();
		mn.close();
		
		double total = hours * pay;
		System.out.println("Total pay is $"+ total );
		
		
	}

}
