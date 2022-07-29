#include <iostream>

double divide(double a, double b)
{
    if (b == 0)
    {
        throw std::string("NIE DZIEL PRZEZ 0");
    }

    return a / b;
}

int main()
{
    int a = 0;
    int b = 0;

    while (true)
    {
        std::cout << "Podaj pierwsza liczbe: ";
        std::cin >> a;
        std::cout << "Podaj drug¹ liczbe: ";
        std::cin >> b;

        try
        {
            double wynik = divide(a, b);
            std::cout << "Wynik dzielenia: " << wynik << std::endl;
        }
        catch (std::string& error)
        {
            std::cout << error << std::endl;
        }

        std::cout << std::endl;

    }
}
