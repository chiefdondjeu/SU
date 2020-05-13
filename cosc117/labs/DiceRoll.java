
public class DiceRoll {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int DiceRoll = (int)(Math.random()*6)+1;
		int DiceRoll2 = (int)(Math.random()*6)+1;
		int DiceRoll3 = DiceRoll + DiceRoll2;

		System.out.println("The first die comes up" + " " + DiceRoll);
		System.out.println("The second die comes up" + " " + DiceRoll2);
		System.out.println("Your total roll is" + " " + DiceRoll3);
	}

}
