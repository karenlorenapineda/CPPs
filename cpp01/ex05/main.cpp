/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpineda- <kpineda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 13:34:51 by kpineda-          #+#    #+#             */
/*   Updated: 2025/12/28 13:35:03 by kpineda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl harl = Harl();
	sleep(1);
	std::cout << "#DEBUG#" << std::endl;
	harl.complain("DEBUG");
	sleep(1);
	std::cout << "#INFO#" << std::endl;
	harl.complain("INFO");
	sleep(1);
	std::cout << "#WARNING#" << std::endl;
	harl.complain("WARNING");
	sleep(1);
	std::cout << "#ERROR#" << std::endl;
	harl.complain("ERROR");
	sleep(1);
	return 0;
}
