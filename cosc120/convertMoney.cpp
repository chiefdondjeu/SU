#include <iostream>
#include <iomanip>
using namespace std;

// This program will input American money and convert it to foreign currency

// PLACE YOUR NAME HERE

// Prototypes of the functions
void convertMulti(float dollars, float& euros, float& pesos);
void convertMulti(float dollars, float& euros, float& pesos, float& yen);
float convertToYen(float dollars);
float convertToEuros(float dollars);
float convertToPesos(float dollars);

int main()
{
	float dollars;
	float euros;
	float pesos;
	float yen;

	cout << fixed << showpoint << setprecision(2);

	cout << "Please input the amount of American Dollars you want converted ";
	cout << "to euros and pesos" << endl;
	cin >> dollars;

	convertMulti(dollars, euros, pesos); // Fill in the code to call convertMulti with parameters dollars, euros, and pesos

	cout << "\n$" << dollars << " is converted to " << euros << " euros and " << pesos << " pesos\n" << endl;// Fill in the code to output the value of those dollars converted to both euros and pesos

	cout << "Please input the amount of American Dollars you want converted ";
	cout << "to euros,\npesos and yen" << endl;
	cin >> dollars;

	convertMulti(dollars,euros, pesos, yen); // Fill in the code to call convertMulti with parameters dollars, euros, pesos and yen

	cout << "\n$" << dollars << " is converted to " << euros << " euros, " << pesos << " pesos, and " << yen << " yen\n" <<endl;// Fill in the code to output the value of those dollars converted to euros, pesos and yen

	cout << "Please input the amount of American Dollars you want converted";
	cout << " to yen" << endl;
	cin >> dollars;

	yen = convertToYen(dollars); //convertToYen(dollars); // Fill in the code to call convertToYen

	cout << "$" << dollars << " is converted to " << yen << " yen\n" << endl;// Fill in the code to output the value of those dollars converted to yen

	cout << "Please input the amount of American Dollars you want converted";
	cout << " to euros" << endl;
	cin >> dollars;

	euros = convertToEuros(dollars); // Fill in the code to call convert ToEuros

	cout << "$" << dollars << "is converted to " << euros << " euros\n" << endl; // Fill in the code to output the value of those dollars converted to euros

	cout << "Please input the amount of American Dollars you want converted";
	cout << " to pesos " << endl;
	cin >> dollars;

	pesos = convertToPesos(dollars); // Fill in the code to call convertToPesos

	cout << "$" << dollars << " is converted to " << pesos << " pesos" << endl;// Fill in the code to output the value of those dollars converted to pesos

	return 0;
}

// All of the functions are stubs that just serve to test the functions
// Replace with code that will cause the functions to execute properly

//	**************************************************************************
//	convertMulti
//
//	task:	  This function takes a dollar value and converts it to euros
//	          and pesos
//	data in:  dollars
//	data out: euros and pesos
//
//	*************************************************************************

void convertMulti(float dollars, float& euros, float& pesos)
{
	//cout << "The function convertMulti with dollars, euros and pesos "
		 //<< endl << " was called with " << dollars << " dollars" << endl << endl;

	euros = dollars*1.06;
	pesos = dollars*9.73;

}

//	************************************************************************
//	convertMulti
//
//	task:	  This function takes a dollar value and converts it to euros
//	          pesos and yen
//	data in:  dollars
//	data out: euros pesos yen
//
//	***********************************************************************

void convertMulti(float dollars, float& euros, float& pesos, float& yen)
{
	//cout << "The function convertMulti with dollars, euros, pesos and yen"
		 //<< endl << " was called with " << dollars << " dollars" << endl << endl;

	euros = dollars*1.06;
	pesos = dollars*9.73;
	yen = dollars*124.35;

}

//	****************************************************************************
//	convertToYen
//
//	task:	       This function takes a dollar value and converts it to yen
//	data in:	   dollars
//	data returned: yen
//
//	***************************************************************************

float convertToYen(float dollars)
{
	//cout << "The function convertToYen was called with " << dollars << " dollars"
		 //<< endl << endl;

	return dollars*124.35;
}

//	****************************************************************************
//	convertToEuros
//
//	task:	       This function takes a dollar value and converts it to euros
//	data in:	   dollars
//	data returned: euros
//
//	****************************************************************************

float convertToEuros(float dollars)
{
	//cout << "The function convertToEuros was called with " << dollars
		 //<< " dollars" << endl << endl;

	return dollars*1.06;
}

//	*****************************************************************************
//	convertToPesos
//
//	task:	       This function takes a dollar value and converts it to pesos
//	data in:	   dollars
//	data returned: pesos
//
//	****************************************************************************

float convertToPesos(float dollars)
{
	//cout << "The function convertToPesos was called with " << dollars
		 //<< " dollars" << endl;

	return dollars*9.73;
}
