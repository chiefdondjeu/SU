#include <iostream>
using namespace std;

int main()
{
	int h, m;
	char colon, unit[2];
	cout << "Enter a time: ";
	cin >> h >> colon >> m >> unit;
	cout << "**********/nResult:" << endl;
	cout << h << endl;
	cout << colon << endl;
	cout << m << endl;
	cout << unit << endl;

	return 0;
}