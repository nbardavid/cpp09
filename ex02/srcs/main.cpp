/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:57:35 by nbardavi          #+#    #+#             */
/*   Updated: 2024/06/11 13:57:32 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/colors.h"
#include "../include/Pmergeme.Class.hpp"
#include <string>
#include <ctime>
#include <iostream>
#include <vector>
#include <cstdlib>

int main(int argc, char **argv){
	
	(void)argc;
	(void)argv;
    std::srand(static_cast<unsigned int>(std::time(0)));
    std::vector<int> vector;
    std::vector<std::pair<int, int> > pvector;
	for (int i = 0; i < 11; ++i){
		vector.push_back(std::rand() % 100);
	}
	Pmergeme(vector, pvector);
	return 0;
}
// if (argc != 2){
// 	std::cerr << RED << "Usage: ./btc <input>" << RESET << std::endl;
// 	return(false);
// }
