#include <iostream>
#include <cctype>
#include <cstdlib>
#include <climits>
#include <stack>

using number_t = long long;

const int MAX_BUF_SIZE = 200;

char buf[MAX_BUF_SIZE];
int buf_p; //指示当前处理到的位置

void error_exit() {
	std::cout << "Error" << std::endl;
	exit(0);
}

number_t get_number() {
	number_t num = 0;
	for (; isdigit(buf[buf_p]); ++buf_p)
		num = num * 10 + buf[buf_p] - '0';
	--buf_p;
	return num;
}

int get_priority(char opt) {
	switch (opt) {
	case '^':
		return 2;
	case '*':
	case '/':
		return 1;
	case '+':
	case '-':
		return 0;
	}
	return -1;
}

void exec_opt(std::stack<number_t> &number, std::stack<char> &symbol) {
	if (number.size() < 2) error_exit();
	number_t p2 = number.top(); number.pop();
	number_t p1 = number.top(); number.pop();
	char c = symbol.top(); symbol.pop();
	number_t r;
	switch (c)
	{
	case '^':
		if (!p1) error_exit();
		if (p1 == 1) {
			r = 1;
			break;
		}
		if (p1 == -1) {
			r = (p2 & 1) ? -1 : 1;
			break;
		}
		for (r = 1; p2--; r *= p1); break;
	case '*':
		r = p1 * p2; break;
	case '/':
		if (!p2) error_exit();
		r = p1 / p2; break;
	case '+':
		r = p1 + p2; break;
	case '-':
		r = p1 - p2; break;
	}
	number.push(r);
}

number_t calc(bool start_with_bracket) {
	std::stack<number_t> number;
	std::stack<char> symbol;
	bool expect_number = true;
	for (char c; (c = buf[buf_p]) && c != ')'; ++buf_p) {
		if (expect_number) {
			bool negtive = false;
			while (c == '-' || c == '+') {
				if (c == '-')
					negtive = negtive ? false : true;
				c = buf[++buf_p];
			}
			number_t r;
			if (isdigit(c))
				r = get_number();
			else if (c == '(') {
				++buf_p;
				r = calc(true);
			}
			else
				error_exit();
			if (negtive) r = -r;
			number.push(r);
			expect_number = false;
		}
		else {
			if (get_priority(c) == -1)
				error_exit();
			while (!symbol.empty() && get_priority(symbol.top()) > get_priority(c))
				exec_opt(number, symbol);
			while (!symbol.empty() && get_priority(symbol.top()) == get_priority(c) && get_priority(c) != 2)
				exec_opt(number, symbol);
			symbol.push(c);
			expect_number = true;
		}
	}
	while (!symbol.empty())
		exec_opt(number, symbol);
	if (start_with_bracket && buf[buf_p] != ')')
		error_exit();
	if (!start_with_bracket && buf[buf_p] == ')')
		error_exit();
	if (number.empty()) error_exit();
	return number.top();
}

int main() {
	while (!std::cin.eof()) {
		char c = std::cin.get();
		if (isspace(c)) continue;
		buf[buf_p++] = c;
	}
	buf[buf_p - 1] = 0;	buf_p = 0;
	number_t r = calc(false);
	if (buf[buf_p + 1])
		error_exit();
	std::cout << r << std::endl;
	return 0;
}