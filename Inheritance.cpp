#include<iostream>
#include<string>
/* In public inheritance , public --> public, protected-->protected and private-->private. Derived is a Base
 * Can be used in the interface which takes base class pointer.
 * 
 * In Protected inheritance , public-->protected protected-->protected and private-->private. Derived is implemented
 * in terms of Base but not a base. Cannot be used in the interface which takes base class pointer. Can implement
 * base class virtual function and can expose base class public and protected method in its interface.
 *
 * In Private inheritance, public->private, protected->private and private-->private. Derived is implemented in terms of 
 * Base but not a base object. Cannot be used in the interface which takes base class pointer. Can implement
 * base class virtual function and can expose base class public  method in its interface.
 * Both protected and private child can access public, protected methods of base.
 */
class Base 
{
    public:
        void public_base_fun()
        {
            std::cout<<"public_base_fun"<<std::endl;
        }
        std::string public_base_variable ="AllowAll";
        
        void calling_mem_fun()
        {
            std::cout<<"Invoking pure_private_base_fun"<<std::endl;
            private_base_fun();
        }
    protected:
        void protected_base_fun()
        {
            std::cout<<"protected_base_fun"<<std::endl;
        }
        std::string proteced_base_variable = "AllowProtected";

    private:
        void private_base_fun()
        {
            std::cout<<"private_base_fun"<<std::endl;
        }
        std::string private_base_variable = "PrivateVariable";
        virtual void pure_private_base_fun() = 0;
};

class Derived: public Base 
{
    public:
        void pure_private_base_fun()
        {

            std::cout<<"Have access to protected variable"<<proteced_base_variable<<std::endl;
            std::cout<<"Have access to public variable"<<public_base_variable<<std::endl;
        }
};

class Derived_Protected:protected Base 
{
    public:
    void pure_private_base_fun()
    {
        std::cout<<"Have access to protected variable"<<proteced_base_variable<<std::endl;
        std::cout<<"Have access to public variable"<<public_base_variable<<std::endl;
    }
};

class Derived_Private:private Base
{
    public:
    using Base::calling_mem_fun;
    using Base::protected_base_fun;
    void pure_private_base_fun()
    {
        std::cout<<"Have access to protected variable"<<proteced_base_variable<<std::endl;
        std::cout<<"Have access to public variable"<<public_base_variable<<std::endl;
    }
};

class Derived_Private_child:public  Derived_Private
{
    public:    
        //using Base::calling_mem_fun;
        void pure_private_base_fun()
        {
            std::cout<<"Nothing can be called from here"<<std::endl;
            //std::cout<<"Have access to protected variable"<<proteced_base_variable<<std::endl;
            //std::cout<<"Have access to public variable"<<public_base_variable<<std::endl;
        }
};

class Derived_Protected_child:public Derived_Protected
{
    public:
        using Base::calling_mem_fun;
        using Base::protected_base_fun;
        void pure_private_base_fun()
        {
            std::cout<<"Have access to protected variable"<<proteced_base_variable<<std::endl;
            std::cout<<"Have access to public variable"<<public_base_variable<<std::endl;
        }
};

void calling_interface(Base* baseObj)
{
    baseObj->calling_mem_fun();
}

int main()
{
    Derived_Private dPvt;
    Derived_Protected dProt;
    Derived_Protected_child dProtChild;
    Derived_Private_child dPvtChild;
    dPvt.pure_private_base_fun();
    dProt.pure_private_base_fun();
    dProtChild.pure_private_base_fun();
    dPvtChild.pure_private_base_fun();
    std::cout<<"========================"<<std::endl;
    dPvt.calling_mem_fun();
    return 0;
}
