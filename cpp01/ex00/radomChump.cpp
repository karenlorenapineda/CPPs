/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radomChump.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:33:52 by kpineda-          #+#    #+#             */
/*   Updated: 2025/10/15 02:09:03 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie randomChump(name);

	randomChump.announce();
}