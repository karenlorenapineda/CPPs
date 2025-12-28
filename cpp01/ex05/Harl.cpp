/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 13:34:23 by kpineda-          #+#    #+#             */
/*   Updated: 2025/12/28 13:36:54 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl has come! Do you know Harl? We all do, don’t we? In case you don’t, he complains a lot. But thats your problem now, good luck!" << std::endl;
};
Harl::~Harl()
{
	std::cout << "Finally he leave! Good job, you survived to Harl!" << std::endl;
};

// private

void Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
};

void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
};

void Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
};

void Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
};

// public

void Harl::complain(std::string level)
{
	typedef void (Harl::*Func)();
	Func complains[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*complains[i])();
			return;
		}
	}
} 