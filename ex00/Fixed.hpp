/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:58:24 by ygolshan          #+#    #+#             */
/*   Updated: 2023/11/27 13:01:09 by ygolshan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Fixed_hpp
# define Fixed_hpp

#include <iostream>

class Fixed
{
		int					val;
		static const int	bit;

	public:
	
		int		getRawBits() const;
		void	setRawBits(int const raw);

		Fixed();
		Fixed(const Fixed& ins);
		~Fixed();
		Fixed&	operator=(const Fixed& variable);
};

#endif