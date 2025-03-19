#include "MutantStack.hpp"
#include <iostream>
#include <list>

//from subject
/*int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;//print what's on top of the stack
    mstack.pop();//remove the top element
    std::cout << mstack.size() << std::endl;//print the size of the stack
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;//skip the first element
    --it;//go back to the first element
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}*/

//my main
int main()
{
    // Teste com MutantStack
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "----- Starting interactions with MutanStack -----"<< std::endl;
    std::cout << "First interaction..."<< std::endl;
    std::cout << "Top: " << mstack.top() << std::endl;
    std::cout << "Size: " << mstack.size() << std::endl;
    mstack.pop();//remove the element from the top
    std::cout << std::endl;
    std::cout << "After removing the top..."<< std::endl;
    std::cout << "Top: " << mstack.top() << std::endl;
    std::cout << "Size: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    /*std::cout << std::endl;
    std::cout << "Topo da pilha: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Topo da pilha após pop: " << mstack.top() << std::endl;*/

    // Iteração sobre MutantStack
    std::cout << std::endl;
    std::cout << "MutantStack elements:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    // Teste com std::list para comparação
    std::cout << std::endl;
    std::cout << "----- Starting interactions with the list for comparison -----"<< std::endl;
    std::list<int> lstTest;
    lstTest.push_back(5);
    lstTest.push_back(17);
    std::cout << "Top: " << lstTest.back() << std::endl;
    lstTest.pop_back();
    std::cout << "Size: " << lstTest.size() << std::endl;
    lstTest.push_back(3);
    lstTest.push_back(5);
    lstTest.push_back(737);
    lstTest.push_back(0);

    // Iteração sobre std::list
    std::cout << "std::list elements:" << std::endl;
    for (std::list<int>::iterator it = lstTest.begin(); it != lstTest.end(); ++it) {
        std::cout << *it << std::endl;
    }

    return 0;
}