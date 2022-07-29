#pragma once

template<typename T>
class SimpleSmartPointer
{
public:
	SimpleSmartPointer(T* data)
		: _data(data)
	{
		//_data = data;
	}

	~SimpleSmartPointer()
	{
		delete _data;
		_data = nullptr; //tutaj nie potrzeba bo po delete juz obiekt naszej klasy nie istnieje i nie ma mozliwosci odwolac sie do taj pamieci niechcacy
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
};

