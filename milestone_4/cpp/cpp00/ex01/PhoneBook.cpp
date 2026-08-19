/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 18:57:59 by mario             #+#    #+#             */
/*   Updated: 2026/08/19 12:11:06 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>

PhoneBook::PhoneBook() : nextIndex(0), totalContacts(0) {}

PhoneBook::~PhoneBook() {}

std::string	truncateField(std::string const &field)
{
	if (field.length() > 10)
		return (field.substr(0, 9) + ".");
	return (field);
}

void	printRow(std::string const &c1, std::string const &c2, std::string const &c3, std::string const &c4)
{
	std::cout << std::right;
	std::cout << std::setw(10) << truncateField(c1) << "|";
	std::cout << std::setw(10) << truncateField(c2) << "|";
	std::cout << std::setw(10) << truncateField(c3) << "|";
	std::cout << std::setw(10) << truncateField(c4) << std::endl;
}

void	PhoneBook::searchContacts()
{
	int i;
	int inputnbr;
	std::string line;
	
	i = 0;
	if (totalContacts == 0)
	{
		std::cout << "No contacts available" << std::endl;
		return ;
	}
	printRow("index", "first name", "last name", "nickname");
	while (i < totalContacts)
	{
		std::ostringstream oss;
		oss << i;
		printRow(oss.str(), contacts[i].getFirstName(), contacts[i].getLastName(), contacts[i].getNickname());
		i++;
	}
	std::cout << "Enter the index of the contact to display: ";
	std::getline(std::cin, line);
	std::istringstream iss(line);
	if (!(iss >> inputnbr))
		std::cout << "Not a valid number" << std::endl;
	else
	{
    	if (inputnbr < 0 || inputnbr >= totalContacts)
			std::cout << "Not a valid contact" << std::endl;
		else
		{
			std::cout << contacts[inputnbr].getFirstName() << std::endl;
			std::cout << contacts[inputnbr].getLastName() << std::endl;
			std::cout << contacts[inputnbr].getNickname() << std::endl;
			std::cout << contacts[inputnbr].getPhoneNumber() << std::endl;
			std::cout << contacts[inputnbr].getDarkestSecret() << std::endl;
		}
	}
}

void	PhoneBook::addContact(Contact const &c)
{
	contacts[nextIndex] = c;
	nextIndex = (nextIndex + 1) % 8;
	if (totalContacts < 8)
		totalContacts++;
}


