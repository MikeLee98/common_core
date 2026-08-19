/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 12:19:35 by mario             #+#    #+#             */
/*   Updated: 2026/08/19 12:01:07 by mario            ###   ########.fr       */
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
		if (input == "ADD")
		{
			Contact newcontact;

			input = "";
			while (input == "")
			{
				std::cout << "First name:";
				std::getline(std::cin, input);	
			}
			newcontact.setFirstName(input);
			input = "";
			while (input == "")
			{
				std::cout << "Last name:";
				std::getline(std::cin, input);
			}
			newcontact.setLastName(input);
			input = "";
			while (input == "")
			{
				std::cout << "Nickname:";
				std::getline(std::cin, input);
			}
			newcontact.setNickname(input);
			input = "";
			while (input == "")
			{
				std::cout << "Phone number:";
				std::getline(std::cin, input);
			}
			newcontact.setPhoneNumber(input);
			input = "";
			while (input == "")
			{
				std::cout << "Darkest secret:";
				std::getline(std::cin, input);
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
