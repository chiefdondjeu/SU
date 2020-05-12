import java.util.Scanner;
public class Passwords {
	public static void main (String[] args) {
		
		Scanner keyboard = new Scanner(System.in);
		
		//System.out.print("Enter your password: ");
		//String password = keyboard.nextLine();
		
		String password2, answerV, answerNM, answerS, answerNC, answerNc, answerND, answerGP;
		answerV = "The password is valid. Done!";
		answerNM = "The passwords doesn't match. Re-enter your passwords.";
		answerS = "The password is too short. Re-enter your passwords.";
		answerNC = "The password has no capital letter. Re-enter your passwords.";
		answerNc = "The password has no lower case letter. Re-enter your passwords.";
		answerND = "The password has no digital letter. Re-enter your passwords.";
		answerGP = "Good password. Done!";
		
		while(true) {
		
			int ii, ii2, cd, cd2, cap, lowcap, digit, NM, GP; 
			//ii=number of character cd=character in decimal NM=character that don't match in decimal
			ii=0;ii2=0;cap=0;lowcap=0;digit=0;NM=0;GP=0;
		
			System.out.print("Enter your password: ");
			String password = keyboard.nextLine();
			System.out.print("Re-enter your password: ");
			password2 = keyboard.nextLine();
		
			for (int i = 0; i < password.length(); i++) {
			password.charAt(i);
			ii=i;
			}
			for (int i2 = 0; i2 < password2.length(); i2++) {
			password2.charAt(i2);
			ii2=i2;
			}
			if (password.length()>=8) {//big if statement start
				while(password!=null) {
					for(int c=0; c<password.length(); c++) {
						cd=password.charAt(c); cd2=password2.charAt(c);
						//System.out.print(cd +" "+ cd2+ '\n');
						//cap=0;lowcap=0;digit=0;NM=0;GP=0;
						if(cd!=cd2) {
							NM++;
						}
						if(cd>=(int)'A' && cd<=(int)'Z') {
							//System.out.println("upcap");
							cap++;
						}
						if(cd>=(int)'a' && cd<=(int)'z') {
							//System.out.println("lowcap");
							lowcap++;
						}
						if(cd>=(int)'0' && cd<=(int)'9') {
							//System.out.println("digit");
							digit++;
						}
						if(cd==(int)'!'||cd==(int)'@'||cd==(int)'#'||cd==(int)'$'||cd==(int)'%'|| cd==(int)'&'|| cd==(int)'*') {
							GP++;
						}
					}//for loop end
					break;
				}//while loop end
				
				if(cap>0 && NM==0) {
					if(lowcap>0) {
						if(digit>0){
							if(GP==0) {
							System.out.print(answerV);
							break;
							}
							else if(GP>0) {
							System.out.print(answerGP);
							break;
							}
						}
						else if(digit==0) {
							System.out.print(answerND+'\n'+'\n');
						}
					}
					if(lowcap==0) {
					System.out.print(answerNc+'\n'+'\n');
					}
				}
				else if(cap==0) {
					System.out.print(answerNC+'\n'+'\n');
				}
				if(NM>0) {
					System.out.print(answerNM+'\n'+'\n');
				}
			}// big if statement end
		
			else if (ii != ii2) {
				System.out.print(answerNM+'\n'+'\n');
			}
			else if (ii < 8) {
				System.out.print(answerS+'\n'+'\n');
			}
			else {
				System.out.print(answerNM+'\n'+'\n');
			}
		
		}
		
	
	
	
	}//static end

}//class end
