#include <iostream>

void hello()
{
	std::cout << "Hello World!\n";
}

int add(int a, int b)
{
	return a + b;
}

int main()
{
	//a)
	hello();

	auto helloWorld = []() { std::cout << "Hello World!\n"; };
	helloWorld();

	[]() { std::cout << "Hello World2!\n"; }();

	//b)
	std::cout << "SUMA1: " << add(1, 2) << std::endl;
	auto addTwoNumbers = [](int a, int b) {return a + b; };
	std::cout << "SUMA1: " << addTwoNumbers(3, 4) << std::endl;

	//ERRATA: WSKAZNIKI NA FUNKCJE
	auto helloFunc = hello; //wskaznik na funkcje hello przy uzyciu auto
	helloFunc();
	void (*PtrName)() = hello; //archaizm
	PtrName(); //wywolanie funkcji
	int (*addPtrFunc)(int, int) = add;
	std::cout << "SUMA1: " << addPtrFunc(5, 6) << std::endl;

	return 0;
}
