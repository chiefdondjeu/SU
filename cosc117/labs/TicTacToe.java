import java.util.Random;
import java.util.Scanner;

public class TicTacToe {

	private static Scanner keyboard = new Scanner(System.in);
	private static char[] board = new char[9];

	public static void main(String[] args) {
		System.out.println("Welcome to Tic-Tac-Toe!!");
		System.out.print("Would you like to play a game? (enter 'yes' or 'no'): ");
		char game=keyboard.next().charAt(0);
		
		while(game=='y') {
			if(game=='y'){
				playGame();
				if(isComputerWin()==true) {
					System.out.println("The computer wins!");
				}
				if(isHumanWin()==true) {
					System.out.println("You win!");
					//System.out.print("\n\nWould you like to play another game? (enter 'yes' or 'no'): ");
					//game=keyboard.next().charAt(0);
				}
				if(isTie()==true) {
					System.out.println("It's a tie!");
					//System.out.print("\n\nWould you like to play another game? (enter 'yes' or 'no'): ");
					//game=keyboard.next().charAt(0);
				}
				if(isDone()==true) {
					System.out.print("\n\nWould you like to play another game? (enter 'yes' or 'no'): ");
					game=keyboard.next().charAt(0);
				}
			}
		}
		System.out.println("Goodbye!");
	}

	private static void playGame() {
		char currentPlayer = determineFirstPlayer();
		System.out.println("The computer is X, the human is O.\n");
		initializeGameBoard();
		while (!isDone()) {
			if (currentPlayer == 'c') { // the computer
				processComputerMove();
				currentPlayer = 'h'; // the human
			} else {
				displayGameBoard();
				processHumanMove();
				currentPlayer = 'c'; // the computer
			}
		}
		displayGameBoard();
		System.out.println("\nGame over!");
	}

	private static char determineFirstPlayer() {
		System.out.print("\nWho should move first? (c=computer h=human): ");
		char player=keyboard.next().charAt(0);
		return player; // return 'c' or 'h'
	}

	private static void initializeGameBoard() {
		for(int i=0; i<board.length; i++) {
			board[i]=' ';
		}
	}

	private static void processComputerMove() {
		while(true) {
			int position = (int)(Math.random()*8);
			if(board[position]==' ') {
				System.out.println("The computer chooses cell "+ position+".");
				board[position]='X';
				//displayGameBoard();
				break;
			}
		}
	}

	private static void processHumanMove() {
		while(isDone()==false) {
			System.out.print("\nEnter an available position number (0-8): ");
			int position=keyboard.nextInt();
			if(position >=0&&position<=8) {
				if(board[position]==' ') {//||position<0||position>8
					board[position]='O';
					break;
					}
				else{
					System.out.println("Invalid move");
					}
			}
			else{
				System.out.println("Invalid move");
				}
		}
	}

	private static void displayGameBoard() {
		System.out.println(" ");
		System.out.println(board[0]+"  | "+board[1]+" | "+board[2]);
		System.out.println("---+---+---");
		System.out.println(board[3]+"  | "+board[4]+" | "+board[5]);
		System.out.println("---+---+--- ");
		System.out.println(board[6]+"  | "+board[7]+" | "+board[8]);
	}

	private static boolean isDone() {
		if(isComputerWin()==true) {
			return true;
		}
		if(isHumanWin()==true) {
			return true;
		}
		if(isTie()==true) {
			return true;
		}
		return false; // return true or false as appropriate
	}
	
	private static boolean isComputerWin() {
		if(board[0]=='X'&&board[1]=='X'&&board[2]=='X') {
			return true;
		}
		if(board[3]=='X'&&board[4]=='X'&&board[5]=='X') {
			return true;
		}
		if(board[6]=='X'&&board[7]=='X'&&board[8]=='X') {
			return true;
		}
		if(board[0]=='X'&&board[3]=='X'&&board[6]=='X') {
			return true;
		}
		if(board[1]=='X'&&board[4]=='X'&&board[7]=='X') {
			return true;
		}
		if(board[2]=='X'&&board[5]=='X'&&board[8]=='X') {
			return true;
		}
		if(board[0]=='X'&&board[4]=='X'&&board[8]=='X') {
			return true;
		}
		if(board[2]=='X'&&board[4]=='X'&&board[6]=='X') {
			return true;
		}
		return false; // return true or false as appropriate
	}

	private static boolean isHumanWin() {
		if(board[0]=='O'&&board[1]=='O'&&board[2]=='O') {
			return true;
		}
		if(board[3]=='O'&&board[4]=='O'&&board[5]=='O') {
			return true;
		}
		if(board[6]=='O'&&board[7]=='O'&&board[8]=='O') {
			return true;
		}
		if(board[0]=='O'&&board[3]=='O'&&board[6]=='O') {
			return true;
		}
		if(board[1]=='O'&&board[4]=='O'&&board[7]=='O') {
			return true;
		}
		if(board[2]=='O'&&board[5]=='O'&&board[8]=='O') {
			return true;
		}
		if(board[0]=='O'&&board[4]=='O'&&board[8]=='O') {
			return true;
		}
		if(board[2]=='O'&&board[4]=='O'&&board[6]=='O') {
			return true;
		}
		return false; // return true or false as appropriate
	}

	private static boolean isTie() {
		boolean isNotDone=false;
		for(int i=0; i<board.length;i++) {
			if(board[i]==' ') {
				isNotDone=true;
			}
		}
		if(isComputerWin()==false&&isHumanWin()==false&&isNotDone!=true) {
			return true;
		}
		return false;	// return true or false as appropriate
	}

}
