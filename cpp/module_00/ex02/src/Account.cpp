/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:27:14 by rcheong           #+#    #+#             */
/*   Updated: 2024/11/21 17:28:12 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/**
 * @brief Constructor for a new Account object
 * @details This constructor will create a new Account object with the given initial deposit amount
 * @param initial_deposit The initial deposit amount
 */
Account::Account( int initial_deposit )
		:_accountIndex(Account::_nbAccounts),
		_amount(initial_deposit),
		_nbDeposits(0),
		_nbWithdrawals(0)
{
	this->_nbAccounts++;
	this->_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

/**
 * @brief Destructor for the Account object
 * @details This destructor will display the timestamp, the account index, the amount, and the message "closed"
 */
Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

/**
 * @brief Get the number of accounts
 */
int	Account::getNbAccounts( void )
{
	return Account::_nbAccounts;
}

/**
 * @brief Get the total amount for all accounts
 */
int	Account::getTotalAmount( void )
{
	return Account::_totalAmount;
}

/**
 * @brief Get the number of deposits
 */
int	Account::getNbDeposits( void )
{
	return Account::_totalNbDeposits;
}

/**
 * @brief Get the number of withdrawals
 */
int	Account::getNbWithdrawals( void )
{
	return Account::_totalNbWithdrawals;
}

/**
 * @brief Display the timestamp in the format [YYYYMMDD_HHMMSS]
 */
void	Account::_displayTimestamp( void )
{
	time_t		now = time(0);
	struct tm	*tm = localtime(&now);

	std::cout << "[";
    std::cout << (tm->tm_year + 1900);
    std::cout << (tm->tm_mon + 1);
    std::cout << tm->tm_mday;
    std::cout << "_";
    std::cout << tm->tm_hour;
    std::cout << tm->tm_min;
    std::cout << tm->tm_sec;
    std::cout << "] ";
}

/**
 * @brief Display the account information
 */
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

/**
 * @brief Make a deposit into the account
 * @details This function will increase the amount in the account by the deposit amount
 * @param deposit The deposit amount
 */
void	Account::makeDeposit( int deposit )
{
	int	p_amount = this->_amount;

	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

/**
 * @brief Make a withdrawal from the account
 * @details This function will decrease the amount in the account
 * by the withdrawal amount unless the account does not have enough funds
 * @param withdrawal The withdrawal amount
 */
bool	Account::makeWithdrawal( int withdrawal )
{
	int	p_amount = this->_amount;

	_displayTimestamp();
	if (checkAmount() < withdrawal)
	{
		std::cout << "index:" << this->_accountIndex << ";";
		std::cout << "p_amount:" << p_amount << ";";
		std::cout << "withdrawal:" << "refused" << std::endl;
		return (false);
	}
	else
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		std::cout << "index:" << this->_accountIndex << ";";
		std::cout << "p_amount:" << p_amount << ";";
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << this->_amount << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
}

/**
 * @brief Check the amount in the account
 */
int	Account::checkAmount( void ) const
{
	return this->_amount;
}

/**
 * @brief Print the account status summary
 * @details This function will display the timestamp, the account index, the amount, the number of deposits, and the number of withdrawals
 */
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}
