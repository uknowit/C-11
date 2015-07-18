#ifndef _DERIVED_CLASS_HPP
#define _DERIVED_CLASS_HPP
#include <stdio.h>
#include <string>
#include "BaseClass.hpp"

class DerivedClass:public BaseClass,public NormalClass {
public:
	DerivedClass(std::string& className):BaseClass(className){
		m_ClassName=className;
	}
	virtual ~DerivedClass(){}
	virtual std::string get_name();
private:
	std::string m_ClassName;
};

class SecondOrderDerivedClass:public DerivedClass {
public:
	SecondOrderDerivedClass(std::string& className):DerivedClass(className)
	{
	}
};

class AnotherDerivedClass:public BaseClass {
public:
	AnotherDerivedClass(std::string& className):BaseClass(className)
	{

	}
	virtual std::string get_name(){return "AnotherDerivedClass";}
};

#endif
