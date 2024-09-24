/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:18:26 by albagar4          #+#    #+#             */
/*   Updated: 2024/09/24 18:33:56 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void){
	{
		Animal errortest;
		const Animal errortest1;
		const Animal *errortest2 = new Animal();
		const Animal *errortest3 = new WrongCat();
		const WrongCat errortest4;
		const Animal *goodtest = new Cat();

		goodtest->makeSound();
		delete goodtest;
	}
	return (0);
}