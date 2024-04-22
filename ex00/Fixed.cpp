/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:57:33 by ygolshan          #+#    #+#             */
/*   Updated: 2023/11/27 13:01:09 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : val(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Deconstructor called" << std::endl;
}

Fixed::Fixed(const Fixed& ins)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = ins;

	return;
}

Fixed&	Fixed::operator=(const Fixed& variable)
{
	std::cout << "Copy assigment operator called" << std::endl;
	if (this != &variable)
		this->val = variable.getRawBits();

	return *this;
}

int		Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;

	return (this->val);
}

void	Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->val = raw;

	return;
}

const int	Fixed::bit = 8;