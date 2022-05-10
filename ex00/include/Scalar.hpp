/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:11:01 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/10 14:44:38 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP
# define SCALAR_HPP

# include <limits>
# include <ostream>
# include <string>

class Scalar
{
	public:
	static std::numeric_limits<char>	LIMIT_CHAR;
	static std::numeric_limits<int>		LIMIT_INT;
	static std::numeric_limits<float>	LIMIT_FLOAT;
	static std::numeric_limits<double>	LIMIT_DOUBLE;

	private:
	double	val;
	bool	valid;
	bool	infinite;
	bool	nan;

	public:
	Scalar(void);
	Scalar(std::string const &s);
	Scalar(Scalar const &x);
	~Scalar();

	Scalar				&operator=(Scalar const &x);

	public:
	std::ostream		&printChar(std::ostream &os) const;
	std::ostream		&printInt(std::ostream &os) const;
	std::ostream		&printFloat(std::ostream &os) const;
	std::ostream		&printDouble(std::ostream &os) const;
}; // class Scalar

std::ostream	&operator<<(std::ostream &os, Scalar const &scalar);

#endif // SCALAR_HPP
