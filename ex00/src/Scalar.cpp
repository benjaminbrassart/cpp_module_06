/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:19:54 by bbrassar          #+#    #+#             */
/*   Updated: 2022/05/10 14:44:27 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>

Scalar::Scalar(void) :
	val(0),
	valid(true),
	infinite(false),
	nan(false)
{
}

Scalar::Scalar(Scalar const &x) :
	val(x.val),
	valid(x.valid),
	infinite(x.infinite),
	nan(x.nan)
{
}

Scalar::Scalar(std::string const &s) :
	val(0),
	valid(true),
	infinite(true),
	nan(true)
{
	char	*end;

	if (s == "inf" || s == "inff" || s == "+inf" || s == "+inff")
		this->val = LIMIT_FLOAT.infinity();
	else if (s == "-inf" || s == "-inff")
		this->val = -LIMIT_FLOAT.infinity();
	else if (s == "nan" || s == "nanf" || s == "+nan" || s == "+nanf")
		this->val = LIMIT_FLOAT.quiet_NaN();
	else if (s == "-nan" || s == "-nanf")
		this->val = -LIMIT_FLOAT.quiet_NaN();
	else
	{
		this->nan = false;
		this->infinite = false;
		if (s.length() == 1 && !std::isdigit(s[0]))
			this->val = static_cast<double>(s[0]);
		else
		{
			this->val = std::strtod(s.c_str(), &end);
			this->valid = (*end == 0 || (*end == 'f' && *(end + 1) == 0));
		}
	}
}

Scalar::~Scalar()
{
}

Scalar &Scalar::operator=(Scalar const &x)
{
	if (this != &x)
	{
		this->val = x.val;
		this->valid = x.valid;
		this->infinite = x.infinite;
		this->nan = x.nan;
	}
	return (*this);
}

std::ostream &Scalar::printChar(std::ostream &os) const
{
	os << "char: ";
	if (!this->valid || this->infinite || this->nan
		|| this->val > LIMIT_CHAR.max()
		|| this->val < -LIMIT_CHAR.max() - 1
		|| fabs(this->val - LIMIT_DOUBLE.quiet_NaN()) < LIMIT_DOUBLE.epsilon())
		std::cout << "impossible";
	else if (!std::isprint(static_cast<char>(this->val)))
		std::cout << "non displayable";
	else
		std::cout << "'" << static_cast<char>(this->val) << "'";
	return (os << std::endl);
}

std::ostream &Scalar::printInt(std::ostream &os) const
{
	os << "int: ";
	if (!this->valid || this->infinite || this->nan
		|| this->val > LIMIT_INT.max()
		|| this->val < -LIMIT_INT.max() - 1)
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(this->val);
	return (os << std::endl);
}

std::ostream &Scalar::printFloat(std::ostream &os) const
{
	os << "float: ";
	if (!this->valid || (!this->infinite && !this->nan && (this->val > LIMIT_FLOAT.max() || this->val < -LIMIT_FLOAT.max())))
		std::cout << "impossible";
	else
	{
		std::cout << this->val;
		if (!this->infinite
			&& !this->nan
			&& std::abs(this->val - std::floor(this->val)) < LIMIT_FLOAT.epsilon())
			std::cout << ".0";
		os << "f";
	}
	return (os << std::endl);
}

std::ostream &Scalar::printDouble(std::ostream &os) const
{
	os << "double: ";
	if (!this->valid)
		std::cout << "impossible";
	else
	{
		std::cout << this->val;
		if (!this->infinite
			&& !this->nan
			&& std::abs(this->val - std::floor(this->val)) < LIMIT_DOUBLE.epsilon())
			std::cout << ".0";
	}
	return (os << std::endl);
}

std::ostream &operator<<(std::ostream &os, Scalar const &scalar)
{
	scalar.printChar(os);
	scalar.printInt(os);
	scalar.printFloat(os);
	scalar.printDouble(os);
	return (os);
}

std::numeric_limits<char> Scalar::LIMIT_CHAR = std::numeric_limits<char>();
std::numeric_limits<int> Scalar::LIMIT_INT = std::numeric_limits<int>();
std::numeric_limits<float> Scalar::LIMIT_FLOAT = std::numeric_limits<float>();
std::numeric_limits<double> Scalar::LIMIT_DOUBLE = std::numeric_limits<double>();
