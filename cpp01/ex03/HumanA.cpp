/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 21:27:14 by kpineda-          #+#    #+#             */
/*   Updated: 2025/12/28 13:53:18 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string newName, Weapon& newWeapon): name(newName), weapon(newWeapon)
{
	std::cout << name << " has now the weapon of type: ";
	std::cout << weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
	
}

void HumanA::setType(std::string type)
{
	weapon.setType(type);
}

void HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}