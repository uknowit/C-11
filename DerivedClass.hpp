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

#endif
