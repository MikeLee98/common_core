/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioro2 <marioro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 17:26:57 by marioro2          #+#    #+#             */
/*   Updated: 2026/09/24 16:53:46 by marioro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>


int main()
{
    ClapTrap tinman("Tinman");
    ScavTrap bouncer("Bouncer");
    FragTrap crusher("Crusher");

    tinman.takeDamage(5);
    tinman.beRepaired(1);
    tinman.attack("Rock");

    std::cout << std::endl;
    bouncer.guardGate();
    bouncer.takeDamage(15);
    bouncer.attack("Fence");
    bouncer.beRepaired(3);

    std::cout << std::endl;
    crusher.highFivesGuys();
    crusher.attack("Boulder");
    crusher.takeDamage(60);
    crusher.highFivesGuys();

    return (0);
}
