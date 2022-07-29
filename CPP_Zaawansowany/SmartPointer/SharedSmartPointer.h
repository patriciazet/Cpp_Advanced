#pragma once
#include "RefCounter.h"

template<typename T>
class SharedSmartPointer
{
public:
	SharedSmartPointer()
		: _data(nullptr), reference(0)
	{
		reference = new RefCounter();

		reference->AddRef(); //zwiekszamy licznik o 1 bo juz istniejmy 
	}

	SharedSmartPointer(T* data)
		: _data(data)
	{
		reference = new RefCounter();

		reference->AddRef(); //zwiekszamy licznik o 1 bo juz istniejmy 
	}

	SharedSmartPointer(const SharedSmartPointer<T>& second)
		:_data(second._data), reference(second.reference) //kopiujemy reference, wiec wspoldzielimy wskaznik na licznik
	{
		reference->AddRef(); 
	}

	~SharedSmartPointer()
	{
		if (reference->Release() == 0) //jeœli wartoœæ licznika po release jest 0 - oznacza ze jestesmy ostatni i sprzatamy
		{
			delete _data;
			delete reference;
		}
	}

	SharedSmartPointer<T>& operator= (const SharedSmartPointer<T>& sp)
	{
		if (this != &sp) //unikamy kopiowania samemu siebie
		{
			if (reference->Release() == 0)
			{
				delete _data;
				delete reference;
			}
			//mamy czysyt this

			//kopiujemy tak jak to robilismy w c-tro kopiujacym
			_data = sp._data;
			reference = sp.reference;
			reference->AddRef();
		}

		return *this;
	}

	T& operator*()
	{
		return *_data;
	}

	T* operator->()
	{
		return _data;
	}

private:
	T* _data;
	RefCounter* reference;
};
