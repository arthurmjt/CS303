#include "Postfix_Evaluator.h"
#include<iostream>
#include<string>
#include<stack>
#include <sstream>
#include<math.h>
using namespace std;

const string oprs = "OAEUGgLl+-*/%^nDIN()[]{}";
const string unary = "DInN";
const string binary = "OAEUGLgl";
const string single = "-+*/%^";

/*
This function is the main function of doing the evaluation part.
it will take the posfix expression then it will start read it.
@ parameter: expression
*/
void Evaluator::evaluate(string exp)
{
	if (exp == "")
	{
		cout << "Error: expression cannot be empty..." << endl;
		system("pause");
		exit(0);
	}

		Infix_To_postfix i;
		i.Convert(exp);

	istringstream read_exprresion(exp);
	char token;
	while (read_exprresion >> token)
	{
		if (isdigit(token))
		{
			read_exprresion.putback(token);
			int number;
			read_exprresion >> number;
			operands.push(number);
			
		}
		else if (CheckifOperator(token))
		{
			bool tmp = true;
			evaluate_operator(token, tmp);
			if (tmp == false)
			{
				read_exprresion.putback(token);
			}
		}
		else
		{
			cout << "Error...\n";
			system("pause");
			exit(0);
		}	
	}
	if (!operands.empty())
	{
		int finalResult = operands.top();
		operands.pop();
		if (!operands.empty())
		{
			cout << "Error: Stack should only have final result!\n";
		}
		else
		{
			cout << finalResult << endl;
		}
	}
	else
	{
		cout << "Error: The stack is empty, but it should have the final.\n";
		system("pause");
		exit(0);
	}
}

/*
This function will evaluate each operator separately.
we make it bool in case there are two unary operators followed each other.
@ parameters:	- the operator
				- tmp which represent if it is followed by another unary operator.
*/
bool Evaluator::evaluate_operator(char opr,bool tmp)
{
	// evalute unary operators here.
	if (unary.find(opr) != -1)
	{
		if (!operands.empty())
		{
			int num = operands.top();
			operands.pop();
			//DINn
			switch (opr)
			{
			case 'D':
				operands.push(--num);
				tmp = false;
				break;

			case 'I':
				operands.push(++num);
				tmp = false;

				break;

			case 'N':
				operands.push(!num);
				break;

			case 'n':
				operands.push(0 - num);
				break;
			default:
				break;
			}
		}
		else
		{
			return tmp;
		}
	}

	// evalute binary operators here.
	else if (binary.find(opr) != -1)
	{
		
		int rhs = operands.top();
		operands.pop();
		if (operands.empty())
		{
			cout << "Error: Stack cannot be empty." << endl;
			system("pause");
			exit(0);
		}
		int lhs = operands.top();
		operands.pop();
		switch (opr)
		{
			//OAEUGLgl
		case 'O':
			operands.push(lhs || rhs);
				break;

		case 'A':

			operands.push(lhs && rhs);
			break;
		case 'E':

			operands.push(lhs == rhs);
			break;
		case 'U':

			operands.push(lhs != rhs);
			break;
		case 'G':

			operands.push(lhs >= rhs);
			break;
		case 'L':

			operands.push(lhs <= rhs);
			break;
		case 'g':

				operands.push(lhs > rhs);
				break;
		case 'l':

			operands.push(lhs < rhs);
			break;

		default:
			break;
		}

	}

	// evalute single operators here.
	else if (single.find(opr) != -1)
	{
		int rhs = operands.top();
		operands.pop();
		if (operands.empty())
		{
			cout << "Error: Stack cannot be empty." << endl;
			system("pause");
			exit(0);
		}
		int lhs = operands.top();
		operands.pop();
		switch (opr)
		{
		case '+':
			operands.push(lhs + rhs);
			break;
		case '-':
			operands.push(lhs - rhs);
			break;
		case '*':
			operands.push(lhs * rhs);
			break;
		case '/':
			if (rhs == 0)
			{
				cout << "Error: Division by zero." << endl;
				system("pause");
				exit(-1);
			}
			else
			{
				operands.push(lhs / rhs);
			break;
		}
		case '%':
			operands.push(lhs % rhs);
			break;
		case '^':
			operands.push(pow(lhs,rhs));
			break;

		default:
			break;
		}
	}
	// in case there is unrecognized operator!
	else
	{
		cout << "Error: cannot recognize the operator.\n";
		system("pause");
		exit(0);
	}
	return tmp;
}

/*Check if the character is operator or not.
@ parameter: current character.
*/
bool Evaluator::CheckifOperator(char ops)
{

	for (int i = 0; i < oprs.size(); i++)
	{
		if (ops == oprs[i])
		{
			return true;
		}
	}
	return false;
}

