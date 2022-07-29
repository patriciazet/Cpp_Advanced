#include <iostream>

#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList()
	: _head(nullptr)
	, _tail(nullptr)
{

}

DoublyLinkedList::~DoublyLinkedList()
{
	clear();
}

void DoublyLinkedList::clear()
{
	Node* tmp = nullptr;

	while (_head != nullptr)
	{
		tmp = _head->next;
		delete _head;
		_head = tmp;
	}

	_tail = nullptr;
}

void DoublyLinkedList::insertFront(int value)
{
	//utworzenie nowego wêz³a, ustawiamy prev na nullptr, poniewa¿ pierwszy element listy nie ma poprzednika
	Node* newNode = new Node();
	newNode->data = value;
	newNode->prev = nullptr;

	if (_head != nullptr) //jezeli lista nie jest pusta to ustaw wskaznik prev akutalnie pierwszego elementu na nasz nowy element
	{
		_head->prev = newNode;
	}
	//kopiujemy wskaznik na pierwszy element (ten ktory wskazuje _head), robimy to najpierw zeby nie stracic uchywtu do listy
	newNode->next = _head;

	//ustawiamy wskaznik poczatku listy na nasz nowo utworzony weze³
	_head = newNode;
}

void DoublyLinkedList::print() const
{
	Node* tmp = _head;

	while (tmp != nullptr) //przechodzenie listy - odwiedzanie wszytkich wez³ów (ang. traverse)
	{
		std::cout << tmp->data << "<->";
		tmp = tmp->next;
	}

	std::cout << "nullptr";
}

unsigned int DoublyLinkedList::size() const //dla przykladu policzymy elementy od konca
{
	Node* tmp = _tail;
	unsigned int size = 0;

	while (tmp != nullptr) //przechodzenie listy - odwiedzanie wszytkich wez³ów (ang. traverse)
	{
		++size;
		tmp = tmp->prev;
	}

	return size;
}

void DoublyLinkedList::insertAfter(int value, const unsigned int index)
{
	Node* tmp = _head;
	unsigned int currentIndex = 0;

	while (tmp != nullptr && currentIndex != index) //przechodzenie listy - odwiedzanie wszytkich wez³ów (ang. traverse)
	{
		++currentIndex;
		tmp = tmp->next;
	}

	if (tmp != nullptr && tmp->next != nullptr) //sprawdzenie czy mamy przynajmniej dwa elementy w liscie, aby wstawiæ nasz nowy element pomiêdzy te istniej¹ce
	{
		Node* newNode = new Node();
		newNode->data = value;

		//Node* nodeAfterNewOne = tmp->next; //element który znajduje siê na naszym nowo wstawionym elementem
		//nodeAfterNewOne->next = newNode;
		
		tmp->next->prev = newNode; //ustawienie na nasz nowy element pola prev z nastêpnego elementu
		
		//Tak sie nie robi, ale zostawiam jako pokaz co robi operator ->
		//tmp->next->prev = newNode;
		//(*(*tmp).next).prev = newNode;
		//Node* next = (*tmp).next;
		//next->prev = newNode;

		newNode->next = tmp->next; //nowy element wskazuje na element nastêpny
		tmp->next = newNode; //element za ktorym wstawiamy ma wskazywac na nowy element
		newNode->prev = tmp; //nowy element wskazuje na ten za ktorym sie wstawiamy
	}

}

int& DoublyLinkedList::operator[](const unsigned int index) const
{
	Node* tmp = _head;
	unsigned int currentIndex = 0;

	while (tmp != nullptr && currentIndex != index) //przechodzenie listy - odwiedzanie wszytkich wez³ów (ang. traverse)
	{
		++currentIndex;
		tmp = tmp->next;
	}

	if (tmp == nullptr)
	{
		//todo wyjatek
	}

	return tmp->data;
}

void DoublyLinkedList::remove(const unsigned int index)
{
	Node* tmp = _head;
	unsigned int currentIndex = 0;

	while (tmp != nullptr && currentIndex != index) //przechodzenie listy - odwiedzanie wszytkich wez³ów (ang. traverse)
	{
		++currentIndex;
		tmp = tmp->next;
	}

	if (tmp->prev == nullptr && tmp->next !=nullptr) //usuwamy pierwszy element
	{
		_head = tmp->next;
		tmp->next->prev = nullptr;
		delete tmp;
	}
	else if (tmp->next == nullptr && tmp->prev != nullptr) //usuwamy ostatni element
	{
		_tail = tmp->prev;
		tmp->prev->next = nullptr;
		delete tmp;
	}
	else if (tmp->next != nullptr && tmp->prev != nullptr) //usuwamy jedyny element w liscie
	{
		//TUTAJ JEST BLAD GDZIES
		_head = nullptr;
		_tail = nullptr;
		delete tmp;
	}
	else //usuwamy element w srodku 
	{
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		delete tmp;
	}

}