/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnannie <jnannie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 09:46:02 by jnannie           #+#    #+#             */
/*   Updated: 2020/12/03 14:33:47 by jnannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int		main(int argc, char **argv)
{
	char	*arg;
	int		i = 0;

	if (argc <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		argv++;
		while (*argv)
		{
			arg = *argv;
			while(arg[i])
			{
				arg[i] = toupper(arg[i]);
				i++;
			}
			std::cout << arg;
			i = 0;
			argv++;
		}
	}
	std::cout << std::endl;
	return (0);
}
