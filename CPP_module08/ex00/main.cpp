#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
    try
    {
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);

        std::cout << "Testing std::vector:" << std::endl;
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Encontrado: " << *it << std::endl;

        std::cout << "Testing std::list:" << std::endl;
        std::list<int> lst;
        lst.push_back(10);
        lst.push_back(20);
        lst.push_back(30);

        std::list<int>::iterator it2 = easyfind(lst, 20);
        std::cout << "Encontrado: " << *it2 << std::endl;

        std::cout << "testing numbers that are not in the list:" << std::endl;
        easyfind(vec, 42);//Deve lançar exceção

    }
    catch (const std::exception& e)
    {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    return 0;
}
