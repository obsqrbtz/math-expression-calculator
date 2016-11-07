#pragma once
#include <string>
#include <vector>
#include <sstream>
struct operations{
	public:
		std::string str;
		int priority;
};
class expression{
	private:
		std::string str_expression;
		std::vector<float> operands_stack;
		std::vector<std::string> ar_expression;
		std::vector<std::string> operators_stack;
		std::vector<std::string> element_type;
		operations operation[10];
	public:
		expression(std::string);
		std::vector<std::string> get_element_type();
		std::vector<std::string> get_expression();
		std::vector<std::string> get_operators_stack();
		std::vector<float> get_operands_stack();
		std::string get_str_expression();
		bool can_pop(std::string, std::string);
		void pop(std::string);
		int get_operator_priority(std::string);
		void fill_stacks(std::string);
		float evaluate();
};