/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 13:34:40 by kpineda-          #+#    #+#             */
/*   Updated: 2025/12/28 13:34:42 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP

# define HARL_HPP

# include <iostream>
# include <string>
# include <unistd.h>

class Harl
{

	void debug( void );
	void info( void );
	void warning( void );
	void error( void );

public:

	Harl(void);
	~Harl(void);
	
	void complain( std::string level );
};

#endif