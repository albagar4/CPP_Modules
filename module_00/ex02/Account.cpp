#include "Account.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit){
	static	int index = 0;

	this->_accountIndex = index;
	this->_amount = initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << index << ";amount:" << initial_deposit << ";created" << std::endl;
	index++;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	return ;
}

Account::~Account(void){
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount;
	std::cout << ";closed" << std::endl;
	return ;
}

int	Account::getNbAccounts(void){
	return (_nbAccounts);
}

int	Account::getTotalAmount(void){
	return (_totalAmount);
}

int	Account::getNbDeposits( void ){
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void){
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void){
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts();
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
	return ;
}

void	Account::makeDeposit(int deposit){
	_totalNbDeposits++;
	_totalAmount += deposit;
	this->_nbDeposits++;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
	this->_amount += deposit;
	std::cout << ";deposit:" << deposit << ";amount:" << this->_amount;
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
	return ;
}

bool	Account::makeWithdrawal(int withdrawal){
	_displayTimestamp();
	if (this->_amount - withdrawal < 0)
	{
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
		this->_amount -= withdrawal;
		std::cout << ";withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
}

int		Account::checkAmount( void ) const{
	return (this->_amount);
}

void	Account::displayStatus( void ) const{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount();
	std::cout << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
	std::time_t time = std::time(0);

	std::cout << "[" << std::setw(2) << std::localtime(&time)->tm_year + 1900;
	std::cout << std::setw(2) << std::setfill('0') << std::localtime(&time)->tm_mon;
	std::cout << std::setw(2) << std::localtime(&time)->tm_mday << "_";
	std::cout << std::setw(2) << std::localtime(&time)->tm_hour;
	std::cout << std::setw(2) << std::localtime(&time)->tm_min;
	std::cout << std::setw(2) << std::localtime(&time)->tm_sec << "] ";
}

