import java.util.*;
public class Combinations {
	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		
		System.out.print("Enter the number of items (n): ");
		int n=input.nextInt();
		System.out.print("Enter the number of items to choose (k): ");
		int k=input.nextInt();
		
		int answer=combination(n,k);
		System.out.print("Total combinations: "+ answer);
		input.close();
	}
	public static int factorial(int x) {
		int f=1;
		for(int i=1;i<=x;i++) {
			f=f*i;
			}
		return f;
	}
	public static int combination(int n, int k){
		int c = factorial(n)/(factorial(k)*factorial(n-k));
		return c;
	}
}
