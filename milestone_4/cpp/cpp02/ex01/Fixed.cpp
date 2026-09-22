/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioro2 <marioro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 14:13:19 by marioro2          #+#    #+#             */
/*   Updated: 2026/09/22 16:27:41 by marioro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <climits>

std::ostream &operator<<(std::ostream &o, const Fixed &fixed)
{
	return (o << fixed.toFloat());
}

float Fixed::toFloat(void) const
{
	return (_value / (float)(1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
	return (_value >> _fractionalBits);
}

Fixed::Fixed(float const value)
{
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(int const value)
{
	std::cout << "Int constructor called" << std::endl;
	_value = value << _fractionalBits;
}

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}
