/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioro2 <marioro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 14:38:50 by marioro2          #+#    #+#             */
/*   Updated: 2026/08/25 15:01:01 by marioro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
	public:
		Zombie();
		~Zombie();
	private:
		std::string name;
		void announce(void);
};

#endif
