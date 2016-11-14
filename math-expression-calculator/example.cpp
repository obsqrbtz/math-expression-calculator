#include <iostream>
#include "calculator.h"
using namespace std;
int main(){
	expression expr("((((4+3^4)*9+56)-56)-56)^2");
	cout << expr.evaluate() << endl;
	system("pause");
	return 0;
}