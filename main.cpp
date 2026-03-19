
#include <iostream>
#include "NumberList.h"

int main()
{
    NumberList lista;

    lista.Init();

    lista.Add(5);
    lista.Add(2);
    lista.Add(-13);
    int numar = 100;
    lista.Add(numar);
    lista.Add(333);

    lista.Print();
    std::cout << std::endl;

    lista.Sort();
    lista.Print();
    return 0;
}