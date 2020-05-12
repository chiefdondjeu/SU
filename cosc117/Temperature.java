import java.util.Scanner;

public class Temperature {

	public static void main(String[] args) {
		double[] temps = readTemps();
		System.out.printf("\nThe average temperature is %.2f", averageTemp(temps));
		System.out.printf("\nThe highest temperature is %.2f", highestTemp(temps));
		System.out.printf("\nThe lowest temperature is %.2f\n", lowestTemp(temps));
		System.out.println("\nThe above statistics are based on the following temperatures:");
		printTemps(temps);
	}

	public static double[] readTemps() {
		Scanner input = new Scanner(System.in);
		System.out.print("Enter the number of temperatures: ");
		int numTemps = input.nextInt();
		double[] temps = new double[numTemps];
		System.out.println("Please enter " + temps.length + " temperatures: ");
		for (int i = 0; i < temps.length; i++) {
			temps[i] = input.nextDouble();
		}
		input.close();
		return temps;
	}

	public static double highestTemp(double[] num) {
		double hightemp = 0;
		for (int i = 0; i < num.length; i++) {
			if (num[i] > hightemp) {
				hightemp = num[i];
			}
		}
		return hightemp;
	}

	public static double lowestTemp(double[] num) {
		double lowtemp = num[0];
		for (int i = 1; i < num.length; i++) {
			if (num[i] < lowtemp) {
				lowtemp = num[i];
			}
		}
		return lowtemp;
	}

	public static double averageTemp(double[] num) {
		double avgtemp = 0;
		for (int i = 0; i < num.length; i++) {
			avgtemp += num[i];
		}
		avgtemp /= num.length;
		return avgtemp;
	}

	public static void printTemps(double[] temps) {
		for (int i = 0; i < temps.length; i++) {
			System.out.printf(" %.2f", temps[i]);
		}
	}

}
