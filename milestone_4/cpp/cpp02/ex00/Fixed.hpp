/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioro2 <marioro2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 14:13:02 by marioro2          #+#    #+#             */
/*   Updated: 2026/09/22 14:30:32 by marioro2         ###   ########.fr       */
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
		Fixed &operator=(const Fixed &other); // This is an operator overload, we are teaching our program how to behave when we use the operator = on a Fixed object
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
