#include "Span.hpp"

//from subject
int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
}

//my main
/*
int main() {
    try {
        Span sp(5);//cria span com no max 5 elementos
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Menor intervalo: " << sp.shortestSpan() << std::endl;
        std::cout << "Maior intervalo: " << sp.longestSpan() << std::endl;

        //Tentando adicionar um número extra para testar exceção
        sp.addNumber(42);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    //Teste com múltiplos números de uma vez
    try {
        Span sp2(10000);
        std::vector<int> bigSet;
        for (int i = 0; i < 10000; i++)
            bigSet.push_back(i * 2); //Números pares

        sp2.addRange(bigSet.begin(), bigSet.end());

        std::cout << "Menor intervalo (grande conjunto): " << sp2.shortestSpan() << std::endl; // Deve ser 2
        std::cout << "Maior intervalo (grande conjunto): " << sp2.longestSpan() << std::endl;  // Deve ser 19998
    }
    catch (const std::exception& e)
    {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    return 0;
}
*/