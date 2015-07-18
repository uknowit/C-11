#ifndef _BASE_CLASS_HPP
#define _BASE_CLASS_HPP

#include <stdio.h>
#include <string>
#include <stdlib.h>

class BaseClass {
public:
	BaseClass(){}
	BaseClass(std::string& className);
	virtual ~BaseClass(){}
	virtual BaseClass* clone_object();
	virtual std::string get_name()=0;
private:
	std::string m_ClassName;

};

class NormalClass {
	public:
		void sampleFunction();
};
#endif
