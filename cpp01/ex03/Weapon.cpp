/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 21:11:26 by kpineda-          #+#    #+#             */
/*   Updated: 2025/10/15 21:21:01 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	
}

Weapon::~Weapon()
{
	
}

const std::string Weapon::getType()
{
	return (type);
}

void Weapon::setType(std::string newType)
{
	type = newType;
}