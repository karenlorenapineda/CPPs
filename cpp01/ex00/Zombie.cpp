/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:33:55 by kpineda-          #+#    #+#             */
/*   Updated: 2025/10/15 18:35:54 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Zombie aparece" << std::endl;
}

Zombie::Zombie(std::string name)
{
	_name = name;
	std::cout << name << " aparece" << std::endl;
}

Zombie::~Zombie() 
{
	std::cout << _name << " desaparece" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}