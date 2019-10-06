#pragma once
#include<string>
#include<iostream>
#include<stack>
#include "Infix_To_postfix.h"

using namespace std;

class Evaluator
{
public:

	/*
	This function is the main function of doing the evaluation part.
	it will take the posfix expression then it will start read it.
	@ parameter: expression
	*/
	void evaluate(string exp);

	/*
	This function will evaluate each operator separately.
	we make it bool in case there are two unary operators followed each other.
	@ parameters:	- the operator
	- tmp which represent if it is followed by another unary operator.
	*/
	bool evaluate_operator(char opr, bool tmp);

	/*
	Check if the character is operator or not.
	@ parameter: current character.
	*/
	bool CheckifOperator(char ops);

private:

	stack<int> operands;
	string expression;
};