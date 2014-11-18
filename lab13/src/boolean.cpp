#include <iostream>
#include <fstream>
#include <string>
#include <locale> // for isalnum
#include "map.h"
#include "stack.h"

using namespace std;

// define a new enum to keep record of observed expression terms.
// this will be useful for error checking after stack::pop
enum class Term : short { empty = 0, var = 1, op = 2, tilde = 3, close = 4, open = 5 };

void initializeVariables(map<string, char>* variableMap, string filename)
{
	//open the variable file
	ifstream fin(filename.c_str());
	if (!fin.good()) throw logic_error("cannot open filename: " + filename);

	string key;
	char value;

	while (true)
	{
		//each line contains two items. The first being the key and the second being the boolean
		fin >> key;
		fin >> value;

		//see if reached end of file (fin >> a value after the file, so the loop will run one more time)
		//this is not put in the while statement because fin>> works a bit differently from getline
		//end of file will be true when fin>> gets the value after the last item, therefore it will run one extra time
		//if eof is put in the while statement
		if (fin.eof()) break;
		variableMap->add(key, value);
	}
	fin.close();
}

string convertToBoolean(string expression, map<string, char>* variableMap)
{
	string newExpression = "";

	//construct the number to put into map
	string variable = "";

	for (size_t i = 0; i < expression.size(); ++i)
	{
		if (isalnum(expression[i]))
		{
			//traverse through the string and get all the numbers
			for (size_t j = i; j < expression.size(); ++j, ++i) //we also want to increment i because we are moving the "cursor" along the expression
			{
				if (!isalnum(expression[i])) break;

				//expression[j] is a number. add it on to variable
				variable += expression[j];
			}

			//now set the new expression with the equivalent of the variable
			newExpression += variableMap->get(variable);

			//done with converting, reset variable
			variable.clear();

			//i is currently on an operator. Add it to the expression
			newExpression += expression[i];
		}
		else
		{
			//we want to set the expression's operators into the new expression
			newExpression += expression[i];
		}

	}

	return newExpression;
}

char booleanNot(char a)
{
	if (a != 'T' && a != 'F') throw logic_error("bad boolean input value");
	bool aa = a == 'T';
	return !aa ? 'T': 'F'; // conditional assignment operator
}

char booleanAlgebra(char a, char b, char op)
{
	if ((a != 'T' && a != 'F')  ||
	    (b != 'T' && b != 'F')) throw logic_error("bad boolean input value");
	if (op != '&' && op != '|') throw logic_error("bad boolean operator name");

	bool aa = a == 'T';
	bool bb = b == 'T';
	bool res;

	// calculate result
	if (op == '&') res = aa && bb;
	else res = aa || bb;

	return res ? 'T': 'F'; // conditional assignment operator
}

int main(int argv, char* argc[])
{
	//test to see if there are enough arguments
	if (argv != 3)
	{
		cout << "Error: Not enough arguments" << endl;
		cout << "       Run the program with: \"boolean <formula_file> <varaiable_file>\"" << endl;
		return -1;
	}

	map<string, char>* variableMap = new map<string, char>();

	// a general try to catch any unexpected error and print a user-friendly message
	try
	{
		//now make the map
		initializeVariables(variableMap, argc[2]);

		//open the formula file
		ifstream fin(argc[1]);
		if (!fin.good()) throw logic_error("cannot open filename: " + string(argc[1]));
		stack<char>* evaluateStack = nullptr;

		while (!fin.eof())
		{
			try
			{
				//have a string to store the expression
				string expression;

				getline(fin, expression);

				// skip empty line and comments in formula file
				if (expression.size() == 0 || expression[0] == '#') continue;

				//at any given point during the preprocessing, if an exception is thrown, it mean that
				//the expression is malformed.
				//first things first. Get rid of white spaces
				cout << "Raw formula: " << expression << endl;

				expression = convertToBoolean(expression, variableMap);
				cout << "  Converted: " << expression << endl;

				//now the expression is simplified. Evaluate using the stack with no worries

				//make a stack
				evaluateStack = new stack<char>();

				for (size_t i = 0; i < expression.size(); ++i)
				{
					// ignore white space
					if (expression[i] == ' ' || expression[i] == '\t') continue;

					//push as long as it's not a ')'
					if (expression[i] != ')')
					{
						evaluateStack->push(expression[i]);
						continue;
					}

					// it is a ), therefore start popping and evaluating
					char a = 0, b = 0, operate = 0;
					Term previousItem = Term::close;

					while (previousItem != Term::open)
					{
						if (evaluateStack->isEmpty()) throw logic_error("miss-matching parenthesis");
						char top = evaluateStack->top();
						evaluateStack->pop();

						switch (top)
						{
						case '~':
							if (previousItem != Term::tilde && previousItem != Term::var) throw logic_error("Tilde not expected");
							if      (a == 0) throw logic_error("Bad place for tilde");
							else if (b == 0) a = booleanNot(a);
							else             b = booleanNot(b);
							previousItem = Term::tilde;
							break;
						case '(':
							if (previousItem != Term::tilde && previousItem != Term::var) throw logic_error("Close parenthesis not expected");
							if (a == 0 || b == 0) throw logic_error("Not enough variable in parenthesis");
							a = booleanAlgebra(a, b, operate);
							b = 0; // not really needed but helps with debugging
							previousItem = Term::open;
							break;
						case '&':
						case '|':
							if (previousItem != Term::tilde && previousItem != Term::var) throw logic_error("Bad place for operator");
							if (operate != 0 && operate != top) throw logic_error("Operator not the same");
							operate = top;
							previousItem = Term::op;
							break;
						case 'T':
						case 'F':
							if (previousItem != Term::close && previousItem != Term::op) throw logic_error("Variable not expected");
							if      (a == 0) a = top;
							else if (b == 0) b = top;
							else // process a and b then store result as 'a'
							{
								a = booleanAlgebra(a, b, operate);
								b = top;
							}
							previousItem = Term::var;
							break;
						default: // it's an invalid input
							throw logic_error("invalid item in expression: " + top);
						}
					}
					// while loop finished so the results must be in 'a'
					evaluateStack->push(a);
				} // end for loop over characters of one expression

				// if there is only one item left, then that is the result.
				// pop off the first item and see if the stack is empty.
				// it can have tildes but nothing else.
				char res = evaluateStack->top();
				evaluateStack->pop();

				while (! evaluateStack->isEmpty() && evaluateStack->top() == '~')
				{
					evaluateStack->pop();
					res = booleanNot(res);
				}

				if (evaluateStack->isEmpty()) cout << "     Result: " << res << endl; //done!
				else throw logic_error("stack is not empty at the end of evaluation");
			}
			catch(const exception & ex)
			{
				cout << "     Result: Malformed. " << ex.what() << endl;
			}

			// release the stack if allocated. In case of early exception, the stack may not be allocated.
			if (evaluateStack)
			{
				delete evaluateStack;
				evaluateStack = nullptr;
			}
			cout << endl;
		} // end while loop over all expressions
	}
	catch(const exception & ex)
	{
		cout << "Error: " << ex.what() << endl;
	}
	delete variableMap;

	return 0;
}
