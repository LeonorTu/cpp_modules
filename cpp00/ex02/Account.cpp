/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:05:04 by jtu               #+#    #+#             */
/*   Updated: 2024/09/10 19:30:02 by jtu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int init_amount)
{
	_totalAmount += init_amount;
	_accountIndex = _nbAccounts++;
	_amount = init_amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";created" << std::endl;
}
Account::~Account()
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";closed" << std::endl;
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts
				<< ";total:" << _totalAmount
				<< ";deposits:" << _totalNbDeposits
				<< ";withdrawals:" << _totalNbWithdrawals
				<< std::endl;
}

void	Account::makeDeposit( int deposit )
{
	int	p_amount;

	p_amount = _amount;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_amount += deposit;
	_nbDeposits++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
				<< ";p_amount:" << p_amount
				<< ";deposit:" << deposit
				<< ";amount:" << _amount
				<< ";nb_deposits:" << _nbDeposits
				<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int	p_amount;

	_displayTimestamp();
	if (withdrawal > _amount)
	{
		std::cout << " index:" << _accountIndex
				<< ";p_amount:" << _amount
				<< ";withdrawal:refused" << std::endl;
		return (false);
	}
	p_amount = _amount;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	_amount -= withdrawal;
	_nbWithdrawals++;
	std::cout << " index:" << _accountIndex
				<< ";p_amount:" << p_amount
				<< ";withdrawal:" << withdrawal
				<< ";amount:" << _amount
				<< ";nb_withdrawals:" << _nbWithdrawals
				<< std::endl;
	return (true);
}

int	Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals
				<< std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t		now = time(0);
	std::tm		*now_tm = localtime(&now);

	std::cout << "[" << std::put_time(now_tm, "%Y%m%d_%H%M%S") << "]";
}
