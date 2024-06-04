/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:57:35 by nbardavi          #+#    #+#             */
/*   Updated: 2024/06/04 16:11:39 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/colors.h"
#include "../include/BitcoinExchange.Class.hpp"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <utility> // Pour std::pair
#include <stdexcept>

void printData(const std::vector<std::pair<std::string, double> >& data) {
    for (std::vector<std::pair<std::string, double> >::const_iterator it = data.begin(); it != data.end(); ++it) {
        std::cout << "Date: " << it->first << " Value: " << it->second << std::endl;
    }
}

std::string trim(const std::string& str){
	size_t first = str.find_first_not_of(" \t\n\v\f\r");
	if (first == std::string::npos){
		return "";
	}
	size_t last = str.find_last_not_of(" \t\n\v\f\r");
	return str.substr(first, (last - first + 1));
}

bool check_date(std::string date){
	date = trim(date);

    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        std::cerr << "Erreur de format de date" << std::endl;
        return false;
    }

	std::cout << date << std::endl;
	
	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = (date.substr(8, 2));
	if (year.is_numeric()){

	}

	int y = 0; 
	int m = 0;
	int d = 0;
	Sy >> y;
	Sm >> m;
	Sd >> d;

	if (Sy.fail() || Sm.fail() || Sd.fail())
		std::cerr << RED << "Erreur year" << RESET << std::endl;

	// std::cout << y << " " << date << std::endl;
	return true;
}

std::vector<std::pair<std::string, double> > readFile(const std::string& filename){
	std::vector<std::pair<std::string, double> > data;
	std::ifstream file(filename.c_str());
    int i = 1;
	if (!file.is_open()) {
        std::cerr << "Could not open the file!" << std::endl;
        return data;
    }

	std::string header;
	std::getline(file, header);

	std::string line;
	while(std::getline(file, line)){
		std::string date;
		std::string value_str;
		double value;

		std::istringstream line_stream(line);
		std::getline(line_stream, date, ',');
		std::getline(line_stream, value_str, ',');

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

std::vector<std::pair<std::string, double> > checkInput(const std::string& filename){
	std::vector<std::pair<std::string, double> > data;
	std::ifstream file(filename.c_str());

    int i = 1;
	
	//open file
	if (!file.is_open()) {
        std::cerr << "Could not open the file!" << std::endl;
        return data;
    }

	//skip header
	std::string header;
	std::getline(file, header);

	std::string line;
	while(std::getline(file, line)){
		std::string date;
		std::string value_str;
		// double value;

		std::istringstream line_stream(line);
		std::getline(line_stream, date, '|');
		std::getline(line_stream, value_str, '\n');
		check_date(date);
		// std::cout << "{" << date << "} ";
		// std::cout << "{" << value_str << "}" << std::endl;

		// std::istringstream value_stream(value_str);
		// if (value_stream >> value) {
		// 	data.push_back(std::make_pair(date, value));
		// } else {
		// 	std::cerr << "Invalid number format: " << value_str << std::endl;
		// }

		i++;
	}
	file.close();
	return data;
}

int main(void){

	std::vector<std::pair<std::string, double> > file = readFile("./data.csv");
	// printData(file);
	
	checkInput("./input.txt");
	return 0;
}
