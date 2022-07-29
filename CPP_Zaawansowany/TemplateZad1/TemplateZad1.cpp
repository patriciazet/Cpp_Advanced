#include <iostream>

template<typename T>
T max(T a, T b) //szablon
{
    //if (a > b)
    //{
    //    return a;
    //}
    //else
    //{
    //    return b;
    //}

    return a > b ? a : b; //operator potrójny (ternary)
}

template<typename T>
T* max(T* a, T* b) // specjalizacja czêœciowa
{
    return *a > *b ? a : b;
}

template<>
char* max(char* a, char* b) //specjalizacja pe³na 
{
    if (strcmp(a, b) > 0)
    {
        return a;
    }
    else
    {
        return b;
    }
}

template<typename T> 
T max(T* data, const unsigned int size) //przeci¹¿anie szablonu
{
    T tmpMax = data[0]; 
    for (unsigned int i = 1; i < size; ++i)
    {
        if (data[i] > tmpMax)
        {
            tmpMax = data[i];
        }
    }
    return tmpMax;
}

int main()
{
    int num1 = 100;
    int num2 = 10;
    std::cout << "Wieksza int: " << max(num1, num2) << std::endl;
    std::cout << "Wieksza double: " << max(1.23, 21.55) << std::endl;

    int* ptr1 = &num1;
    int* ptr2 = &num2;
    std::cout << "Wiekszy ptr: " << *max(ptr1, ptr2) << std::endl;

    std::cout << "Wiekszy ³anuch: " << max("AAAzaabbba", "AAAccc") << std::endl;

    const unsigned int size = 10;
    double tab[size] = { 0.0, 412.13, 3123.1, 12.33, 32, 11, 23, 56, 1, 555 };
    std::cout << "Najwiekszy element w tablicy:" << max(tab, size) << std::endl;
}
