#include <iostream>
#include "calculator.h"
using namespace std;
int main(){
	expression expr("ln(e^5)");
	cout << expr.evaluate() << endl;
	system("pause");
	return 0;
}