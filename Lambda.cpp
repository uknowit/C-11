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
    return 0;
}
