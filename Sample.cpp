//============================================================================
// Name        : Sample.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <typeinfo>
#include "../include/DerivedClass.hpp"
#include "../include/DoubleDispatcher.hpp"
#include "../include/DoubleDispatcher_vOne.hpp"
#include <vector>
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
	void* addr=dynamic_cast<NormalClass*>(baseObj);
	if(NULL!=normalObj)
	{
		std::cout<<"Non polymorphic target"<<std::endl;
		normalObj->sampleFunction();
		std::cout<<addr<<std::endl;//printing starting address of polymorphic type
	}
	else
	{
		std::cout<<"Dynamic cast returned NULL"<<std::endl;;
	}
}

void reference_handler(BaseClass& baseRef)
{
	try
	{
		NormalClass normalClassRef=dynamic_cast<NormalClass&>(baseRef);
		normalClassRef.sampleFunction();
		std::cout<<&normalClassRef<<std::endl;
	}
	catch(const std::bad_cast& castExp)
	{
		std::cout<<"bad_cast exception thrown. Handling it..."<<std::endl;
	}
}

void test( Circle& c,Triangle& t)
{
	std::vector<std::pair<Shape*,Shape*>> vs{ {&t,&t}, {&t,&c}, {&c,&t}, {&c,&c} };
	for (auto p : vs)
	{
		p.first->intersect(*p.second);
	}
}

void test_vOne( Circle_vOne& c,Triangle_vOne& t)
{
	std::vector<std::pair<Shape_vOne*,Shape_vOne*>> vs{ {&t,&t}, {&t,&c}, {&c,&t}, {&c,&c} };
	for (auto p : vs)
	{
		p.first->intersect(*p.first,*p.second);
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
	DerivedClass dReference(date);
	reference_handler(dReference);
	AnotherDerivedClass adReference(date);
	reference_handler(adReference);
	Triangle triniityTriangle;
	Circle trinityCircle;
	test(trinityCircle,triniityTriangle);
	Triangle_vOne diaryTriangle;
	Circle_vOne diaryCircle;
	test_vOne(diaryCircle,diaryTriangle);
	return 0;
}
