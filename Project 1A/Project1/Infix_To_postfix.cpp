#include "Infix_To_postfix.h"
#include<iostream>
#include<string>
#include<stack>
#include <sstream>
using namespace std;

const string Infix_To_postfix::OPERATORS = "OAEUGgLl+-*/%^nDIN()[]{}"; // 24 
const int PRECEDENCE[] = { 1, 2, 3, 3, 4, 4, 4, 4, 5, 5, 6, 6, 6, 7, 8, 8, 8, 8,-1, -1, -1, -1, -1, -1 };
const string open = "([{";
const int OPEN[] = {1,2,3};
const string close = ")]}";
const string unary = "DInN";
const string binary = "OAEUGLgl";
const string single = "-+*/%^";


/*
the is function is going to convert the expression from infix to postfix.
@ parameter: the original expression
*/
void Infix_To_postfix::Convert(string& expression)
{
	expression = CheckExpression(expression);
	postfix_exprssion = "";
	string expression_token;
	std::istringstream read(expression);
	while (!operators_stack.empty())
	{
		operators_stack.pop();
	}
	while (read >> expression_token)
	{
		 if (isdigit(expression_token[0]))
		{
			postfix_exprssion += expression_token + " ";
		}
		else if (CheckifOperator(expression_token[0]))
		{
			ProcessOperators(expression_token[0]);
		}
		else
		{
			cout << "Error: There was an error while trying to read the expression: " << expression << endl;
			return ;
		}
	}
	while (!operators_stack.empty())
	{
		char temp_ops = operators_stack.top();
		operators_stack.pop();
		if (temp_ops == '(' || temp_ops == '[' || temp_ops == '{') {
			cout << "UnMached Error: There is an error with the parantheses!" << endl;
			return;
		}
		postfix_exprssion += temp_ops ;
	} 
	expression = postfix_exprssion;
}

/*
This function will check if the expression has any error, and also will take care of the binary operators.
by replaceing them with letters represent each of them.
@ parameter: the original expression from Convert function.
*/
string Infix_To_postfix::CheckExpression(string & expression)
{
	string new_expression = "";

	if (expression == "")
	{
		cout << "expression cannot br empty.\n";
		system("pause");
		exit(-1);
	}
	if (expression[0] == ')' || expression[0] == ']' || expression[0] == '}')
	{
		cout << "expression cannot start with closed parantheses @ char 0\n";
		system("pause");
		exit(-1);
	}
	else if (expression[0] == '<' && expression[1] == '='
		|| expression[0] == '>' && expression[1] == '='
		|| expression[0] == '!' && expression[1] == '='
		|| expression[0] == '=' && expression[1] == '='
		|| expression[0] == '|' && expression[1] == '|'
		|| expression[0] == '&' && expression[1] == '&'
		|| expression[0] == '<'
		|| expression[0] == '>'
		|| expression[0] == '=')
	{
		cout << "expression cannot start with binary character @ char 0\n";
		system("pause");
		exit(-1);
	}
	else if ((expression[0] == '+' && expression[0] != '+') || (expression[0] == '-' && expression[0] != '-') || expression[0] == '/' || expression[0] == '*' || expression[0] == '<' || expression[0] == '%')
	{
		cout << "expression cannot start with arithmetic character @ char 0\n";
		system("pause");
		exit(-1);
	}
	else {
		char prev_char = ' ';
		for (int i = 0; i < expression.size(); i++)
		{	
			if (expression[i] == ' ')
			{
				continue;
			}
			if (isdigit(expression[i]))
			{
				if (isdigit(expression[i]) && isspace(expression[i + 1]) && isdigit(expression[i + 2]))
				{
					cout << "Two operands in a row @ char " << i + 2 << endl;
					system("pause");
					exit(-1);
				}
				else {
					new_expression += expression[i];
					prev_char = expression[i];
				}
			}
			else if (expression[i] == '/' && expression[i + 1] == '0') {
				cout << "Error: Division by zero @ char " << i+1 << endl;
				system("pause");
				exit(-1);
			}
			else if (expression[i] == '|' && expression[i + 1] == '|')
			{
				if (unary.find(prev_char) != -1)
				{
					cout << "A unary operand can’t be followed by a binary operator @ char " << i << endl;
					system("pause");
				}
				else
				{
					new_expression += " O ";
					prev_char = 'O';
					++i;
				}
			}
			else if (expression[i] == '&' && expression[i + 1] == '&')
			{
				if (unary.find(prev_char) != -1)
				{
					cout << "A unary operand can’t be followed by a binary operator @ char " << i << endl;
					system("pause");
					exit(-1);
				}
				else if (binary.find(prev_char) != -1)
				{
					cout << "Two binary operators in a row @ char " << i << endl;
					system("pause");
					exit(-1);
				}
				else
				{
					new_expression += " A ";
					prev_char = 'A';
					++i;
				}
			}
			else if (expression[i] == '=' && expression[i + 1] == '=')
			{
				if (unary.find(prev_char) != -1)
				{
					cout << "A unary operand can’t be followed by a binary operator @ char " << i << endl;
					system("pause");
					exit(-1);
				}
				else
				{
					new_expression += " E ";
					prev_char = 'E';
					++i;
				}
			}
			else if (expression[i] == '!' && expression[i + 1] == '=')
			{
				if (unary.find(prev_char) != -1)
				{
					cout << "A unary operand can’t be followed by a binary operator @ char " << i << endl;
					system("pause");
					exit(-1);
				}
				else
				{
					new_expression += " U ";
					prev_char = 'U';
					++i;
				}
			}
			else if (expression[i] == '>' && expression[i + 1] == '=')
			{
				if (unary.find(prev_char) != -1)
				{
					cout << "A unary operand can’t be followed by a binary operator @ char " << i << endl;
					system("pause");
					exit(-1);
				}
				else
				{
					new_expression += " G ";
					prev_char = 'G';
					++i;
				}
			}
			else if (expression[i] == '>')
			{
				if (unary.find(prev_char) != -1)
				{
					cout << "A unary operand can’t be followed by a binary operator @ char " << i << endl;
					system("pause");
					exit(-1);
				}
				else
				{
					new_expression += " g ";
					prev_char = 'g';
				}
			}
			else if (expression[i] == '<' && expression[i + 1] == '=')
			{
				if (unary.find(prev_char) != -1)
				{
					cout << "A unary operand can’t be followed by a binary operator @ char " << i << endl;
					system("pause");
					exit(-1);
				}
				else
				{
					new_expression += " L ";
					prev_char = 'L';
					++i;
				}
			}
			else if (expression[i] == '<')
			{
				if (unary.find(prev_char) != -1)
				{
					cout << "A unary operand can’t be followed by a binary operator @ char " << i << endl;
					system("pause");
					exit(-1);
				}
				else
				{
					new_expression += " l ";
					prev_char = 'l';
				}
			}
			else if (expression[i] == '<')
			{
				if (unary.find(prev_char) != -1)
				{
					cout << "A unary operand can’t be followed by a binary operator @ char " << i << endl;
					system("pause");
					exit(-1);
				}
				else
				{
					new_expression += " l ";
					prev_char = 'l';
				}
			}
			else if (expression[i] == '-' && expression[i + 1] == '-')
			{

				new_expression += " D ";
				prev_char = 'D';
				++i;
			}
			else if (expression[i] == '+' && expression[i + 1] == '+')
			{

				new_expression += " I ";
				prev_char = 'I';
				++i;
			}
			else if (expression[i] == '-' && isdigit(expression[i + 1]) && !isdigit(prev_char))
			{

				new_expression += " n ";
				prev_char = 'n';
			}
			else if (expression[i] == '!')
			{

				new_expression += " N ";
				prev_char = 'N';
			}
			else if (single.find(expression[i]) != -1)
			{
				new_expression += " ";
				new_expression += expression[i];
				new_expression += " ";
				prev_char = expression[i];
			}
			else
			{
				if (close.find(expression[i]) != -1 || open.find(expression[i]) != -1)
				{
					new_expression += " ";
					new_expression += expression[i];
					new_expression += " ";

					prev_char = expression[i];
				}
				else
				{
					cout << "Error: Somthing went wrong.\n";
					system("pause");
					exit(0);
				}
			}
		}
	}
	return new_expression;
}

