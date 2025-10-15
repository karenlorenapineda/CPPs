/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:33:40 by kpineda-          #+#    #+#             */
/*   Updated: 2025/10/15 18:32:52 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump(std::string name);
Zombie *newZombie(std::string name);

// int main(void)
// {
// 	Zombie x;
// 	Zombie Foo("Foo");

// 	x.announce();
// 	Foo.announce();
// 	randomChump("Random");
// 	Zombie* other = newZombie("MarcoPolo");
// 	other->announce();

// 	delete other;
//     return 0;
// }

int main(void)
{
	std::cout << "se crea el zombie, se anuncia, se destrulle y luego se llama a randomChump\n";
	Zombie *z = newZombie("newZ");
	z->announce();
	delete z;
	randomChump("rndZ");

	std::cout << "se crea el zombie, se anuncia, se llama a randomChump y luego se destrulle\n";
	z = newZombie("newZ");
	z->announce();
	randomChump("rndZ");
	delete z;

	std::cout << "se crea el zombie, se llama a randomChump y luego se anuncia y se destrulle\n";
	z = newZombie("newZ");
	randomChump("rndZ");
	z->announce();
	delete z;

	return 0;
}