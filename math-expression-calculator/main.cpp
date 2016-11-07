#include "calculator.h"
#include <iostream>
using namespace std;
int main(){
	expression pff("(4+5)-(14-8/2+2*(4-2))+10");
	cout << pff.get_str_expression() << endl;
	cout << pff.evaluate() << endl;
	system("pause");
	return 0;
}