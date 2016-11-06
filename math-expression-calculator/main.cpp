#include "calculator.h"
#include <iostream>
using namespace std;
int main(){
	calculator pff("24-(5+654)*5-4^2*sin(45+6)/45*(cos(456))^2-43");
	cout << pff.get_str_expression() << endl;
	for (int i = 0; i < pff.get_operands_stack().size(); i++){
		cout << pff.get_operands_stack()[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < pff.get_operators_stack().size(); i++){
		cout << pff.get_operators_stack()[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}