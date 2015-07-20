#ifndef _DOUBLE_DISPATCHER_VONE_HPP
#define _DOUBLE_DISPATCHER_VONE_HPP

#include <string>
#include <iostream>
class Rectangle;

class Shape_vOne {
public:
	virtual ~Shape_vOne(){}
	virtual Rectangle box() const = 0;
	virtual bool intersect(const Shape_vOne& shape1, const Shape_vOne& shape2) =0;
};

class Rectangle: public Shape_vOne {
public:
	virtual Rectangle box() const override;
	bool intersect(const Rectangle&, const Rectangle&){return true;};
	bool intersect(const Shape_vOne& shape1, const Shape_vOne& shape2) override
	{
		return intersect(shape1.box(),shape2.box());
    }
};

class Circle_vOne:public Shape_vOne {
public:
	virtual Rectangle box() const override;
	bool intersect(const Shape_vOne& shape1, const Shape_vOne& shape2) override;
};


class Triangle_vOne:public Shape_vOne {
public:
	virtual Rectangle box() const override;
	bool intersect(const Shape_vOne& shape1, const Shape_vOne& shape2)  override;
};

#endif
