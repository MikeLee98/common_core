/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mario <Mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 16:37:52 by marioro2          #+#    #+#             */
/*   Updated: 2026/09/23 13:54:05 by Mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
	private:
		std::string name;
		unsigned int hitPoints = 10;
		unsigned int energyPoints = 10;
		unsigned int attackDamage = 0;

	public:
		ClapTrap(std::string);
		ClapTrap(const ClapTrap &other);
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
