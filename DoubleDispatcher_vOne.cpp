/*
 * DoubleDispatcher_vOne.cpp
 *
 *  Created on: 20-Jul-2015
 *      Author: uknowit
 */
#include "../include/DoubleDispatcher_vOne.hpp"


Rectangle Rectangle::box() const
{
	return *this;
}

Rectangle Circle_vOne::box() const
{
	Rectangle reference;
	return reference;
}


Rectangle Triangle_vOne::box() const
{
	Rectangle reference;
	return reference;
}


bool Circle_vOne::intersect(const Shape_vOne& shape1,const Shape_vOne& shape2)
{
	std::cout<<"Calling circle intersect with other shape"<<std::endl;
	return true;
}

bool Triangle_vOne::intersect(const Shape_vOne& shape1,const Shape_vOne& shape2)
{
	std::cout<<"Calling Triangle intersect with other shape"<<std::endl;
	return true;
}
