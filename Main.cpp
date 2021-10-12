#include "Calculator.h"
#include "CalculatorUI.h"
#include "CalculatorTest.h"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		testCalculator(argv[1]);
	} else
	{
		testCalculator("all");
		cout << "\nTest Cases Completed - running Calculator UI\n.............................................\n";
		runCalculator();
	}
	return 0;
}
