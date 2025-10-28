/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 20:06:15 by kpineda-          #+#    #+#             */
/*   Updated: 2025/10/28 21:18:47 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string newName)
{
	name = newName;
}
HumanB::HumanB(std::string newName, Weapon* newWeapon)
{
	name = newName;
	weapon = newWeapon;
}

void HumanB::setWeapon(Weapon *newWeapon)
{
	weapon = newWeapon;
}

void HumanB::attack()
{
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

HumanB::~HumanB()
{
	
}