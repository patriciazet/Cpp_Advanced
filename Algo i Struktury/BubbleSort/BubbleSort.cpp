#include <iostream>

void bubbleSort(int* tab, const unsigned int size)
{
    bool swapped = false;

    do
    {
        swapped = false;

        for (unsigned int i =0; i<size-1; ++i) //zadanie domowe: OPTYMALIZACJA: zrobic tak ¿eby nie ruszaj elemnetów koñcowych, po tej zmianie mo¿na usun¹c flagê swapped
        {
            if (tab[i] > tab[i+1])
            {
                int tmp = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = tmp;
                swapped = true;
            }
        }

    } while (swapped);

}

int main()
{
    const unsigned int size = 10;
    int tab[size] = { 8, 3, 5, 0, 2, 9, 1, 7, 6, 4};

    for (int i = 0; i < size; ++i)
    {
        std::cout << "[" << i << "]= " << tab[i] << std::endl;
    }
    std::cout << std::endl;

    bubbleSort(tab, size);

    for (int i = 0; i < size; ++i)
    {
        std::cout << "[" << i << "]= " << tab[i] << std::endl;
    }

}
