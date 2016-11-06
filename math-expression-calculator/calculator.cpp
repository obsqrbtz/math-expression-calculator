#include "calculator.h"
float string_to_float(std::string str){
	float result;
	std::istringstream(str) >> result;
	return result;
}
void calculator::fill_stacks(std::string expr){
	std::string current_operand;
	std::string current_operator;
	std::string current_long_operator;
	for (int i = 0; i < expr.size(); i++){
		if (isdigit(expr[i])){
			while (isdigit(expr[i]) && i < expr.size()){
				current_operand.push_back(expr[i]);
				i++;
			}
			operands_stack.push_back(string_to_float(current_operand));
			current_operand.clear();
		}
		else{
			while (!isdigit(expr[i]) && i < expr.size()){
				if (expr[i] != '(' || expr[i] != ')'){
					if (isalpha(expr[i])){
						current_long_operator.push_back(expr[i]);
					}else{
						if (current_long_operator.size() != 0){
							operators_stack.push_back(current_long_operator);
							current_long_operator.clear();
						}
						current_operator.clear();
						current_operator.push_back(expr[i]);
						operators_stack.push_back(current_operator);
					}
				}else{
					if (current_long_operator.size() != 0){
						operators_stack.push_back(current_long_operator);
						current_long_operator.clear();
					}
					current_operator.clear();
					current_operator.push_back(expr[i]);
					operators_stack.push_back(current_operator);
				}
				i++;
			}
			current_operator.clear();
			current_long_operator.clear();
		}
		i--;
	}
}
calculator::calculator(std::string expr){
	str_expression = expr;
	fill_stacks(expr);
// Define operations and priorities
	operation[0].priority = 0;
	operation[0].str = "(";

	operation[1].priority = 1;
	operation[1].str = ")";

	operation[2].priority = 2;
	operation[2].str = "+";

	operation[3].priority = 2;
	operation[3].str = "-";

	operation[4].priority = 3;
	operation[4].str = "*";

	operation[5].priority = 3;
	operation[5].str = "/";

	operation[6].priority = 4;
	operation[6].str = "^";
}
std::string calculator::get_str_expression(){
	return str_expression;
}
std::vector<std::string> calculator::get_operators_stack(){
	return operators_stack;
}
std::vector<float> calculator::get_operands_stack(){
	return operands_stack;
}
float calculator::evaluate(){
	float result = 0;
	return result;
}