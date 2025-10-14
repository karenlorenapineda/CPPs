/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:36:18 by kpineda-          #+#    #+#             */
/*   Updated: 2025/10/14 18:45:37 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	std::cout << "Welcome to your ";
    std::cout << "\033[31mA\033[0m";
    std::cout << "\033[32mW\033[0m";
    std::cout << "\033[33mE\033[0m";
    std::cout << "\033[34mS\033[0m";
    std::cout << "\033[35mO\033[0m";
    std::cout << "\033[36mM\033[0m";
    std::cout << "\033[91mE\033[0m";
    std::cout << " PhoneBook!" << std::endl;
    std::cout << "You can: " << std::endl;
    std::cout << "\033[32mADD\033[0m: add new contact"  << std::endl;
    std::cout << "\033[36mSEARCH\033[0m: search for an existing contact" << std::endl;
    std::cout << "\033[31mEXIT\033[0m: exit the program" << std::endl;

	contactCount = 0;
	contactAmount = 0;
};

std::string PhoneBook::newContactInfo(std::string info)
{
	std::string command;
	
	while (true)
	{
		std::cout << "Enter " << info << ": ";
		std::getline(std::cin, command);
		if (command.empty())
			continue;
		else
			return command;
	}
}

void PhoneBook::Add()
{
	if (contactCount >= 8)
		contactCount = 0;
	contacts[contactCount].contactInfo.firstName = newContactInfo("First Name");
	contacts[contactCount].contactInfo.lastName = newContactInfo("Last Name");
	contacts[contactCount].contactInfo.nickname = newContactInfo("Nickname");
	contacts[contactCount].contactInfo.phoneNumber = newContactInfo("Phone Number");
	contacts[contactCount].contactInfo.darkestSecret = newContactInfo("Darkest Secret");
	std::cout << "Contact saved!" << std::endl;
	contactCount++;
	if (contactAmount < 8)
		contactAmount++;
};

std::string	PhoneBook::ShellSize(std::string info)
{
	
	if (info.length() > 10)
		return info.substr(0, 9) + ".";
	else
		return std::string(10 - info.length(), ' ') + info;
}

void	PhoneBook::printTable()
{
	std::cout << "+----------+----------+----------+----------+"<< std::endl;
    std::cout << "|     Index| FirstName|  LastName|  Nickname|"<< std::endl;
    std::cout << "+----------+----------+----------+----------+"<< std::endl;
	
	for (int i= 0; i < contactAmount; i++)
	{
		std::cout << "|         " << i + 1 << "|";
		std::cout << ShellSize(contacts[i].contactInfo.firstName) << "|";
		std::cout << ShellSize(contacts[i].contactInfo.lastName) << "|";
		std::cout << ShellSize(contacts[i].contactInfo.nickname) << "|";
		std::cout << std::endl;
	}
	for (int i = contactAmount; i < 8; i++)
	{
		std::cout << "|         " << i + 1;
		std::cout << "|          |          |          |"<< std::endl;
    }
    std::cout << "+----------+----------+----------+----------+"<< std::endl;
}

void PhoneBook::Search()
{
	printTable();
	
	std::cout << "Enter a Index Number: ";
	
	std::string line;
	int index;
	getline(std::cin, line);
	
	std::stringstream sline(line);
	if (!(sline >> index))
		std::cout << "Invalid Index" << std::endl;
	else if (index > 0 && index <= contactAmount)
		contacts[index - 1].VisualiceInfo();
	else
		std::cout << "Out of range!" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "See u soon :D" << std::endl;
};