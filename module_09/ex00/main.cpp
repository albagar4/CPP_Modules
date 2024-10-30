/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:10:21 by albagar4          #+#    #+#             */
/*   Updated: 2024/10/30 11:10:25 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Incorrect nbr of parameters" << std::endl;
		std::cout << "Usage: ./btc <database.csv> <filename>" << std::endl;
		std::cout << "** Erase the titles from the database **" << std::endl;
	}
	else {
		std::ifstream csv("data.csv");
		std::ifstream input(argv[1]);
		if (!csv.is_open() || !input.is_open()) {
			std::cout << "File not found" << std::endl;
			return (0);
		}
		std::string file;
		std::string sheet;
		std::getline(csv,file, '\0');
		std::getline(input,sheet, '\0');
		
		BitcoinExchange test(file, sheet);
		test.lineDivision();
		test.determineValue();
		csv.close();
		input.close();
	}
	return (0);
}
