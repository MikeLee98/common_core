/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mario <Mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 14:49:08 by Mario             #+#    #+#             */
/*   Updated: 2026/09/07 18:58:56 by Mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main(void)
{
	Zombie *horde;
	int i;

	horde = zombieHorde(5, "Bob");
	i = 0;
	while (i < 5)
	{
		horde[i].announce();
		i++;
	}
	delete[] horde;
	return (0);
}
