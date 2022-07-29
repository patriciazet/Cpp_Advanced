//Zad 2.
//Utworzyæ 2 listy po 10 elemmentów.
//Przenieœæ elementy od 3 do 7 z jednej listy do drugiej na pozycjê 3.
//Wyœwietliæ listy.
#include <iostream>
#include <list>


int main()
{
    std::list<int> list1 = { 1,2,3,4,5,6,7,8,9,10 };
    std::list<int> list2{ 11,12,13,14,15,16,17,18,19,20 };

    //std::advance(it, 1); to samo co ++it
    for (auto it = list1.begin(); it != list1.end(); ++it)
    {
        std::cout << *it << "; ";
    }

    for (auto it = list2.rbegin(); it != list2.rend(); ++it)
    {
        std::cout << *it << "; ";
    }
    
    auto copyFrom = list1.begin();
    std::advance(copyFrom, 2);

    auto copyTo = list1.begin();
    std::advance(copyTo, 7);

    auto to = list2.begin(); //przsuwam iterator w ktore miejsce chce skopiowac
    std::advance(to, 3);

    //list2.splice(to, list1); //na 3 pozycje przenies mi cal¹ liste1
    //list2.splice(list2.end(), list1); //polacz obie listy, dolacz list1 na koniec list2

    list2.splice(to, list1, copyFrom, copyTo);


    std::cout << std::endl << std::endl << std::endl;
    for (auto it = list2.begin(); it != list2.end(); ++it)
    {
        std::cout << *it << "; ";
    }

    std::cout << std::endl << std::endl << std::endl;

    for (auto it = list1.begin(); it != list1.end(); ++it)
    {
        std::cout << *it << "; ";
    }
}
