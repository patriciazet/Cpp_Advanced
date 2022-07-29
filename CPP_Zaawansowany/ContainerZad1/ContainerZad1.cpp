#include <iostream>
#include <vector>

template<typename T>
void bubbleSort(std::vector<T>& vec)
{
    for (size_t i = 0; i < vec.size() - 1; ++i)
    {
        for (size_t j = 0; j < vec.size() - 1; ++j)
        {
            if (vec.at(j) > vec.at(j + 1))
            {
                //zamienic miejscami
                std::swap(vec.at(j), vec.at(j + 1));
                //T tmp = vec.at(j);
                //vec.at(j) = vec.at(j + 1);
                //vec.at(j + 1) = tmp;
            }
        }
    }
}

template<typename T>
void printVector(const std::vector<T>& vec) {
    for (size_t i = 0; i < vec.size() - 1; ++i)
    {
        std::cout <<"[" << i << "]=" << vec.at(i) << ";\n";
    }
}

int main()
{
    std::vector<int> ints;
        
    //zadanie: utworz funkcê szablonow¹, która wczyta do wektora dowolny typ
    int input = 0;
    do
    {
        std::cout << "Podaj liczbe: ";

        std::cin >> input;

        ints.push_back(input);

    } while (input != 0);

    //Wersja 2: 0 nie bedzie wepchniête do kontenera
    //int input = 0;
    //std::cin >> input;
    //while (input != 0)
    //{
    //    ints.push_back(input);
    //    std::cin >> input;
    //} 

    int sum = 0;
    for (int i = 0; i < ints.size(); ++i)
    {
        sum += ints[i];
    }
    std::cout << "Suma liczb w vectorze: " << sum << std::endl;

    bubbleSort(ints);
    printVector(ints);

}


= {0,1,2,3,4,5,6,7,8,9}