/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 18:20:25 by albagar4          #+#    #+#             */
/*   Updated: 2024/09/27 18:22:54 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
	// {
	// 	IMateriaSource *src = new MateriaSource();
	// 	for (int i = 0; i < 3; i++)
	// 	{
	// 		src->learnMateria(new Ice());
	// 		src->learnMateria(new Cure());
	// 	}

	// 	AMateria *wpn1 = src->createMateria("ice");
	// 	AMateria *wpn2 = src->createMateria("cure");
	// 	AMateria *wpn3 = src->createMateria("nutella");

	// 	ICharacter *me = new Character("me");
	// 	me->equip(wpn1);
	// 	me->equip(wpn2);
	// 	me->equip(wpn3);
	// 	me->unequip(1);
	// 	me->unequip(3);

	// 	delete src;
	// 	delete me;
	// 	return (0);
	// }
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
		return 0;
	}
}
