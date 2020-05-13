import java.util.*;
public class Tower {
	
	private double cx;
	private double cy;
	private double radius;
	
	public Tower(double x, double y, double r){
		cx=x;
		cy=y;
		radius=r;	
	}
	public boolean inRange(double x0, double y0) {
		double range=Math.sqrt(((x0-cx)*(x0-cx))+((y0-cy)*(y0-cy)));
		if(range<= radius) {
			return true;
		}
		else {
			return false;
		}
	}
	public double getX() {
		return cx;
	}
	public double getY() {
		return cy;
	}
	public double getR() {
		return radius;
	}
	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		
		System.out.print("What is the x-coordinate of the tower: ");
		double x= input.nextDouble();
		System.out.print("What is the y-coordinate of the tower: ");
		double y= input.nextDouble();
		double r= Math.sqrt((x*x)+(y*y));
		System.out.print("The radius is: "+ r);
		
		Tower florent=new Tower(x,y,r);
		System.out.print("\n\nEnter a x-coordinate: ");
		double x0= input.nextDouble();
		System.out.print("Enter a y-coordinate: ");
		double y0= input.nextDouble();
		if(florent.inRange(x0,y0)==true) {
			System.out.print("\nThe coordinate is in range");
		}
		else{
			System.out.print("\nThe coordinate is not in range");
		}
		input.close();
	}
	

}
