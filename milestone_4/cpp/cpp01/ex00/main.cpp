/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mario <Mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 17:28:14 by Mario             #+#    #+#             */
/*   Updated: 2026/09/03 17:36:35 by Mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main(void)
{
	std::cout << "Creating a Zombie on the heap..." << std::endl;
	Zombie *heapZombie = newZombie("Heap Zombie");

	std::cout << "The heap Zombie announces:" << std::endl;
	heapZombie->announce();

	std::cout << "\nCreating a Zombie on the stack..." << std::endl;
	randomChump("Stack Zombie");

	std::cout << "\nBack in main: the heap Zombie still exists!" << std::endl;
	heapZombie->announce();

	std::cout << "\nDeleting the heap Zombie..." << std::endl;
	delete heapZombie;

	return (0);
}
