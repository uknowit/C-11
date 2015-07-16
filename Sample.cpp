//============================================================================
// Name        : Sample.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "../include/DerivedClass.hpp"

using namespace std;
void function_handler(BaseClass* baseObj)
{
	NormalClass* normalObj=dynamic_cast<NormalClass*>(baseObj);
	if(NULL!=normalObj)
		std::cout<<"Non polymorphic target"<<std::endl;
}
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	string date="16-07-2015";
	DerivedClass* dClass=new DerivedClass(date);
	BaseClass* cloneObj= dClass->clone_object();
	DerivedClass* castObj=dynamic_cast<DerivedClass*>(cloneObj);
	std::cout<<castObj->get_name()<<std::endl;
	DerivedClass* dObj=new DerivedClass(date);
	function_handler(dObj);
	return 0;
}
