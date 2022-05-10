/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 08:30:47 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/10 12:05:25 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "I.hpp"
#include <cstdlib>
#include <iostream>

typedef Base *(*Generator)(void);

static Base *makeA(void);
static Base *makeB(void);
static Base *makeC(void);

#ifdef GENERATE_INVALID

static Base *makeInvalid(void);

#endif

static Generator const	generators[] = {
	makeA,
	makeB,
	makeC,
#ifdef GENERATE_INVALID

	makeInvalid,

#endif
};

Base	*generate(void)
{
	return (generators[rand() % ARRAYLEN(generators)]());
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "identified A";
	else if (dynamic_cast<B *>(p))
		std::cout << "identified B";
	else if (dynamic_cast<C *>(p))
		std::cout << "identified C";
	else
		std::cout << "could not identify";
	std::cout << std::endl;
	// identify(*p);
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "identified A" << std::endl;
		return;
	} catch (std::exception &e)
	{
	}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "identified B" << std::endl;
		return;
	} catch (std::exception &e)
	{
	}
	try
	{
		(void)dynamic_cast<C &>(p);
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

#ifdef GENERATE_INVALID

static Base	*makeInvalid(void)
{
	std::cout << "generated I" << std::endl;
	return (new I);
}

#endif
