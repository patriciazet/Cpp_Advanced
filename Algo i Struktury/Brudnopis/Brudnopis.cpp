#include <iostream>

void readNumbers(int* tab, const unsigned int size)
{
    for (unsigned int i = 0; i < size; ++i)
    {
        std::cout << "Podaj " << i << " liczbe: ";
        std::cin>>tab[i];
    }
}

int findMinumum(int* tab, const unsigned int size)
{
    int min = 0;

    if (size > 0 && tab != nullptr)
    {
        min = tab[0];

        int i = 1;
        while (i < size - 1)
        {
            if (tab[i] < min)
            {
                min = tab[i];
            }
            ++i;
        }
    }

    return min;
}

int main()
{
    std::cout << "Ile liczb wczytac?" << std::endl;
    unsigned int numberCount = 0;
    std::cin >> numberCount;

    if (numberCount > 0)
    {
        int* tab = new int[numberCount];
        readNumbers(tab, numberCount);
        int min = findMinumum(tab, numberCount);
        std::cout << "Najmniejsza liczba to: " << min <<std::endl;
        delete[] tab;
    }

}

