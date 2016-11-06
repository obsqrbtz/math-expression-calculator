#pragma once
#include <string>
#include <vector>
#include <sstream>
struct operations{
	public:
		std::string str;
		int priority;
};
class calculator{
	private:
		std::string str_expression;
		std::vector<float> operands_stack;
		std::vector<std::string> operators_stack;
		operations operation[10];
	public:
		std::vector<std::string> get_operators_stack();
		std::vector<float> get_operands_stack();
		calculator(std::string);
		float evaluate();
		std::string get_str_expression();
		void fill_stacks(std::string);
};