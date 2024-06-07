/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPM.Class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:09:05 by nbardavi          #+#    #+#             */
/*   Updated: 2024/06/07 14:37:26 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/colors.h"
#include <stack>
#include <string>
#include <iostream>
#include <sstream>

bool is_digit(size_t c){
	return (c >= '0' && c <= '9');
}

bool is_op(size_t c){
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPM(std::string string){
    std::stack<int> stack;
	int pos1;
	int pos2;
	for (size_t i = 0; i < string.length(); ++i){
		if (is_digit(string[i])){
			stack.push(string[i] - '0');
		}
		else if (is_op(string[i])){
			if (stack.size() <= 1){
				std::cerr << RED << "Error: Wrong format" << RESET << std::endl;
				return;
			}
			else{
				pos1 = stack.top();
				stack.pop();
				pos2 = stack.top();
				stack.pop();
				
				if (string[i]  == '+'){
					stack.push(pos2 + pos1);
				}

				if (string[i]  == '-'){
					stack.push(pos2 - pos1);
				}

				if (string[i]  == '*'){
					stack.push(pos2 * pos1);
				}

				if (string[i]  == '/'){
					stack.push(pos2 / pos1);
				}
			}
		}
	}
	std::cout << "Result: " << stack.top() << std::endl;
}
