/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:57:35 by nbardavi          #+#    #+#             */
/*   Updated: 2024/05/30 15:50:59 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/colors.h"
#include "../include/BitcoinExchange.Class.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <utility> // Pour std::pair
#include <stdexcept>

bool check_date(std::string date){
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        std::cerr << "Erreur de format de date" << std::endl;
        return false;
    }
	std::cout << date << std::endl;
	std::istringstream Sy(date.substr(0, 4));
	std::istringstream Sm(date.substr(5, 2));
	std::istringstream Sd(date.substr(8, 2));
	int y = 0; 
	int m = 0;
	int d = 0;
	Sy >> y;
	Sm >> m;
	Sd >> d;
	if (Sy.fail() || Sm.fail() || Sd.fail())
		std::cerr << RED << "Erreur year" << RESET << std::endl;//Gestion d'erreur
	// std::cout << y << " " << date << std::endl;
	return true;
}

std::vector<std::pair<std::string, double> > readFile(const std::string& filename){
	std::vector<std::pair<std::string, double> > data;
	std::ifstream file(filename.c_str());
    int i = 0;
	if (!file.is_open()) {
        std::cerr << "Could not open the file!" << std::endl;
        return data;
    }

	std::string line;
	while(std::getline(file, line)){
		std::string date;
		std::string value_str;
		double value;

		std::istringstream line_stream(line);
		std::getline(line_stream, date, ',');
		std::getline(line_stream, value_str, ',');
		if (!check_date(date)){
			std::cerr << RED << "Erreur date ligne: " << i << std::endl;
		}

		std::istringstream value_stream(value_str);
		if (value_stream >> value) {
			data.push_back(std::make_pair(date, value));
		} else {
			std::cerr << "Invalid number format: " << value_str << std::endl;
		}

		i++;
	}
	file.close();
	return data;
}

int main(void){
	readFile("./data.csv");
	return 0;
}
