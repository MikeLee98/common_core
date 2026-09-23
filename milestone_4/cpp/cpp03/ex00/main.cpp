/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioro2 <marioro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 17:26:57 by marioro2          #+#    #+#             */
/*   Updated: 2026/09/23 17:30:26 by marioro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap a;
	ClapTrap b("Brad");

	a.attack("Brad");
	a.takeDamage(3);
	b.attack("ClapTrap");
	a.beRepaired(2);
	b.takeDamage(5);
	b.beRepaired(4);
	return 0;
}
