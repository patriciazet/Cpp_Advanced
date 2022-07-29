//Zad 5.
//Korzystaj�c ze stosu odwr�� �a�uch znak�w
#include <iostream>
#include <stack>

int main()
{
    std::string poem = "Ala ma kota, a kot ma pchly";
    
    std::stack<char> reverser;

    for (size_t i = 0; i < poem.size(); ++i)
    {
        reverser.push(poem[i]);
    }

    std::cout << poem << std::endl << "ODWRACAM" << std::endl;

    while (!reverser.empty())
    {
        std::cout << reverser.top();
        reverser.pop();
    }
    
    //Wypisywanie przy uzyciu for
    //for (size_t i = reverser.size(); i > 0; --i)
    //{
    //    std::cout << reverser.top();
    //    reverser.pop();
    //}
}
