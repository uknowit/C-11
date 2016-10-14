/*
 * Iterators.cpp
 *
 *  Created on: Oct 14, 2016
 *      Author: root
 */

#include <vector>
#include <iostream>
#include "Iterators.hpp"
#include <algorithm>
#include <iterator>


void Iterators::inputOutputIterators()
{
	double nums[] = {1.2, 3.5, 3.0, 2.8};
	std::vector<int> vec;
	std::vector<int>::iterator vecIter;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);

	for(vecIter = vec.begin(); vecIter != vec.end(); ++vecIter)
	{
		std::cout<<*vecIter<<std::endl;
		*vecIter = *vecIter + 1;
	}
	std::cout<<"****************"<<std::endl;
	std::cout<<"Updated vector list"<<std::endl;
	std::for_each(vec.begin(), vec.end(), [](int num){std::cout<< num <<std::endl;});
	std::cout<<"****************"<<std::endl;
	std::back_inserter(vec) = 5;
	//std::front_inserter(vec) = 1; Not supported for vector as there is no push_front;
	std::inserter(vec, vecIter) = 99;
	std::ostream_iterator<int> outIter(std::cout, "::");
	std::copy(vec.begin(), vec.end(), outIter);
	//std::copy(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(), std::back_inserter(vec));
	std::cout<<productCalc(vec)<<std::endl;
	//std::cout<<productCalc(nums)<<std::endl;
	std::cout<<productCalcIter(nums,nums+((sizeof(nums)/sizeof(nums[0]))))<<std::endl;
	std::cout<<"************"<<std::endl;
	std::cout<<"Odd numbers........."<<std::endl;
	std::vector<int>::iterator oddIter = generateIter(vec.begin(), vec.end());
	while(oddIter != vec.end())
	{
		std::cout<<*oddIter<<std::endl;
		oddIter = generateIter(++oddIter, vec.end());
	}
}
