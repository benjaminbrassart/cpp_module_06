/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 08:28:51 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/10 11:53:57 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "utils.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

#define BASE_COUNT 10

int	main(void)
{
	Base	*bases[BASE_COUNT];

	srand(time(NULL));
	std::cout
		<< std::endl
		<< "      GENERATING      "
		<< std::endl << std::endl;
	for (int i = 0; i < BASE_COUNT; ++i)
	{
		std::cout << "[" << i << "] ";
		bases[i] = generate();
	}
	std::cout
		<< std::endl
		<< "      IDENTIFYING (REFERENCE)      "
		<< std::endl << std::endl;
	for (int i = 0; i < BASE_COUNT; ++i)
	{
		std::cout << "[" << i << "] ";
		identify(*bases[i]);
	}
	std::cout
		<< std::endl
		<< "      IDENTIFYING (POINTER)      "
		<< std::endl << std::endl;
	for (int i = 0; i < BASE_COUNT; ++i)
	{
		std::cout << "[" << i << "] ";
		identify(bases[i]);
	}
	for (int i = 0; i < BASE_COUNT; ++i)
		delete bases[i];
}
