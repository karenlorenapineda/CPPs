/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:33:58 by kpineda-          #+#    #+#             */
/*   Updated: 2025/10/15 02:09:03 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP

#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <sstream>

class Zombie
{
	std::string _name;

public:
	Zombie();
	Zombie(std::string name);
	~Zombie();

	void announce(void);
};

#endif