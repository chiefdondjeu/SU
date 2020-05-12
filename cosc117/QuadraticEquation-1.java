import java.util.*;
public class QuadraticEquation {
	private double a;
	private double b;
	private double c;
	public QuadraticEquation() {
	 	a=0.0;
		b=0.0;
		c=0.0;
	}
	public QuadraticEquation(double x, double y, double z) {
		a=x;
		b=y;
		c=z;
	}
	public double geta() {
		return a;
	}
	public double getb() {
		return b;
	}
	public double getc() {
		return c;
	}
	public double getDiscriminant() {	//method
		double discriminant=b*b;
		discriminant-=4*a*c;
		return discriminant;
	}
	public double getRoot1() {
		double r1=-b+Math.sqrt(getDiscriminant());
		return r1/=2*a;
	}
	public double getRoot2() {
		double r2=(-b)-Math.sqrt(getDiscriminant());
		return r2/=2*a;
	}
	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		System.out.print("Enter a value for a: ");
		double x=input.nextDouble();
		System.out.print("Enter a value for b: ");
		double y=input.nextDouble();
		System.out.print("Enter a value for c: ");
		double z=input.nextDouble();
		input.close();
		QuadraticEquation formula=new QuadraticEquation(x,y,z);
		if(formula.getDiscriminant()>=0) {
			if(formula.getDiscriminant()>0) {
				System.out.print("\nRoot1: "+formula.getRoot1()+"\nRoot2: "+formula.getRoot2());
			}
			if(formula.getDiscriminant()==0) {
			System.out.println("\nThere is only one real root\nRoot: "+formula.getRoot1());
			}
		}
		if(formula.getDiscriminant()<0) {
			System.out.println("\nThere are no real roots.");
		}
	}

}
