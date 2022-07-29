#include <iostream>

class Product
{
public:
    Product()
        : _price(0), _name("")
    {

    }

    Product(float price, std::string name)
        : _price(price), _name(name)
    {

    }

private:
    float _price; 
    std::string _name;
};

int main()
{
    std::unique_ptr<Product> ptr1 = std::make_unique<Product>(); //wywo�a si� konstruktor domyslny
    std::unique_ptr<Product> ptr2 = std::make_unique<Product>(7.99, "Mas�o :("); //wywo�a si� konstruktor parametrowy

    std::cout << "Hello World!\n";
}

