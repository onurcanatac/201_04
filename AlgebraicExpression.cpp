//Onurcan Ataç, 22002194
#include "AlgebraicExpression.h"
#include <iostream>
#include <cstdlib>
#include <stdio.h>

#include <sstream>

bool isOperator(string current)
{
	if (current == "+" || current == "-" || current == "*" || current == "/" || current == "^" ) // || current == "(" || current == ")"
	{
		return true;
	}
	else
	{
		return false;
	}
}

int precedence(string current)
{
	//if (current == ")")
		//return 4;

	if (current == "^")
		return 2;

	else if (current == "*" || current == "/")
		return 1;

	else if (current == "+" || current == "-")
		return 0;

	//else if (current == "(")
		//return 0;
	else
	{
		return -1;
	}
}

// It converts an infix expression exp to its equivalent postfix form.
string infix2postfix(const string exp)
{
	Stack stack;
	string postfix;

	string current = "";
	//current += exp.substr(i, 1);

	for (int i = 0; i < exp.size(); i++)
	{
		if (i + 1 == exp.size() || exp.substr(i + 1, 1) == " " || exp.substr(i, 1) == " ")
		{
			current += exp.substr(i, 1);

			if (current == " ")
			{
				if (i != 0 && postfix != "" && postfix[postfix.size() - 1] != ' ')
				{
					postfix += " ";
				}
			}
			else if (!isOperator(current) && current != "(" && current != ")") //&& current != " "
			{
				postfix += current;
			}

			else if (current == "(")
			{
				stack.push(current);
			}

			else if (current == ")")
			{
				string curTop;
				stack.getTop(curTop);

				while (curTop != "(")
				{
					postfix += curTop;
					stack.pop();
					stack.getTop(curTop);
				}
				stack.pop(); //remove the open paranthesis
			}

			else if (isOperator(current))
			{
				string checker;

				if (!stack.isEmpty())
				{
					stack.getTop(checker);//fix these
				}

				while (!stack.isEmpty() && precedence(current) <= precedence(checker))
				{
					postfix += checker;
					stack.pop();
					if (!stack.isEmpty())
					{
						stack.getTop(checker);
					}
				}
				stack.push(current);
			}

			if (i == exp.size() - 1)
			{
				string current;

				while (!stack.isEmpty())
				{
					stack.getTop(current);
					postfix += " " + current;
					stack.pop();

				}
			}

			current = "";
		}
		else
		{
			current += exp.substr(i, 1);
		}

	}
	return postfix;
}

// It converts a postfix expression exp to its equivalent prefix form.
string postfix2prefix(const string exp)
{
	Stack stack;
	string current = "";

	for (int i = 0; i < exp.size(); i++)
	{
		if (i + 1 == exp.size() || exp.substr(i + 1, 1) == " " || exp.substr(i, 1) == " ")
		{
			current += exp.substr(i, 1);

			if (current == " ")
			{
				current = "";
				continue;
			}
			else if (!isOperator(current) && current != "(" && current != ")")
			{
				stack.push(current);
			}
			else
			{
				string operFirst, operSecond;

				stack.getTop(operSecond);
				stack.pop();

				stack.getTop(operFirst);
				stack.pop();

				stack.push(current + " " + operFirst + " " + operSecond);
			}

			current = "";
		}

		else
		{
			current += exp.substr(i, 1);
		}
	}
	string prefix;
	stack.getTop(prefix);

	return prefix;
}


// It converts a prefix expression exp to its equivalent infix form.
string prefix2infix(const string exp)
{
	Stack stack;
	string current = "";

	for (int i = exp.size() - 1; i >= 0; i--)
	{

		if (i == 0 || exp.substr(i-1, 1) == " " || exp.substr(i, 1) == " ")
		{
			current = exp.substr(i, 1) + current;

			if (current == " ")
			{
				current = "";
				continue;
			}
			else if (!isOperator(current) && current != "(" && current != ")")
			{
				stack.push(current);
			}
			else
			{
				string operFirst, operSecond;

				stack.getTop(operSecond);
				stack.pop();

				stack.getTop(operFirst);
				stack.pop();

				if (i != 0 && precedence(current) == 0 )// ikisi de toplama veya çýkartma olduðunda gereksiz parantez oluyor
				{
					//if (bracketsUsed == false)
					
					stack.push("( " + operSecond + " " + current + " " + operFirst + " )");
					

					//bracketsUsed = true;
				}
				else
				{
					stack.push(operSecond + " " + current + " " + operFirst);
				}	
			}

			current = "";
		}

		else
		{
			current = exp.substr(i, 1) + current;
		}
	}
	string infix;
	stack.getTop(infix);

	return infix;
}

// It converts an infix expression exp to its equivalent prefix form.
string infix2prefix(const string exp)
{
	return postfix2prefix(infix2postfix(exp));
}

// It converts a prefix expression exp to its equivalent postfix form.
string prefix2postfix(const string exp)
{
	return infix2postfix(prefix2infix(exp));
}

// It converts a postfix expression exp to its equivalent infix form.
string postfix2infix(const string exp)
{
	return prefix2infix(postfix2prefix(exp));
}

//It evaluates a postfix expression.
double evaluatePostfix(const string exp)
{
	Stack stack;
	string current = "";

	for (int i = 0; i < exp.size(); i++)
	{
		if (i + 1 == exp.size() || exp.substr(i + 1, 1) == " " || exp.substr(i, 1) == " ")
		{
			current += exp.substr(i, 1);

			if (current == " ")
			{
				current = "";
				continue;
			}

			else if (!isOperator(current) && current != "(" && current != ")")
			{
				stack.push(current);
			}

			else
			{
				string operFirst, operSecond;
				double result;

				stack.getTop(operSecond);
				stack.pop();

				stack.getTop(operFirst);
				stack.pop();
				
				double opSecond = strtod(operSecond.c_str(), NULL);
				double opFirst = strtod(operFirst.c_str(), NULL);
				//int curOperator;

				if (current == "+")
				{
					result = opFirst + opSecond;
				}
				
				if (current == "-")
				{
					result = opFirst - opSecond;
				}

				if (current == "*")
				{
					result = opFirst * opSecond;
				}

				if (current == "/")
				{
					result = opFirst / opSecond;
				}

				//string resultt;

				//stringstream res(result);
				//res >> resultt;

				stringstream ss;
				ss << result;

				stack.push(ss.str());
			}

			current = "";
		}

		else
		{
			current += exp.substr(i, 1);
		}
	}
	string postEval;
	stack.getTop(postEval);

	double evaluation = strtod(postEval.c_str(), NULL);

	return evaluation;
	
}

//It evaluates an infix expression.
double evaluateInfix(const string exp)
{
	return evaluatePostfix(infix2postfix(exp));
}

//It evaluates a prefix expression.
double evaluatePrefix(const string exp)
{
	return evaluatePostfix(prefix2postfix(exp));
}