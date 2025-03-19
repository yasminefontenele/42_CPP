#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>
#include <deque>

/*int main()
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
}*/

int main()
{
    int arr[] = {1, 4, 3, 4, 5, 6, 7, 8};
    std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));

    std::cout << "Testing with vector..." << std::endl;// the 
    try
    {
        easyfind(vec, 4);
        easyfind(vec, 6);
        easyfind(vec, 8);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    const int arrList[] = {50, 60, 70, 80, 120};
    const std::vector<int> vecConst(arrList, arrList + sizeof(arrList) / sizeof(arrList[0]));

    std::cout << "Testing with const vector..." << std::endl;
    try
    {
        easyfind(vecConst, 50);
        easyfind(vecConst, 80);
        easyfind(vecConst, 90);//Should throw exception
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}