#pragma once
#include <string>
#include <vector>
using namespace std;

const string operators[] = {"+", "-", "*", "/", "^"};
const int NUMBER_OF_OPERATORS = sizeof(operators) / sizeof(operators[0]);

/*
* Check if a string value is indeed a double
*    value - the value to check
*  returns true if the number is a double, false otherwise
*/
bool isDouble(string value);

/*
 * Parse the input string and return a vector that includes only numbers and operators.
 * These are not validated as a valid calculator command they will only include valid
 * numbers and operators.
 *    input - an input from the user
 *  returns a vector of strings that are either numbers or operators, nothing else
 */
vector<string> parseInput(string input);

/*
 * Run the UI for the calculator
 */
void runCalculator();

