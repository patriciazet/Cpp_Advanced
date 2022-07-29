#include <iostream>
#include <memory>
#include <vector>

class Chicken
{
public:

    Chicken()
    {
        std::cout << "Chicken" << std::endl;
    }

    Chicken(const Chicken& second)
    {
        std::cout << "Chicken copy" << std::endl;
    }

    ~Chicken()
    {
        std::cout << "~Chicken" << std::endl;
    }
};

void fun()
{
    Chicken* rawPtr = new Chicken();

    std::unique_ptr<Chicken> smartPtr(new Chicken());

    delete rawPtr;
}

void funA(std::shared_ptr <Chicken> sharedPtr)
{

}

void copyChicken(int howMany, std::shared_ptr <Chicken> sharedPtr)
{
    std::vector<std::shared_ptr<Chicken>> chickens;
    std::cout << "copy Chicken count " << sharedPtr.use_count() << std::endl;
    for (int i = 0; i < howMany; ++i)
    {
        chickens.push_back(sharedPtr);
        std::cout << "Chicken count " << sharedPtr.use_count() << std::endl;
    }
}

int main()
{
    //fun();

    std::shared_ptr <Chicken> sharedPtr = std::make_shared<Chicken>(); //1 blok pamięci(szybciej), zapewnia exception safety
    //std::shared_ptr <Chicken> sharedPtr(new Chicken());
    
    std::cout << "B Chicken count " << sharedPtr.use_count() << std::endl;
    copyChicken(10, sharedPtr);
    std::cout << "E Chicken count " << sharedPtr.use_count() << std::endl;
    //funA(new Chicken()); //(┬┬﹏┬┬) gdzie delete!??!?!?!?

    //funA(std::make_shared<Chicken>()); //╰(*°▽°*)╯
    
    std::cout << "Hello World!\n";



}

