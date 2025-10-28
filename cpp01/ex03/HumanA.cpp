/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 21:27:14 by kpineda-          #+#    #+#             */
/*   Updated: 2025/10/28 21:00:21 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string newName, Weapon& newWeapon): weapon(newWeapon)
{
	name = newName;
}

HumanA::~HumanA()
{
	
}

void HumanA::attack()
{
	std::cout << name << "attacks with their" << weapon.getType() << std::endl;
}