/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:36:23 by kpineda-          #+#    #+#             */
/*   Updated: 2025/10/14 18:19:27 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CONTACT_HPP

# define CONTACT_HPP

# include <iostream>
# include <string>
# include <sstream>

struct	Info
{
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
};

class Contact
{
public:
	Info contactInfo;
	
	Contact();
	~Contact();
	void VisualiceInfo();
	
};

#endif