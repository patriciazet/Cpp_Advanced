#pragma once

template<typename T, unsigned int N>
class StaticTable
{
public:
	T& operator[](const unsigned int i) 
	{
		//TODO: wyj�tek out_of_range, gdy i >= N; https://en.cppreference.com/w/cpp/error/out_of_range
		return tab[i];
	}

	template<typename T2>
	void print(T2 separator)
	{
		//wypisuje ca�a tablice u�ywaja� zmiennej T2 separator jako znaku rozdzielaj�cego warto�ci
	}

private:
	T tab[N];
};

//specjalizacja szablonu klasy
template<unsigned int N>
class StaticTable<bool, N>
{
public:
	bool& operator[](const unsigned int i)
	{
		//TODO: wyj�tek out_of_range, gdy i >= N; https://en.cppreference.com/w/cpp/error/out_of_range
		return tab[i];
	}

private:
	bool tab[N];
};


//template<typename T, unsigned int N>
//T& StaticTable::operator[](const unsigned int i)
//{
//	//TODO: wyj�tek out_of_range, gdy i >= N; https://en.cppreference.com/w/cpp/error/out_of_range
//	return tab[i]; 
//}

