/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 08:10:26 by bbrassar          #+#    #+#             */
/*   Updated: 2022/04/20 08:23:36 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.h"
#include <iostream>

static void	init_data(Data *data)
{
	data->i = 42;
	data->l = 88888;
}

int	main(void)
{
	Data		data;
	uintptr_t	raw;
	Data		*ptr;

	init_data(&data);
	raw = serialize(&data);
	ptr = deserialize(raw);
	std::cout
		<< "Data: {" << std::endl
		<< "    i = " << data.i << "," << std::endl
		<< "    l = " << data.l << "," << std::endl
		<< "}" << std::endl;
	std::cout
		<< std::endl
		<< "&Data = " << &data << std::endl
		<< "raw = serialize(&Data) = " << raw << std::endl
		<< "ptr = deserialize(raw) = " << ptr << std::endl;
	return (0);
}
