/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:52:26 by ygolshan          #+#    #+#             */
/*   Updated: 2023/11/27 13:13:51 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : val(0)
{
    
}

Fixed::Fixed(const int value)
{
	this->val = value * (1 << this->bit);
}

Fixed::Fixed(const float value)
{
	this->val = roundf(value * (1 << this->bit));
}

Fixed::Fixed(const Fixed& ins)
{
	*this = ins;
}

Fixed::~Fixed()
{
    
}

Fixed &	Fixed::operator=(const Fixed& variable)
{
	if (this != &variable)
		this->val = variable.getRawBits();
	return *this;
}

int		Fixed::getRawBits() const
{
	return (this->val);
}

void	Fixed::setRawBits(const int raw)
{
	this->val = raw;
}

float	Fixed::toFloat() const
{
	return ((float)this->val / (1 << this->bit));
}

int		Fixed::toInt() const
{
	return (this->val / (1 << this->bit));
}

Fixed&			Fixed::max(Fixed& a, Fixed& b)
{
	if (a < b)
		return (b);
	return (a);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (b);
	return (a);
}

Fixed&			Fixed::min(Fixed& a, Fixed& b)
{
	if (a > b)
		return (b);
	return (a);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (b);
	return (a);
}

bool	Fixed::operator<(const Fixed& variable) const
{
	if (this->toFloat() < variable.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator>(const Fixed& variable) const
{
	return (variable.val < this->val);
}

bool	Fixed::operator<=(const Fixed& variable) const
{
	return !(this->val > variable.val);
}

bool	Fixed::operator>=(const Fixed& variable) const
{
	return !(this->val < variable.val);
}

bool	Fixed::operator==(const Fixed& variable) const
{
	return (this->val == variable.val);
}

bool	Fixed::operator!=(const Fixed& variable) const
{
	return !(this->val == variable.val);
}

Fixed	Fixed::operator+(const Fixed& variable) const
{
	return (this->toFloat() + variable.toFloat());
}

Fixed	Fixed::operator-(const Fixed& variable) const
{
	return (this->toFloat() - variable.toFloat());
}

Fixed	Fixed::operator*(const Fixed& variable) const
{
	return (this->toFloat() * variable.toFloat());
}

Fixed	Fixed::operator/(const Fixed& variable) const
{
	if (variable.getRawBits() == 0)
	{
		exit(1);
	}
	return (this->toFloat() / variable.toFloat());
}

Fixed&	Fixed::operator++()
{
	this->val++;
	return (*this);
}

Fixed&	Fixed::operator--()
{
	this->val--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	operator++();
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	operator--();
	return (tmp);
}

const int	Fixed::bit = 8;

std::ostream & operator<<(std::ostream & o, const Fixed& variable)
{
	o << variable.toFloat();
	return (o);
}
