/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioro2 <marioro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 17:40:19 by marioro2          #+#    #+#             */
/*   Updated: 2026/09/15 16:05:08 by marioro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void	Harl::debug(void)
{
	std::cout << "I have a plan." << std::endl;
}

void	Harl::info(void)
{
	std::cout << "The plan has changed." << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "We may need a backup plan." << std::endl;
}

void	Harl::error(void)
{
		std::cout << "There is no plan." << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i;

	for (i = 0; i < 4; i++)
	{
		if (level == levels[i])
			break ;
	}
	if (i == 4)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return ;
	}
	switch (i)
	{
		case (0):
		std::cout << "[ DEBUG ]" << std::endl;
		debug();
		std::cout << std::endl;
		case (1):
		std::cout << "[ INFO ]" << std::endl;
		info();
		std::cout << std::endl;
		case (2):
		std::cout << "[ WARNING ]" << std::endl;
		warning();
		std::cout << std::endl;
		case (3):
		std::cout << "[ ERROR ]" << std::endl;
		error();
		std::cout << std::endl;
		break ;
	}
	return ;
}
