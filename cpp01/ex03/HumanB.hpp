/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 21:21:51 by kpineda-          #+#    #+#             */
/*   Updated: 2025/12/28 13:43:25 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP

#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>
#include <sstream>

class HumanB
{
	Weapon* weapon;
	std::string name;
	HumanB();

public:
	HumanB(std::string newName);
	HumanB(std::string newName, Weapon* newWeapon);
	~HumanB();
	
	void setWeapon(Weapon* newWeapon);
	void attack();
};

#endif