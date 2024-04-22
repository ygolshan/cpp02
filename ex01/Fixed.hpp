/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:50:40 by ygolshan          #+#    #+#             */
/*   Updated: 2023/11/27 13:08:34 by ygolshan         ###   ########.fr       */
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

		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(Fixed const & ins);
		~Fixed();

		Fixed &	operator=(Fixed const & variable);


};

std::ostream & operator<<(std::ostream & o, Fixed const & variable);

#endif