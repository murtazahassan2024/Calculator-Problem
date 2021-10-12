#include <iostream>
#include "Calculator.h"
#include "CalculatorUI.h"
#include "helper/TestHelper.h"

string BASIC_TEST_CASES[][2] =
{ {"2 2 +","4.000000"},
  {"2 2 -","0.000000"},
  {"2 2 *","4.000000"},
  {"2 2 /","1.000000"},
  {"2 2 ^","4.000000"}};

string COMPOUND_TEST_CASES[][2] =
{ {"4 8 3 * +","28.000000"},
  {"4 8 + 3 *","36.000000"},
  {"78 30 0.5 28 8 + * - 6 / +","80.000000"},
  {"2.1 2 ^ 5.2 + 7.2 - 7.1 *","17.111000"},
  {"2 20 * 2 / 3 4 + 3 2 ^ * + 6 - 15 +","92.000000"}};

string INVALID_TEST_CASES[][2] =
{ {"2 + 2", INVALID_MESSAGE},
  {"2 2 2 +", INVALID_MESSAGE}};

string runTests(string tests[][2], int n, string error)
{
	string results;
    for (int testCase = 0; testCase < n; testCase++)
    {
        string input = tests[testCase][0];
        string expected = tests[testCase][1];
        string actual = processCommand(parseInput(input));
        results += checkEquals(actual, expected, input, error);
    }
    return results;
}

/*
* A tester for the processCommand() function
* Many test cases taken from or validated using...
* https://www.free-online-calculator-use.com/postfix-evaluator.html#
*/
bool testCalculator(string subtest)
{
    string results;

    if (subtest == "all")
    {
        results += runTests(BASIC_TEST_CASES, 5, "Basic Test Case Failed");
        results += runTests(COMPOUND_TEST_CASES, 5, "Compound Test Case Failed");
        results += runTests(INVALID_TEST_CASES, 2, "Invalid Test Case Failed");
    } else if (subtest == "basic")    { results += runTests(BASIC_TEST_CASES, 5, "Basic Test Case Failed");
	} else if (subtest == "compound") {results += runTests(COMPOUND_TEST_CASES, 5, "Compound Test Case Failed");
	} else if (subtest == "invalid")  { results += runTests(INVALID_TEST_CASES, 5, "Invalid Test Case Failed");
	} else {results += "Invalid subtest";}

    if (results.size() == 0)
    {
    	cout << "All Test Passed!\n";
    	return true;
    } else
    {
    	cout << results;
        return false;
    }
}
