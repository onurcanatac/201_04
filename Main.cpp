//Onurcan Ata�, 22002194
#include "AlgebraicExpression.h"

int main()
{
	//driver file
	cout << infix2prefix("( 17 + 5 ) - 25 / 5") << endl;
	cout << infix2postfix("( 17 + 5 ) - 25 / 5") << endl;
	cout << evaluateInfix("( 17 + 5 ) - 25 / 5") << endl;
	cout << prefix2infix("* + * 125 2 5 + 12 5") << endl;
	cout << prefix2postfix("* + * 125 2 5 + 12 5") << endl;
	cout << evaluatePrefix("* + * 125 2 5 + 12 5") << endl;
	cout << postfix2infix("120 14 4 - 4 * + 2 /") << endl;
	cout << postfix2prefix("120 14 4 - 4 * + 2 /") << endl;
	cout << evaluatePostfix("120 14 4 - 4 * + 2 /") << endl;
	return 0;

}