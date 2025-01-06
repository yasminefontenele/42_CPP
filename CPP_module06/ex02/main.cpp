
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>//for rand()

Base *generate(void)
{
    Base *ret = NULL;
    int r = rand() % 3;

    if (r == 0)
        ret = new A;
    else if (r == 1)
        ret = new B;
    else
        ret = new C;
}

void identify(Base* p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (...) {}

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (...) {}

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (...) {}

    std::cout << "Unknown type" << std::endl;
}

int main()
{
    for (int i = 0; i < 10; ++i)
    {
        Base* obj = generate();
        std::cout << "Using pointer: ";
        identify(obj);
        std::cout << "Using reference: ";
        identify(*obj);
        delete obj;
    }

    return 0;
}