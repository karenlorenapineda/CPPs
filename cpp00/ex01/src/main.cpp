/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:36:13 by kpineda-          #+#    #+#             */
/*   Updated: 2025/10/13 20:22:25 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook phoneBook;
	std::string command;

	while (true)
	{
		std::cout << "Please enter a commnad: ";
		std::getline(std::cin, command);
		if (command.compare("ADD") == 0)
			phoneBook.Add();
		else if (command.compare("SEARCH") == 0)
			phoneBook.Search();
		else if (command.compare("EXIT") == 0)
			return 0;
	}
	return 0;
}