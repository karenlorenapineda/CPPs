/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:33:40 by kpineda-          #+#    #+#             */
/*   Updated: 2025/10/15 19:09:04 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main(void)
{
	int N;
	N = 7;
	Zombie* horde = zombieHorde(N, "Angels");
	for(int i = 0; i < N; i++)
		horde->announce();
	delete [] horde;

	return 0;
}