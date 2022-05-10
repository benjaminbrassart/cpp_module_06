/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 08:29:26 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/10 12:05:19 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GENERATE_HPP_
# define _GENERATE_HPP_

# include "Base.hpp"

# define ARRAYLEN(array) (sizeof (array) / sizeof (*array))

Base	*generate(void);

/**
 * If the cast fails and new-type is a pointer type,
 * dynamic_cast returns NULL
 *
 * @see https://en.cppreference.com/w/cpp/language/dynamic_cast
 */
void	identify(Base *p);

/**
 * If the cast fails and new-type is a reference type,
 * dynamic_cast throws a std::bad_cast.
 *
 * @see https://en.cppreference.com/w/cpp/language/dynamic_cast
 */
void	identify(Base &p);

#endif
