/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mario <Mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 14:13:19 by marioro2          #+#    #+#             */
/*   Updated: 2026/09/21 20:55:54 by Mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

bool Fixed::operator>(const Fixed &other) const
{
	return (_value > other._value);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (_value < other._value);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (_value >= other._value);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (_value <= other._value);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (_value == other._value);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (_value != other._value);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;

	result.setRawBits(_value + other._value);
	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;

	result.setRawBits(_value - other._value);
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;

	result.setRawBits((_value * other._value) >> _fractionalBits);
	return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result;

	result.setRawBits((_value / other._value) << _fractionalBits);
	return (result);
}

Fixed &Fixed::operator++(void)
{
	_value++;
	return (*this);
}

Fixed &Fixed::operator--(void)
{
	_value--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed old(*this);

	_value++;
	return (old);
}

Fixed Fixed::operator--(int)
{
	Fixed old(*this);

	_value--;
	return (old);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

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
	_value = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(int const value)
{
	_value = value << _fractionalBits;
}

Fixed::Fixed()
{
	_value = 0;
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	_value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const
{
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}
