import java.util.Scanner;
public class Passwords {
	public static void main (String[] args) {
		
		Scanner keyboard = new Scanner(System.in);
		
		System.out.print("Enter your password: ");
		String password = keyboard.nextLine();
		
		String password2, answerV, answerNM, answerS, answerNC, answerNc, answerND;
		answerV = "The password is valid. Done!";
		answerNM = "The passwords doesn't match. Re-enter your passwords.";
		answerS = "The password is too short. Re-enter your passwords.";
		answerNC = "The password has no capital letter. Re-eneter your passwords.";
		answerNc = "The password has no lower case letter. Re-enter your passwords.";
		answerND = "The password has no digital letter. Re-enter your passwords.";
		
		int i, i2, c, cd, cd2, cap, lowcap, digit, NM; // i=c=number of character cd=character in decimal NM=character that don't match in decimal
		cap=0;lowcap=0;digit=0;NM=0;
		
		System.out.print("Re-enter your password: ");
		password2 = keyboard.nextLine();
		
		for (i = 0; i < password.length(); i++) {
			password.charAt(i);
		}
		for (i2 = 0; i2 < password2.length(); i2++) {
			password2.charAt(i2);
		}
		if (i == i2 && i >= 8) {//big if statement start
			while(password!=null) {
				for(c=0; c<i; c++) {
					cd=password.charAt(c); cd2=password2.charAt(c);		//System.out.print(cd +" "+ cd2+ '\n');
					if(cd!=cd2) {
						NM++;
					}
					if(cd>=(int)'A' && cd<=(int)'Z') {
						cap++;				//System.out.println("upcap");
					}
					if(cd>=(int)'a' && cd<=(int)'z') {
						lowcap++;			//System.out.println("lowcap");
					}
					if(cd>=(int)'0' && cd<=(int)'9') {
						digit++;			//System.out.println("digit");
					}
				}//for loop end
				break;
			}//while loop end
				if(cap>0 && NM==0) {
					if(lowcap>0) {
						if(digit>0){
							System.out.print(answerV);
						}
						else if(digit==0) {
							System.out.print(answerND);
						}
					}
					if(lowcap==0) {
					System.out.print(answerNc);
					}
				}
				else if(cap==0) {
					System.out.print(answerNC);
				}
				if(NM>0) {
					System.out.print(answerNM);
				}
		}// big if statement end
		
		else if (i != i2) {
			System.out.print(answerNM);
		}
		else if (i < 8) {
			System.out.print(answerS);
		}
		else {
			System.out.print(answerNM);
		}
		
		keyboard.close();
	
	
	
	}//static end

}//class end
