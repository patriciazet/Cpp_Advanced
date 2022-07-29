//Zad 6.
//Napisz prosty s³ownik który przet³umaczy s³owo z jêzyka anielskiego na polski(kilka testowych s³ów).
#include <iostream>
#include <map>

void translate(const std::map<std::string, std::string>& dictionary, const std::string& english)
{
    std::string polish{};
    try
    {
        polish = dictionary.at(english);
    }
    catch(const std::out_of_range& ex)
    {
        polish = "ERROR: not found";
    }

    std::cout << english << " means: " << polish << std::endl;
}

int main()
{
    std::map<std::string, std::string> dictionary;
    dictionary.insert(std::pair<std::string, std::string>("castle", "zamek"));
    dictionary.insert({ "zip", "zamek" });
    dictionary.insert({ "zip", "archiwum" });
    dictionary.insert({ "lock", "zamek" });
    dictionary.insert({ "dog", "pies" });
    dictionary.insert({ "cat", "kot" });
    dictionary.insert({ { "apple", "jablko" }, { "pear", "gruszka" }, { "red", "czerwony" } });

    std::cout << dictionary.at("dog") <<std::endl;
    std::cout << dictionary["cat"] << std::endl;

    //std::cout << dictionary.at("bat") << std::endl;
    //std::cout << dictionary["bat"] << std::endl;
    translate(dictionary, "zip");
    translate(dictionary, "apple");
    translate(dictionary, "bat");
}
