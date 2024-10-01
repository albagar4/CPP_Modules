/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:18:26 by albagar4          #+#    #+#             */
/*   Updated: 2024/10/01 15:49:06 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main(void){
	{
		// AAnimal errortest;
		// const AAnimal errortest1;
		// const AAnimal *errortest2 = new AAnimal();
		// const AAnimal *errortest3 = new WrongCat();
		// const WrongCat errortest4;
		const AAnimal *goodtest = new Cat();

		goodtest->makeSound();
		delete goodtest;
	}
	return (0);
}