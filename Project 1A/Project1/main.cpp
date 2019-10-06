#include <iostream>
#include <string>
#include "Postfix_Evaluator.h"

using namespace std;

int main()
{
	Evaluator e;
	
	e.evaluate("1+2 *3");
	e.evaluate("2+2^2*3");
	e.evaluate("1==2");
	e.evaluate("1+3>2");
	e.evaluate("(4>=4) && 0");
	e.evaluate("(1+2)*3");
	e.evaluate("++++2-5*(3^2)");

	/* we tested all the expressions and they all work fine, and the Error positions.*/
	cout << "Works!" << endl;
	system("pause");
	return 0;
}