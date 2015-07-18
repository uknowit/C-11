//============================================================================
// Name        : Sample.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "../include/DerivedClass.hpp"
/*
 * Derived class
 *  _________
 * |         |
 * |  vptr   |
 * |         |
 * |_________|
 * 		|		 _________				Type info	          Type info
 * 		|______	|         |									_____________
 * 				|  vtable |          _______________		|       	|
 * 				|         |-------->|				| ----->| Base class|
 * 				|_________|			|	Bases		|		|___________|
 * 									|_______________|	     ____________
 * 															|       	 |
 *															|Normal class|
 *															|____________|
 */
using namespace std;
void function_handler(BaseClass* baseObj)
{
	NormalClass* normalObj=dynamic_cast<NormalClass*>(baseObj);
	if(NULL!=normalObj)
	{
		std::cout<<"Non polymorphic target"<<std::endl;
		normalObj->sampleFunction();
	}
	else
	{
		std::cout<<"Dynamic cast returned NULL";
	}
}
int main()
{
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	string date="16-07-2015";
	DerivedClass* dClass=new DerivedClass(date);
	BaseClass* cloneObj= dClass->clone_object();
	DerivedClass* castObj=dynamic_cast<DerivedClass*>(cloneObj);
	std::cout<<castObj->get_name()<<std::endl;
	DerivedClass* dObj=new DerivedClass(date);
	function_handler(dObj);
	AnotherDerivedClass* adObj= new AnotherDerivedClass(date);
	function_handler(adObj);
	return 0;
}
