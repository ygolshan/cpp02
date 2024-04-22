/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:52:23 by ygolshan          #+#    #+#             */
/*   Updated: 2023/11/27 13:08:27 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef Fixed_hpp
# define Fixed_hpp

#include <iostream>
#include <cmath>

class Fixed
{

		int					val;
		static const int	bit;

	public:

		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;

		static			Fixed&	max(Fixed& a, Fixed& b);
		static const	Fixed&	max(const Fixed& a, const Fixed& b);
		static			Fixed&	min(Fixed& a, Fixed& b);
		static const	Fixed&	min(const Fixed& a, const Fixed& b);

		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(Fixed const & ins);
		~Fixed();

		
		Fixed	operator+(const Fixed& variable) const;
		Fixed	operator-(const Fixed& variable) const;
		Fixed	operator*(const Fixed& variable) const;
		Fixed	operator/(const Fixed& variable) const;
		Fixed&	operator++();
		Fixed&	operator--();
		Fixed	operator++(int);
		Fixed	operator--(int); 
        Fixed&	operator=(Fixed const & variable);
		bool	operator>(const Fixed& variable) const;
		bool	operator<(const Fixed& variable) const;
		bool	operator>=(const Fixed& variable) const;
		bool	operator<=(const Fixed& variable) const;
		bool	operator==(const Fixed& variable) const;
		bool	operator!=(const Fixed& variable) const;

};

std::ostream&	operator<<(std::ostream& o, const Fixed& variable);
#endif
