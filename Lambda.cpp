/*
 * LambdaExamples.cpp
 *
 *  Created on: Oct 12, 2016
 *      Author: root
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

/*
 *  Lambda signature :
 *  [capture list(reference(&) or value)](arguments) mutable -> return_type{ function_body}
 *  ex:- [&os, mod](int x) mutable ->void {}
 */

void print_modulo(const std::vector<int>& myVec, std::ostream& os, int mod)
{
    std::for_each(myVec.begin(), myVec.end(), [&os, mod](int x)  ->void {
            if( x % mod == 0)
                os<<x<<"\n";
            });
}

class Modulo_print
{
    public:
        std::ostream &m_os;
        int m_mod;
        Modulo_print(std::ostream& os, int mod):m_os(os),m_mod(mod){}
        void operator()(int x)const {
            if(x % m_mod == 0)
                m_os<<x<<"\n";
        }
};

void print_module_local_class(const std::vector<int>& myVec, std::ostream& os, int mod)
{

    class Modulo_print
    {
        public:
            std::ostream &m_os;
            int m_mod;
            Modulo_print(std::ostream& os, int mod):m_os(os),m_mod(mod){}
            void operator()(int x)const {
                if(x % m_mod == 0)
                    m_os<<x<<"\n";
            }
    };
    std::for_each(myVec.begin(), myVec.end(), Modulo_print{os, mod});
}

std::function<void(char* b, char* e)> rev = [](char *b, char *e){
	if(1 < e-b)
	{

		std::swap(*b, *--e);
		rev(++b, e);
	}
};

void func_rec(std::string& str1, std::string& str2)
{
	rev(&str1[0], &str1[0]+str1.size());
	rev(&str2[0], &str2[0]+str2.size());
}

void func_non_rec(std::string& str1, std::string& str2)
{
	auto rev = [](char *b, char *e){while(1 < e- b){std::swap(*b++, *--e);}};
	rev(&str1[0], &str1[0]+str1.size());
	rev(&str2[0], &str2[0]+str2.size());
}

int main()
{
    std::cout<<"Printing the header "<<std::endl;

    std::vector<int> myVec = {3, 5, 7, 8, 12, 34, 45, 65, 78, 89 , 93};
    print_modulo(myVec, std::cout, 3);

    std::cout<<"**********************"<<std::endl;
    std::cout<<"Using function object"<<std::endl;
    for_each(myVec.begin(), myVec.end(), Modulo_print{std::cout, 3});

    std::cout<<"**********************"<<std::endl;
    std::cout<<"Using local class"<<std::endl;
    print_module_local_class(myVec, std::cout, 3);

    std::cout<<"**********************"<<std::endl;
    std::cout<<"Using recursive function"<<std::endl;
    std::string str1 = "eiltonodslemac";
    std::string str2 = "malayalam";
    func_rec(str1, str2);
    std::cout<<str1<<" "<<str2<<std::endl;

    std::cout<<"**********************"<<std::endl;
    std::cout<<"Using non-recursive function"<<std::endl;
    func_non_rec(str1, str2);
    std::cout<<str1<<" "<<str2<<std::endl;
    return 0;
}
