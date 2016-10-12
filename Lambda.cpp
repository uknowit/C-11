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
#include <ctime>
#include <locale>
#include <unistd.h>
/*
 *  Lambda signature :
 *  [capture list(reference(&) or value)](arguments) mutable -> return_type{ function_body}
 *  ex:- [&os, mod](int x) mutable ->void {}
 */

class LambdaCaptureList
{
	public:
		LambdaCaptureList(std::string creationTime):mCreationTime(creationTime){}
		void invokeLambda(std::string& currentTime)
		{
			std::function<void()> lambdaFunc = [&, currentTime, this ]() mutable{
				size_t pos = currentTime.find_first_of(" ");
				currentTime = currentTime.substr(pos, currentTime.size());
				std::cout<<"Current  time::"<<currentTime<<std::endl;
				std::cout<<"Creation time::"<<mCreationTime<<std::endl;
			};

			std::function<void()> lambdaFuncOne = [&,  this ]() mutable{
							size_t pos = currentTime.find_first_of(" ");
							currentTime = currentTime.substr(pos, currentTime.size());
							std::cout<<"Current  time::"<<currentTime<<std::endl;
							std::cout<<"Creation time::"<<mCreationTime<<std::endl;
						};
			lambdaFunc();
			std::cout<<"Current  time outside::"<<currentTime<<std::endl;
			lambdaFuncOne();
			std::cout<<"Current  time outside after reference::"<<currentTime<<std::endl;
		}
	private:
		std::string mCreationTime;
};

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

double sqrt_fun(double rational)
{
	return sqrt(rational);
}

void lambda_type(double aa)
{
	std::cout<<"Invoking with value:"<<aa<<std::endl;
	double (*ptr2)(double) = [&](double a){
		return sqrt(a);};//Capture by reference is not allowed;
	std::cout<<ptr2(aa)<<std::endl;
}

int main()
{
	int execNum = 0;
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

    double (*ptr1)(double) = [](double a){
    	return sqrt(a);};

    //double (*ptr3)(int) = [](double a){ return sqrt(a);}; argument is different
    ptr1 = sqrt_fun;
    std::cout<<ptr1(25.0)<<std::endl;
    lambda_type(37.0881);
    std::cout<<execNum<<std::endl;
    std::locale::global(std::locale("en_IN.utf8"));
    std::time_t t = std::time(NULL);
    char mbstr[100], secStr[100];
    if (std::strftime(mbstr, sizeof(mbstr), "%A %c", std::localtime(&t))) {
    	std::string ls = std::string(mbstr);
    	LambdaCaptureList lcapList(ls);
    	usleep(2000000);
    	std::time_t t1 = std::time(NULL);
    	std::strftime(secStr, sizeof(secStr), "%A %c", std::localtime(&t1));
    	std::string lslocal = std::string(secStr);
    	lcapList.invokeLambda(lslocal);
    }
    return 0;
}
