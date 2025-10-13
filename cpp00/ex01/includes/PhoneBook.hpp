/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:36:25 by kpineda-          #+#    #+#             */
/*   Updated: 2025/10/13 21:57:02 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONEBOOK_HPP

# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	Contact contacts[8];
	int		contactAmount;
	int		contactCount;
	
	std::string newContactInfo(std::string info);
	std::string	ShellSize(std::string info);
	void	printTable();
	
public:
	PhoneBook();
	~PhoneBook();
	void Add();
	void Search();
};

#endif