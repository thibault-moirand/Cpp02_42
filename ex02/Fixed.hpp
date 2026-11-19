/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:08:57 by marvin            #+#    #+#             */
/*   Updated: 2024/09/16 13:08:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <sstream>
#include <cmath>

class Fixed
{
	private:
		int	value;
		static int const	fractBits = 8;
	public:
		Fixed();
		Fixed(int const value);
		Fixed(const Fixed& autreObjet);
		Fixed(float const float_n);
		~Fixed();
		Fixed& operator=(const Fixed& autreObjet);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

		bool operator<(const Fixed& autreObjet);
		bool operator>(const Fixed& autreObjet);
		bool operator<=(const Fixed& autreObjet);
		bool operator>=(const Fixed& autreObjet);
		bool operator==(const Fixed& autreObjet);
		bool operator!=(const Fixed& autreObjet);

		Fixed& operator+(const Fixed& autreObjet);
		Fixed& operator*(const Fixed& autreObjet);
		Fixed& operator/(const Fixed& autreObjet);
		Fixed& operator-(const Fixed& autreObjet);

		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

		static Fixed &min( Fixed &a, Fixed &b );
		static Fixed &max( Fixed &a, Fixed &b );
		static const Fixed &min( const Fixed &a, const Fixed &b );
		static const Fixed &max( const Fixed &a, const Fixed &b );
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif