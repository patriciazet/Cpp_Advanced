#include <iostream>
#include "StaticTable.h"


int main()
{
    StaticTable<int, 10> table1;

    for (int i = 0; i < 10; ++i)
    {
        table1[i] = i;
    }

    for (int i = 0; i < 10; ++i)
    {
        std::cout << "tab[" << i << "]=" << table1[i] << std::endl;
    }

    StaticTable<bool, 2> table2;
    table2[0] = true;


}
