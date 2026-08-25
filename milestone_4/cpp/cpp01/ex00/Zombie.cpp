/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioro2 <marioro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 14:38:23 by marioro2          #+#    #+#             */
/*   Updated: 2026/08/25 15:12:39 by marioro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
