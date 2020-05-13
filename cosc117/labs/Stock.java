//import java.util.*;
public class Stock {
	
	private String symbol;	//instance variable
	private String name;
	private Double previousClosingPrice;
	private Double currentPrice;
	public Stock() {	//default constructor
		symbol = "none";
		name = "none";
		previousClosingPrice = 0.0;
	}
	public Stock(String s, String n, double pCP) {	//Constructor
		symbol = s;
		name = n;
		previousClosingPrice = pCP;
	}
	public void currentPrice(double price) {	//instance method
		currentPrice = previousClosingPrice;
	}
	public double getChangePercent() {	//method
		double ChangePercent = currentPrice; 
		ChangePercent -= previousClosingPrice;
		previousClosingPrice*=previousClosingPrice;
		Math.sqrt(previousClosingPrice);
		ChangePercent/= previousClosingPrice;
		ChangePercent*=100;
		return ChangePercent;
	}
	public static void main(String[] args) {
		Stock company = new Stock("ORCL", "Oracle Corporation", 34.5); 
		System.out.println("Symbol: "+ company.symbol);
		System.out.println("Name: "+company.name);
		System.out.println("Previous Closing Price: "+ company.previousClosingPrice);
		company.currentPrice(34.5);
		System.out.println("Price-change: "+ company.getChangePercent());
	}

}
