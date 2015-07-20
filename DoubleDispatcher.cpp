/*
 * DoubleDispatcher.cpp
 *
 *  Created on: 19-Jul-2015
 *      Author: uknowit
 */
#include "../include/DoubleDispatcher.hpp"

// intersect(Shape&,Shape&) function with overrider specified for the desired combinations
// check above in c++0x3
bool Circle::intersect(const Shape& s) const
{
	std::cout <<"intersect(circle,shape)"<<std::endl;
	return s.intersect(*(this));
}

bool Circle::intersect(const Circle&) const
{
	std::cout <<"intersect(circle,circle)\n";
	return true;
}

bool Circle::intersect(const Triangle&) const
{
	std::cout <<"intersect(circle,triangle)\n";
	return true;
}

bool Triangle::intersect(const Shape& s) const
{
	std::cout <<"intersect(triangle,shape)"<<std::endl;
	return s.intersect(*(this));
}

bool Triangle::intersect(const Circle&) const
{
	std::cout <<"intersect(triangle ,circle)\n";
	return true;
}

bool Triangle::intersect(const Triangle&) const
{
	std::cout <<"intersect(triangle ,triangle)\n";
	return true;
}



