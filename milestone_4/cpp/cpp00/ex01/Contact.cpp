/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 18:58:08 by mario             #+#    #+#             */
/*   Updated: 2026/08/17 19:30:21 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void	Contact::setFirstName(std::string const &firstName)
{
	this->firstName = firstName;
}

void	Contact::setLastName(std::string const &lastName)
{
	this->lastName = lastName;
}

void	Contact::setNickname(std::string const &nickname)
{
	this->nickname = nickname;
}

void	Contact::setPhoneNumber(std::string const &phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(std::string const &darkestSecret)
{
	this->darkestSecret = darkestSecret;
}

std::string	Contact::getFirstName() const
{
	return (firstName);
}

std::string	Contact::getLastName() const
{
	return (lastName);
}

std::string	Contact::getNickname() const
{
	return (nickname);
}

std::string	Contact::getPhoneNumber() const
{
	return (phoneNumber);
}

std::string	Contact::getDarkestSecret() const
{
	return (darkestSecret);
}
