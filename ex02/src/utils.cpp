/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 08:30:47 by bbrassar          #+#    #+#             */
/*   Updated: 2022/04/20 08:46:53 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

typedef Base *(*Generator)(void);

static Base *makeA(void);
static Base *makeB(void);
static Base *makeC(void);

static Generator const	generators[3] = {
	makeA, makeB, makeC
};

Base	*generate(void)
{
	return (generators[rand() % 3]());
}

void	identify(Base *p)
{
	identify(*p);
}

/**
 * If the cast fails and new-type is a reference type, it throws an exception that matches a handler of type std::bad_cast.
 *
 * @see https://en.cppreference.com/w/cpp/language/dynamic_cast
 *
 */
void	identify(Base &p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "identified A" << std::endl;
		return;
	} catch (std::exception &e)
	{
	}
	try
	{
		dynamic_cast<B&>(p);
		std::cout << "identified B" << std::endl;
		return;
	} catch (std::exception &e)
	{
	}
	try
	{
		dynamic_cast<C&>(p);
		std::cout << "identified C" << std::endl;
		return;
	} catch (std::exception &e)
	{
	}
	std::cout << "could not identify" << std::endl;
}

static Base *makeA(void)
{
	std::cout << "generated A" << std::endl;
	return (new A);
}

static Base *makeB(void)
{
	std::cout << "generated B" << std::endl;
	return (new B);
}

static Base *makeC(void)
{
	std::cout << "generated C" << std::endl;
	return (new C);
}
