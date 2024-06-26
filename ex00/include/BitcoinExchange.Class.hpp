/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.Class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:09:01 by nbardavi          #+#    #+#             */
/*   Updated: 2024/06/07 14:38:40 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTC_CLASS_HPP
# define BTC_CLASS_HPP

#include <string>
#include <iostream>
#include <vector>

void checkInput(const std::string& filename, std::vector<std::pair<std::string, double> > file_data);
std::vector<std::pair<std::string, double> > readFile(const std::string& filename);

#endif
