#include "calculator.h"
#include <iostream>
using namespace std;
int main(){
	expression pff("2.4-(5+65.4)*5");
	cout << pff.get_str_expression() << endl;
	for (int i = 0; i < pff.get_expression().size(); i++){
		cout << pff.get_expression()[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < pff.get_expression().size(); i++){
		cout << pff.get_element_type()[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}