/*
this function will process operators (which one should come first)
@ parameter: the operator
*/
void Infix_To_postfix::ProcessOperators(char ops)
{
	if (operators_stack.empty() || (ops == '(') || (ops == '[') || (ops == '{'))
	{
		if (ops == ')' || ops == ']' || ops == '}')
		{
			cout << "Unmatched close parenthesis" << endl;
			system("pause");
		}
		operators_stack.push(ops);
	}
	else
	{
		if (precedence(ops) >= precedence(operators_stack.top()))
		{
			operators_stack.push(ops);
		}
		else
		{
			while ((!operators_stack.empty()) && precedence(ops) <= precedence(operators_stack.top()))
			{
				if ((operators_stack.top() == '(') || (operators_stack.top() == '[') || (operators_stack.top() == '{'))
				{
					break;
				}
				postfix_exprssion += operators_stack.top();
				postfix_exprssion += " ";
				operators_stack.pop();
			}

			if (ops == ')') {
				if (!operators_stack.empty() && (operators_stack.top() == '('))
				{
					operators_stack.pop();
				}
				else
				{
					cout << "Unmatched close parenthesis 1" << endl;
					system("pause");
				}
			}
			else if (ops == ']')
			{
				if (!operators_stack.empty() && (operators_stack.top() == '['))
				{
					operators_stack.pop();
				}
				else
				{
					cout << "Unmatched close parenthesis 2" << endl;
					system("pause");
				}
			}
			else if (ops == '}')
			{
				if (!operators_stack.empty() && (operators_stack.top() == '{'))
				{
					operators_stack.pop();
				}
				else
				{
					cout << "Unmatched close parenthesis 3" << endl;
					system("pause");
				}
			}
			else
			{
				operators_stack.push(ops);
			}
		}
	}
}

/*
return the weight of the operator.
@ parameter: the operator
*/
int Infix_To_postfix::precedence(char ops)
{
	return PRECEDENCE[OPERATORS.find(ops)] ;
}

/*
check if the character is operator or not.
@ parameter: current character.
*/
bool Infix_To_postfix::CheckifOperator(char ops)
{
	return OPERATORS.find(ops) != -1;
}