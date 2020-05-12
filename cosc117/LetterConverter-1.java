import java.util.Scanner;

public class LetterConverter {

	public static void main(String[] args) {
		
		Scanner character = new Scanner (System.in);
		
		System.out.print("Enter a letter: ");
		char letter = character.next().charAt(0);
		character.close();
		
		int dec = (int)letter;
		int num = 32;
		int ll = dec+num;
		int ul = dec-num;
		
		if(letter >= 65 && letter <= 122) {
			if(letter <= 90) {
				System.out.print(letter + " is converted to: " + (char)ll );	
			}
			else {
				System.out.print(letter + " is converted to: " + (char)ul);
			}
		}
		else {
			System.out.print(letter + " : not a valid letter.");
		}

	}

}
