// Za pomoc¹ std::set sprawdz czy w podanym ³añcuchu znaków wystêpuj¹ wszystkie litery alfabetu.

#include <iostream>
#include <set>
#include <algorithm>

bool containsAllLetters(std::string text)
{
    std::set<char> alphabetChecker;

    for (std::string::iterator itText = text.begin(); itText != text.end(); itText++)
    {
        if (*itText >= 65 && *itText <= 90) //zamien duze litery na ma³e
        {
            *itText += 32;
        }

        if (*itText >= 97 && *itText <= 122) //wrzucamy do naszego kontenera tylo male litery
        {
            alphabetChecker.insert(*itText); //umieszcza w zbiorze unikalne wartosci, duplikaty sa pomijane
        }
    }

    return alphabetChecker.size() == 26;
}

unsigned char toLowerCase(unsigned char c) 
{
    return std::tolower(c);
}

struct removeNonLetters2 //funktor
{
    bool operator() (unsigned char c)
    {
        return !((c >= 97 && c <= 122) || (c >= 65 && c <= 90));
    }
};

bool containsAllLetters2(std::string text)
{
    auto removeNonLetters = [](unsigned char c)
    {
        return !((c >= 97 && c <= 122) || (c >= 65 && c <= 90));
    };

    text.erase(std::remove_if(text.begin(), text.end(), removeNonLetters),text.end()); //erase remove idiom
    //std::transform(text.begin(), text.end(), text.begin(), toLowerCase); //to samo co nizej, ale bez uzycia lambdy

    //funckja transform dla kazdego elementu z zakresu (text.begin -> text.end) wywo³a przekazan¹ unary operation
    //a nastêpnie przechowa wynik w text.begin()
    std::transform(text.begin(), text.end(), text.begin(), //zamiana na ma³e litery 
        [](unsigned char c) { return std::tolower(c); });

    std::set<char> alphabetChecker;

    std::for_each(text.begin(), text.end(),  //dla kazdego elementu wywo³aj lambdê
        [&alphabetChecker](unsigned char c) { alphabetChecker.insert(c); });

    return alphabetChecker.size() == 26;
}

bool containsAllLetters3(const std::string& text)
{
    std::set<char> alphabetChecker;

    auto fillSetWithOnlyLetters = [&alphabetChecker](unsigned char c)
    {
        if (c >= 65 && c <= 90)
        {
            alphabetChecker.insert(std::tolower(c));
        }

        if (c < 97 && c < 122)
        {
            alphabetChecker.insert(c);
        }
    };

    const unsigned char maleA = 65;
    const unsigned char duzeA = 97;
    const unsigned char maleZ = 90;
    const unsigned char duzeZ = 122;

    auto fillSetWithOnlyLetters2 = [&alphabetChecker, &maleA, &duzeA, &maleZ, &duzeZ ](unsigned char c)
    {
        if ((c >= maleA && c <= maleZ) || (c <= duzeA && c <= duzeZ))
        {
            alphabetChecker.insert(std::tolower(c));
        }
    };

    std::for_each(text.begin(), text.end(), fillSetWithOnlyLetters);

    return alphabetChecker.size() == 26;
}

int main()
{
    std::cout << "Hello World!\n";
}

