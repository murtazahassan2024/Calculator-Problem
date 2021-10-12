#include "CalculatorUI.h"
#include <iostream>
#include <cstring>
#include <sstream>
#include "Calculator.h"
using namespace std;


bool isDouble(string value)
{
    try
    {
        stod(value);
        return true;
    }
    catch (const std::invalid_argument&) {}
    catch (const std::out_of_range&) {}
    return false;
}

vector<string> parseInput(string input)
{
    vector<string> commands;
    stringstream tokens(input);
    string token;
    while (getline(tokens, token, ' '))
    {
        try
        {
            bool valid = true;
            stod(token);
            for (size_t i = 0; i < token.length(); i++)
            {
                if (!isdigit(token[i]) && token[i] != '.')
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
            {
                commands.push_back(token);
                continue; // It's a number, move on to the next token
            }
        }
        catch (const std::invalid_argument&)
        {
            // not a number, ignore
        }
        catch (const std::out_of_range&)
        {
            // too big, ignore
        }

        bool foundCommand = false;
        for (int i = 0; i < NUMBER_OF_OPERATORS; i++)
        {
            if (token == operators[i])
            {
                commands.push_back(operators[i]);
                foundCommand = true;
                break;
            }
        }

        if (!foundCommand)
        {
            // wipe the commands, it was invalid
            commands.clear();
            break;
        }
    }
    return commands;
}

void runCalculator()
{
    std::cout << "Welcome to the Calculator\n";
    while (true)
    {
        std::cout << "calc>>:";
        string input;
        getline(cin, input);
        if (input == "quit" || input == "q")
        {
            break;
        }

        vector<string> commands = parseInput(input);
        if (commands.size() == 0)
        {
            cout << "Your command was invalid\n";
            cout << "Enter a valid post-fix expression to process or quit to end the program\n";
        }
        else
        {
            cout << processCommand(commands) << "\n";
        }
    }
}
