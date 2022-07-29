#include <iostream>

struct A
{
    virtual void foo() const
    {
        std::cout << "A::foo()" << std::endl;
    }

    virtual void foo(int)
    {
        std::cout << "A::foo(int)" << std::endl;
    }

    virtual void boo() = 0; //przynajmniej jedna czysto wirtualna
};

struct B : A
{
    void boo() override
    {
        std::cout << "B::boo" << std::endl;
    }
};

int main()
{
    B objB;
    A objA;
    A* ptrA = &objB;
}
