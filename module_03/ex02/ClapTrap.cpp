/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:14:44 by albagar4          #+#    #+#             */
/*   Updated: 2024/08/29 14:14:51 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
	std::cout << CYAN << "ClapTrap: Default constructor called" << RNL;
	this->name = "Default";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name){
	std::cout << CYAN << "ClapTrap: " << name << " constructor called" << RNL;
	this->name = name;
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
}

ClapTrap::~ClapTrap(){
	std::cout << CYAN << "ClapTrap: " << name << " Destructor called" << RNL;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap){
	std::cout << CYAN << "ClapTrap: Copy constructor called" << RNL;
	this->name = claptrap.name;
	this->hitPoints = claptrap.hitPoints;
	this->energyPoints = claptrap.energyPoints;
	this->attackDamage = claptrap.attackDamage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap){
	std::cout << CYAN << "ClapTrap: Copy assignment operator called" << RNL;
	this->name = claptrap.name;
	this->hitPoints = claptrap.hitPoints;
	this->energyPoints = claptrap.energyPoints;
	this->attackDamage = claptrap.attackDamage;
	return (*this);
}

void ClapTrap::attack(const std::string& target){
	if (this->energyPoints > 0)
	{
		std::cout << this->name << " has attacked " << target << "!!" << std::endl;
		std::cout << target << " has received " << this->attackDamage << " points of damage" << std::endl; 
		this->energyPoints--;
	}
	else
		std::cout << this->name << " has no Energy points left" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	this->hitPoints -= amount;
	if (this->hitPoints > 0)
		std::cout << this->name << " has received " << amount << " points of damage, but he's still standing" << std::endl;
	else
		std::cout << this->name << " has received " << amount << " points of damage, and sadly he died" << std::endl; 
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->hitPoints > 0 && this->energyPoints > 0)
	{
		this->hitPoints += amount;
		this->energyPoints--;
		std::cout << this->name << " used his magic to recover " << amount << " points of life" << std::endl;
	}
	else if (this->hitPoints <= 0)
		std::cout << this->name << " is dead, he cannot use his magic :(" << std::endl;
	else
		std::cout << this->name << " has not enough energy points to use his magic" << std::endl;
}

void ClapTrap::printStats(void){
	std::cout << BOLD << "Name: " << RESET << this->name << std::endl;
	std::cout << BOLD << "HitPoints: " << RESET << this->hitPoints << std::endl;
	std::cout << BOLD << "EnergyPoints: " << RESET << this->energyPoints << std::endl;
	std::cout << BOLD << "AttackDamage: " << RESET << this->attackDamage << std::endl;
}
