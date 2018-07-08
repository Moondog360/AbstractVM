/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafernan   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 13/38/57 by mafernan          #+#    #+#             */
/*   Updated: 2018/07/08 14:16:17 by mafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Operand.hpp"
#include "Factory.hpp"

// constructor
template<typename T>
Operand<T>::Operand(std::string val, eOperandType type) : _val(val), _type(type) {};
// copy
template<typename T>
Operand<T>::Operand( Operand const & src ) {
	*this = src;
}
// deconstructor
template<typename T>
Operand<T>::~Operand( void ) {}; // deconstructor

// get Type function
template<typename T>
eOperandType Operand<T>::getType( void ) const { // get Type function
	return (_type);
}

// return precision value 
template<typename T>
int Operand<T>::getPrecision( void ) const {
	switch (_type) {
		case int8:
			return (0);
		case int16:
			return (1);
		case int32:
			return (2);
		case FLOAT:
			return (3);
		case DOUBLE:
			return (4);
	}
}

// return the val as a string
template<typename T>
std::string const & Operand<T>::toString( void ) const { 
	return (_val);
}

// = operator
template<typename T>
Operand & Operand<T>::operator=(Operand const & src) {
	if (this != &src) {
		*this = src;
	}
	return (*this);
}

// + operator
template<typename T>
IOperand const * Operand<T>::operator+( IOperand const & rhs ) const { //Sum
	long double		lhs_val = std::stold(this->_val);
	long double		rhs_val = std::stold(rhs.toString());
	long double		result = lhs_val + rhs_val;
	Factory			f;
	int		lhs_prec = this->getPrecision();
	int		rhs_prec = rhs.getPrecision();
	IOperand const * op = NULL;
	if (lhs_prec < rhs_prec)
		op = f.createOperand( rhs.getType() ,std::to_string(result));
	else
		op = f.createOperand( this->getType() ,std::to_string(result));
	return (op);
}