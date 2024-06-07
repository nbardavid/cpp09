/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:57:35 by nbardavi          #+#    #+#             */
/*   Updated: 2024/06/07 14:37:00 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/colors.h"
#include <string>
#include <iostream>


int main(int argc, char **argv){
	
	if (argc != 2){
		std::cerr << RED << "Usage: ./btc <input>" << RESET << std::endl;
		return(false);
	}
	RPM(argv[1]);
	return 0;
}
