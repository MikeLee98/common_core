/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioro2 <marioro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 17:40:23 by marioro2          #+#    #+#             */
/*   Updated: 2026/09/15 14:59:45 by marioro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(void)
{
	Harl harl;
	std::string level;

	std::cout << "Enter a complaint level:" << std::endl;
	while (std::getline(std::cin, level))
	{
		harl.complain(level);
		break ;
	}
	return (0);
}
