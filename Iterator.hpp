/*
 * Iterators.hpp
 *
 *  Created on: Oct 14, 2016
 *      Author: root
 */

#ifndef ITERATORS_HPP_
#define ITERATORS_HPP_

class Iterators {
public:
	void inputOutputIterators();
	template<typename X>
	double productCalc(X& container)
	{
	    typename X::iterator iter;
		iter = container.begin();
		double prod = 1;
		while(iter != container.end())
		{
			prod*=*iter++;
		}
		return prod;
	}

	template<typename Iter>
	double productCalcIter(Iter start, Iter end)
	{
		double prod = 1;
		while(start != end)
		{
			prod*=*start++;
		}
		return prod;
	}

	template<typename Iter>
	Iter generateIter(Iter start,  Iter end)
	{
		Iter temp;
		while(start != end)
		{
			if(*start % 2 != 0)
			{
				temp = start;
				break;
			}
			else
			{
				start++;
			}
		}
		return temp;
	}

};




#endif /* ITERATORS_HPP_ */
