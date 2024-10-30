/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:10:43 by albagar4          #+#    #+#             */
/*   Updated: 2024/10/30 11:10:45 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Wrong nbr of parameters" << std::endl;
		std::cout << "Usage: ./RPN \"<mathematical expression>\"" << std::endl;
	}
	else
		evaluateRPN(argv[1]);
	return (0);
}
