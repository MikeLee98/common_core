/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioro2 <marioro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 17:26:57 by marioro2          #+#    #+#             */
/*   Updated: 2026/09/24 16:48:35 by marioro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap a;
    ClapTrap b("Bradinton");

    a.beRepaired(2);
    b.attack("Brad");
    a.takeDamage(5);
    b.takeDamage(3);
    a.attack("Bradinton");
    b.beRepaired(4);
    std::cout << std::endl;

    ScavTrap s1;
    ScavTrap s2("Martim");

    s1.beRepaired(5);
    s2.takeDamage(42);
    s1.guardGate();
    s2.attack("Bradinton");
    s1.attack("Martim");
    s2.guardGate();
    s1.takeDamage(20);
    s2.beRepaired(10);

    return (0);
}
