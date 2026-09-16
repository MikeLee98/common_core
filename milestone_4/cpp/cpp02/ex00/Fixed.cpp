/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioro2 <marioro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 14:13:19 by marioro2          #+#    #+#             */
/*   Updated: 2026/09/16 17:27:27 by marioro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	_value = 0;
}

Fixed::Fixed(const Fixed& other)
{
	_value = other._value;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	_value = other._value;
	return (*this);
}
