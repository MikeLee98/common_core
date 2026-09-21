/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mario <Mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 14:13:02 by marioro2          #+#    #+#             */
/*   Updated: 2026/09/18 21:37:42 by Mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed
{
	private:
		int 				_value;
    	static const int	_fractionalBits = 8;

	public:
		Fixed(int const value);
		Fixed(float const value);
		Fixed();
		Fixed(const Fixed& other);
		~Fixed();
		Fixed	&operator=(const Fixed &other);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		bool Fixed::operator>(const Fixed &other) const;
		bool Fixed::operator<(const Fixed &other) const;
		bool Fixed::operator>=(const Fixed &other) const;
		bool Fixed::operator<=(const Fixed &other) const;
		bool Fixed::operator==(const Fixed &other) const;
		bool Fixed::operator!=(const Fixed &other) const;
		Fixed Fixed::operator+(const Fixed &other) const;
		Fixed Fixed::operator-(const Fixed &other) const;
		Fixed Fixed::operator*(const Fixed &other) const;
		Fixed Fixed::operator/(const Fixed &other) const;
		Fixed &Fixed::operator++(void);
		Fixed &Fixed::operator--(void);
		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &min(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &o, const Fixed &fixed);

#endif
