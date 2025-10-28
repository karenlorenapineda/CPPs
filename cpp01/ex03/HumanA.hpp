/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 21:21:25 by kpineda-          #+#    #+#             */
/*   Updated: 2025/10/28 20:51:22 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP

#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>
#include <sstream>

class HumanA
{
	Weapon& weapon;
	std::string name;
	HumanA();

public:

	HumanA(std::string newName, Weapon& newWeapon);
	~HumanA();
	
	void attack();
};

#endif