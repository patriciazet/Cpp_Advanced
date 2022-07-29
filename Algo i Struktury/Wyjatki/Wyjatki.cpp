#include <iostream>

int readParameters(int howManyNumbers, int* tableWithParametrs) //funkcja ktora zwraca kod b³êdu
{
    if (tableWithParametrs == nullptr)
    {
        return -1; //oznacza ze nie otrzymalismy poprawnej tablicy
    }

    if (howManyNumbers < 0)
    {
        return -2; //oznacza ze dostalismy bledna (ujemna) ilosc parametrow do wczytywania
    }

    for (int i = 0; i < howManyNumbers; ++i)
    {
        //Kod wczytujacy parametry
        //tableWithParametrs[i] = .....?
    }

    return 0; //oznacza brak b³êdu

}

static int error = 0; //globalna flaga b³êdu

Vector readParameters(int howManyNumbers)
{
    error = 0; //zerowanie flagi b³êdu
    Vector vect;

    if (howManyNumbers < 0)
    {
        error = -2;
        return vect; //zwracamy pusty/domyslny obiekt ktorego nie powinno sie uzywac
    }

    for (int i = 0; i < howManyNumbers; ++i)
    {
        // vect.push_back(); // zape³nanie vectora w pêtli
    }

    return vect;

}

Vector readParametersException(int howManyNumbers)
{
    error = 0; //zerowanie flagi b³êdu
    Vector vect;

    if (howManyNumbers < 0)
    {
        throw std::string("howManyNumbers nie moze byc mniejsze niz 0");
    }

    for (int i = 0; i < howManyNumbers; ++i)
    {
        // vect.push_back(); // zape³nanie vectora w pêtli
    }

    return vect;

}

int main3()
{
    Vector vect;

    try
    {
        vect = readParameters(7);
    }
    catch (std::string& errorString)
    {
        std::cout << errorString << std::endl;

        throw errorString; //rethrow
    }
    catch (...) //tak sie nie powinno raczej robic
    {
        std::cout << "Jakis niezany blad" << std::endl;
    }

}

int main1()
{
    int* tab = new int [7];
    int error = readParameters(7, tab);

    if (!error)
    {
        //tutaj kod ktory ktory sie wykona jak funkcja readParameters zadzia³a
    }
    else
    {
        std::cout << "Zda¿y³o siê coœ z³ego!\n";
        //obs³uga b³êdów
    }

}

int main2()
{
    int* tab = new int[7];
    Vector vect = readParameters(7);

    if (!error) //sprawdzanie flagi b³êdu
    {
        //tutaj kod ktory ktory sie wykona jak funkcja readParameters zadzia³a
    }
    else
    {
        std::cout << "Zda¿y³o siê coœ z³ego!\n";
        //obs³uga b³êdów
    }

}