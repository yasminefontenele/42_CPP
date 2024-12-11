/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfontene <yfontene@student.42porto>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:31:39 by yfontene          #+#    #+#             */
/*   Updated: 2024/11/08 14:57:32 by yfontene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*std::endl adiciona uma nova linha e limpa o buffer.*/
#include "Account.hpp"
#include <iostream>// std::cout
#include <ctime>// std::time
#include <iomanip>// std::setw setw é para setar o tamanho do campo de saida

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/*Contruct*/
Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    _nbAccounts++;
    _totalAmount += _amount;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

/*Destruct*/
Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void Account::_displayTimestamp()
{
    std::time_t now = std::time(0);//pega o tempo atual em segundos
    std::tm *ltm = std::localtime(&now);//converte o tempo em uma estrutura de data/hora

    std::cout << "[" << 1900 + ltm->tm_year
                << std::setw(2) << std::setfill('0') << 1 + ltm->tm_mon
                << std::setw(2) << std::setfill('0') << ltm->tm_mday << "_"
                << std::setw(2) << std::setfill('0') << ltm->tm_hour
                << std::setw(2) << std::setfill('0') << ltm->tm_min
                << std::setw(2) << std::setfill('0') << ltm->tm_sec << "] ";
}

int Account::getNbAccounts(void) { return _nbAccounts; }
int Account::getTotalAmount(void) { return _totalAmount; }
int Account::getNbDeposits(void) { return _totalNbDeposits; }
int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts
                << ";total:" << _totalAmount
                << ";deposits:" << _totalNbDeposits
                << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
    int previousAmount = _amount;
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
                << ";p_amount:" << previousAmount
                << ";deposit:" << deposit
                << ";amount:" << _amount
                << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    int previousAmount = _amount;
    
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
                << ";p_amount:" << previousAmount;

    if (withdrawal > _amount)
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }

    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;

    std::cout << ";withdrawal:" << withdrawal
                << ";amount:" << _amount
                << ";nb_withdrawals:" << _nbWithdrawals << std::endl;

    return true;
}

int Account::checkAmount(void) const { return _amount; }

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
                << ";amount:" << _amount
                << ";deposits:" << _nbDeposits
                << ";withdrawals:" << _nbWithdrawals << std::endl;
}