/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:08:59 by marvin            #+#    #+#             */
/*   Updated: 2024/09/16 13:08:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	//std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(int const value)
{
	//std::cout << "Int constructor called" << std::endl;
	this->value = value * pow(2, this->fractBits);
}

Fixed::Fixed(float const value)
{
	//std::cout << "Float constructor called" << std::endl;
	this->value = roundf(value * pow(2, this->fractBits));
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& source)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = source;
}

Fixed& Fixed::operator=(const Fixed& source)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	this->value = source.getRawBits();
	return *this;
}

int	Fixed::getRawBits( void ) const
{
	return this->value;
}

void	Fixed::setRawBits( int const raw )
{
	this->value = raw;
}

float	Fixed::toFloat( void ) const
{
	return (this->value / pow(2, this->fractBits));
}

int		Fixed::toInt( void ) const
{
	return (this->value / pow(2, this->fractBits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}

bool Fixed::operator<(const Fixed& autreObjet)
{
	return this->value < autreObjet.value;
}
bool Fixed::operator>(const Fixed& autreObjet)
{
	return this->value > autreObjet.value;
}
bool Fixed::operator<=(const Fixed& autreObjet)
{
	return this->value <= autreObjet.value;
}
bool Fixed::operator>=(const Fixed& autreObjet)
{
	return this->value >= autreObjet.value;
}
bool Fixed::operator==(const Fixed& autreObjet)
{
	return this->value == autreObjet.value;
}
bool Fixed::operator!=(const Fixed& autreObjet)
{
	return this->value != autreObjet.value;
}
Fixed& Fixed::operator+(const Fixed& autreObjet)
{
	this->value += autreObjet.value;
	return *this;
}
Fixed& Fixed::operator*(const Fixed& autreObjet)
{
	value = roundf((this->toFloat() * autreObjet.toFloat()) * pow(2, fractBits));
	return *this;
}
Fixed& Fixed::operator/(const Fixed& autreObjet)
{
	value = roundf((this->toFloat() / autreObjet.toFloat()) * pow(2, fractBits));
	return *this;
}
Fixed& Fixed::operator-(const Fixed& autreObjet)
{
	this->value -= autreObjet.value;
	return *this;
}
Fixed& Fixed::operator++()
{
	this->value++;
	return *this;
}
Fixed Fixed::operator++(int)
{
	Fixed temp;

	temp.value = this->value;
	this->value++;
	return temp;
}
Fixed& Fixed::operator--()
{
	this->value--;
	return *this;
}
Fixed Fixed::operator--(int)
{
	Fixed temp;

	temp.value = this->value;
	this->value--;
	return temp;
}

Fixed &Fixed::min( Fixed &a, Fixed &b )
{
	if (a.value > b.value)
		return b;
	return a;
}
Fixed &Fixed::max( Fixed &a, Fixed &b )
{
	if (a.value > b.value)
		return a;
	return b;
}
const Fixed &Fixed::min( const Fixed &a, const Fixed &b )
{
	if (a.value > b.value)
		return b;
	return a;
}
const Fixed &Fixed::max( const Fixed &a, const Fixed &b )
{
	if (a.value > b.value)
		return a;
	return b;
}