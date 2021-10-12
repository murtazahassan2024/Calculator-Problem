#pragma once
#include <string>
#include <vector>
using namespace std;

const string INVALID_MESSAGE = "Invalid Command";

/*
 * Process the list of commands (already validated for content) as a
 * calculator command.
 *    commands - the previously validated list of numbers and operators that may be a command
 *  returns a string of the calculated result or INVALID_MESSAGE if the command does not
 *          result in a single numerical answer
 */
string processCommand(vector<string> commands);
