#ifndef _DOUBLE_DISPATCHER_HPP
#define _DOUBLE_DISPATCHER_HPP

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class Circle;
class Triangle;

class Shape {
public:
	virtual ~Shape(){}
	virtual bool intersect(const Shape&) const =0;
	virtual bool intersect(const Circle&) const =0;
	virtual bool intersect(const Triangle&) const =0;
};

/*https://en.wikipedia.org/wiki/C%2B%2B11#Explicit_overrides_and_final*/
class Circle : public Shape {
public:
	bool intersect(const Shape&) const override;
	virtual bool intersect(const Circle&) const override;
	virtual bool intersect(const Triangle&) const override;
};

class Triangle : public Shape {
public:
	bool intersect(const Shape&) const override;
	virtual bool intersect(const Circle&) const override;
	virtual bool intersect(const Triangle&) const override ;
};

#endif
