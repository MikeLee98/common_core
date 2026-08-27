/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioro2 <marioro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 12:19:35 by mario             #+#    #+#             */
/*   Updated: 2026/08/27 17:43:36 by marioro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int main()
{
	PhoneBook phonebook;
	std::string input;

	while (1)
	{
		std::cout << "Enter command: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (0);
		if (input == "ADD")
		{
			Contact newcontact;

			input = "";
			while (input.find_first_not_of(" \t") == std::string::npos)
			{
				std::cout << "First name:";
				std::getline(std::cin, input);
				if (std::cin.eof())
					return (0);
			}
			newcontact.setFirstName(input);
			input = "";
			while (input.find_first_not_of(" \t") == std::string::npos)
			{
				std::cout << "Last name:";
				std::getline(std::cin, input);
				if (std::cin.eof())
					return (0);
			}
			newcontact.setLastName(input);
			input = "";
			while (input.find_first_not_of(" \t") == std::string::npos)
			{
				std::cout << "Nickname:";
				std::getline(std::cin, input);
				if (std::cin.eof())
					return (0);
			}
			newcontact.setNickname(input);
			input = "";
			while (input.find_first_not_of(" \t") == std::string::npos)
			{
				std::cout << "Phone number:";
				std::getline(std::cin, input);
				if (std::cin.eof())
					return (0);
			}
			newcontact.setPhoneNumber(input);
			input = "";
			while (input.find_first_not_of(" \t") == std::string::npos)
			{
				std::cout << "Darkest secret:";
				std::getline(std::cin, input);
				if (std::cin.eof())
					return (0);
			}
			newcontact.setDarkestSecret(input);
			phonebook.addContact(newcontact);
		}
		else if (input == "SEARCH")
		{
			phonebook.searchContacts();
		}
		else if (input == "EXIT")
			return(0);
		else
			std::cout << "Unknown command" << std::endl;
	}
}
