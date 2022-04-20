/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 04:25:27 by bbrassar          #+#    #+#             */
/*   Updated: 2022/04/20 04:41:18 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static bool	_checkArgs(int argc)
{
	if (argc == 2)
		return (true);
	std::cout
		<< "Expected 1 argument, "
		<< argc - 1
		<< " given."
		<< std::endl;
	return (false);
}

static void	_execute(std::string const &value)
{
	std::cout << value << std::endl;
}

int	main(int argc, char const *argv[])
{
	if (!_checkArgs(argc))
		return (1);
	_execute(argv[1]);
	return (0);
}
