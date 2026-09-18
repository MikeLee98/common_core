/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mario <Mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 14:13:02 by marioro2          #+#    #+#             */
/*   Updated: 2026/09/18 15:26:38 by Mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	private:
		int _value;
    	static const int _fractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed &operator=(const Fixed &other); // This is an operator overload, we are teaching C++ how to behave when we use the operator = on a Fixed object
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
