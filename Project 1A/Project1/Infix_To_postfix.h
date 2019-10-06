/*
Data Strucutre CS303
Project 1A

Group Memebers:
Noor Sakoki
Jingtang Ma
Feng Zheng
*/
#pragma once
#pragma once
#include<iostream>
#include<string>
#include<stack>

using namespace std;
class Infix_To_postfix
{
public:

	/*
	This function will check if the expression has any error, and also will take care of the binary operators.
	by replaceing them with letters represent each of them.
	@ parameter: the original expression from Convert function.
	*/
	string CheckExpression(string& expression);

	/*
	theis function is going to convert the expression from infix to postfix.
	@ parameter: the original expression
	*/
	void Convert(string& expression);

	/*
	this function will process operators (which one should come first)
	@ parameter: the operator
	*/
	void ProcessOperators(char ops);

	/*
	return the weight of the operator.
	@ parameter: the operator
	*/
	int precedence(char ops);

	/*
	check if the character is operator or not.
	@ parameter: current character.
	*/
	bool CheckifOperator(char ops);
	

private:
	static const std::string OPERATORS;
	string postfix_exprssion;
	stack<char> operators_stack;
};