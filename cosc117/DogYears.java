import java.util.Scanner;

public class DogYears {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner dg= new Scanner(System.in);
		
		System.out.print("How old is your dog? ");
		Double old = dg.nextDouble();
		
		Double age = 4 * (old - 2) + 21;
		System.out.print("Your dog is " + age + " in human years");
		
		dg.close();
	}

}
