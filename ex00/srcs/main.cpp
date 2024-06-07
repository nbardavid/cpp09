/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:57:35 by nbardavi          #+#    #+#             */
/*   Updated: 2024/06/07 14:38:43 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/colors.h"
#include "../include/BitcoinExchange.Class.hpp"

int main(int argc, char **argv){
	
	if (argc != 2){
		std::cerr << RED << "Usage: ./btc <input>" << RESET << std::endl;
		return(false);
	}
	std::vector<std::pair<std::string, double> > file = readFile("./data.csv");
	checkInput(argv[1], file);
	return 0;
}
