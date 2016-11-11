#include "console_window.h"
char console_window(){
	std::string input;
	std::cout << "1. Evaluate expression" << std::endl;
	std::cout << "2. Exit" << std::endl;
	std::cin >> input;
	if (input == "1"){
		std::string expr_str;
		std::cout << "Enter expression(without spaces)" << std::endl;
		std::cin >> expr_str;
		expression expr(expr_str);
		for (int i = 0; i < expr.get_expression().size(); i++) std::cout << expr.get_expression()[i] << " ";
		std::cout << std::endl;
		for (int i = 0; i < expr.get_element_type().size(); i++) std::cout << i << ":" << expr.get_element_type()[i] << std::endl;
		std::cout << expr.get_str_expression() << " = " << expr.evaluate() << std::endl;
		return '1';
	}
	else if (input == "2"){
		return '0';
	}
	else{
		std::cout << "Invalid input" << std::endl;
		return '1';
	}
}
void console_window_loop(){
	char i = '1';
	while (i != '0'){
		i = console_window();
	}
}