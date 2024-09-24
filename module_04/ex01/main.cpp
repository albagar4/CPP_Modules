/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:18:26 by albagar4          #+#    #+#             */
/*   Updated: 2024/09/24 17:41:09 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void){
	// {
	// 	const Animal* j = new Dog();
	// 	const Animal* i = new Cat();
	// 	delete j;
	// 	delete i;
	// }
	{
		int i = 6;
		const Animal* animalArray[i];

		for (int j = 0; j < i; j++)
		{
			if (j < i / 2)
				animalArray[j] = new Dog();
			else
				animalArray[j] = new Cat();
		}
		for (int j = 0; j < i; j++)
			delete animalArray[j];
	}
	return (0);
}