/*
 * HierachyImplementor.cpp
 *
 *  Created on: 16-Jul-2015
 *      Author: uknowit
 */
#include "../include/BaseClass.hpp"
#include "../include/DerivedClass.hpp"

BaseClass::BaseClass(std::string& className)
{
	m_ClassName=className;
}


BaseClass* BaseClass::clone_object()
{
	return this;
}

std::string DerivedClass::get_name()
{
	return m_ClassName;
}
