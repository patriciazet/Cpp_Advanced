
#include <iostream>
#include <iomanip>

template<typename T>
void print(T s) //szablon funkcji print
{
    std::cout << s << std::endl;
}

template<>
void print(double s) //specjalizacja 1 dla typu double
{
    std::cout << std::setprecision(2) << s << std::endl;
}

template<>
void print(bool value) //specjalizacja 2 dla typu bool
{
    if (value)
    {
        std::cout << "Prawda" << std::endl;
    }
    else
    {
        std::cout << "Falsz" << std::endl;
    }

}

template<int N>
void printKu()
{
    for (int i =0; i<N;++i)
    std::cout << "Ku ";
}

struct D
{
private:
    int z;
};

template<typename T1, typename T2> //szablon z 2 argumentami
void print(T1 s, T2 p) //szablon funkcji print
{
    std::cout << s << ", " << p << std::endl;
}

template<typename T1, typename T2> //specjalizacja czeœciowa dla wskaŸików
void print(T1* s, T2* p) //szablon funkcji print
{
    std::cout << *s << ", " << *p << std::endl;
}

template<typename T1> //specjalizacja czêœciowa dla drugiego parametru
void print(T1 s, bool p) //szablon funkcji print
{
    std::cout << s << ", " << (p ? "true" : "false") << std::endl;
}

//PRACA DOMOWA: Szablon gdzie bool jest na 1 miejsu a na drugim dowolony argument

template<typename T1, typename T2, typename T3>
T1 fun(T1 a, T2 b, T3 c)
{
    //...
}

template<typename T1, typename T2>
int fun(T1 a, T2 b, bool c)
{
    //...
}

//template<class T1> //to samo co linijka nizej, ale nikt tak nie pisze
template<typename T1>
class A
{
    T1 fieldA;

    T1 funA();
};

template<typename T1>
class B : A<T1>
{
    T1 fieldB;

    void funB(T1 a, T1 b);
};

class C : A<int> //c nie jest szablonem
{

};

template<typename T1>
class D : A<float>
{
    T1 fieldD;
};

template<typename T1, typename T2>
class E : A<T2>
{
    T1 fieldE;
};

class F 
{
   int fieldF;

   template<typename T>
   void funF(T p);

};

int main()
{
    int i = 1;
    double d = 1232.21112;
    bool b = true;

    print(i);
    print(d);
    print(b);

    printKu<100>();

    std::cout << std::endl;

    print(3.21, true);
    print(false , 3.33);
    //D obj;
    //print(obj);

    A<int> objA1;
    A<bool> objA2;
    //objA2 = objA1; //to nie dzia³a
    A<std::string> objA3;
    E<double, bool> objE;
    D<F> objeD;

    B<std::string> objB;
}



