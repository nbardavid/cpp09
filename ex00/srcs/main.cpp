/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:57:35 by nbardavi          #+#    #+#             */
/*   Updated: 2024/06/05 15:56:07 by nbardavi         ###   ########.fr       */
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
#include <ctime>

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

bool is_number(const std::string& s) {
    std::string::const_iterator it = s.begin();
    bool decimal_point_found = false;
	if (*it == '-')
		++it;
    while (it != s.end()) {
        if (*it == '.') {
            if (decimal_point_found) {
                return false;
            }
            decimal_point_found = true;
        } else if (!std::isdigit(*it)) {
            return false;
        }
        ++it;
    }
    return !s.empty() && !(s.size() == 1 && decimal_point_found);
}

bool isValidDate(int year, int month, int day) {
    std::tm time_in = {};
    time_in.tm_sec = 0;
    time_in.tm_min = 0;
    time_in.tm_hour = 0;
    time_in.tm_year = year - 1900;
    time_in.tm_mon = month - 1;
    time_in.tm_mday = day;

    std::time_t time_temp = std::mktime(&time_in);
    if (time_temp == -1) {
        return false;
    }

    std::tm* time_out = std::localtime(&time_temp);
    if (!time_out) {
        return false;
    }

    return (time_out->tm_year == year - 1900 && 
            time_out->tm_mon == month - 1 &&
            time_out->tm_mday == day);
}

bool check_date(std::string date){
	date = trim(date);
	
	//checking structure
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        std::cerr << "Error: wrong date format [(YYYY-MM-DD)] line: ";
        return false;
    }

	// std::cout << date << std::endl;
	
	//cutting string
	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = (date.substr(8, 2));
	if (!is_number(year) || !is_number(month) || !is_number(day)){
		std::cout << RED << "Error: date contain letter line: ";
		return false;
	}
	
	//convert to int
	int y,m,d;
	std::istringstream Sy(year);
	std::istringstream Sm(month);
	std::istringstream Sd(day);
	Sy >> y;
	Sm >> m;
	Sd >> d;

	if (Sy.fail() || Sm.fail() || Sd.fail()){
		std::cerr << RED << "Convertion error" << RESET << std::endl;
		return false;
	}
	if (!isValidDate(y, m, d)){
		std::cerr << RED << "Error: not a valid date line: ";
		return false;
	}
	return true;
}

bool check_value(std::string str_value){
	str_value = trim(str_value);
	if (!is_number(str_value)){
		std::cerr << RED << "Error: non numeric value found line: ";
		return false;
	}
	std::istringstream s_value(str_value);
	float value;
	s_value >> value;
	if (value >= 1000 || value <= 0){
		std::cerr << RED << "Error: value does not respect [0 < value < 1000] line: ";
		return false;
	}
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

		if (line.find('|', 0) == line.npos){
			std::cerr << RED << "Error: no \'|\' at line: " << i << RESET << std::endl;
		}
		else{
			std::istringstream line_stream(line);
			std::getline(line_stream, date, '|');
			std::getline(line_stream, value_str, '\n');

			if (check_date(date) == false){
				std::cerr << i << RESET << std::endl;
			}
			if (check_value(value_str) == false){
				std::cerr << i << RESET << std::endl;
			}

			std::cout << "{" << date << "} ";
			std::cout << "{" << value_str << "}" << std::endl;

			// std::istringstream value_stream(value_str);
			// if (value_stream >> value) {
			// 	data.push_back(std::make_pair(date, value));
			// } else {
			// 	std::cerr << "Invalid number format: " << value_str << std::endl;
			// }
		}
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
