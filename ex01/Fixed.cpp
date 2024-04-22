/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:50:58 by ygolshan          #+#    #+#             */
/*   Updated: 2023/11/27 13:01:09 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : val(0)
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int value)
{
	this->val = value * (1 << this->bit);
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
	this->val = roundf(value * (1 << this->bit));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & ins)
{
	*this = ins;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Deconstructor called" << std::endl;
}


Fixed &	Fixed::operator=(Fixed const & variable)
{
	if (this != &variable)
		this->val = variable.getRawBits();
	std::cout << "Copy assigment operator called" << std::endl;
	return *this;
}

int		Fixed::getRawBits() const
{
	return (this->val);
}

void	Fixed::setRawBits(int const raw)
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

const int	Fixed::bit = 8;

std::ostream & operator<<(std::ostream & o, Fixed const & variable)
{
	o << variable.toFloat();
	return (o);
}