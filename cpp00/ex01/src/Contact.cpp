/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:36:20 by kpineda-          #+#    #+#             */
/*   Updated: 2025/10/14 18:38:36 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact()
{
	
};

Contact::~Contact()
{
	
};

void Contact::VisualiceInfo()
{
	std::cout << "First Name: " << contactInfo.firstName << std::endl
		<< "Last Name: " << contactInfo.lastName << std::endl
		<< "Nickname: " << contactInfo.nickname << std::endl
		<< "Phone Number: " << contactInfo.phoneNumber << std::endl
		<< "Darkest Secret: " << contactInfo.darkestSecret << std::endl;
		
};