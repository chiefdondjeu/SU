#include <iostream>
#include <string>
#include "ex9Aux.h"
#include "time24.h"

int main()
{
	accumulator <int> test(5);
	int val = 10;

	while(val <= 30)
	{
		test.addValue(val);
		std :: cout << test.getTotal() << " ";
		val += 5;
	}
	std :: cout << "\n";

	
	accumulator <std :: string> test2(std :: string("3071740 "));
	test2.addValue(std :: string("Florent Dondjeu "));
	//std :: cout << test2.getTotal() << std :: endl;

	test2.addValue(std :: string("Computer Science "));
	std :: cout << test2.getTotal() << std :: endl;

	accumulator <time24> test3(time24(4,30)); //4:30
	time24 t1(13,15), t2(1,45), t3(16,0);

	test3.addValue(t1);
	std :: cout << test3.getTotal();
	
	test3.addValue(t2);
	std :: cout << test3.getTotal();

	test3.addValue(t3);
	std :: cout << test3.getTotal() << std :: endl;

	return 0;
}