#pragma once
#include <iostream>
using namespace std;
#pragma warning(disable: 4996)
template < class InfoType = int>
class Dequeue
{
private:
	struct QItem {
		InfoType info;
		QItem* next;
		QItem* prev;
		QItem(InfoType Ainfo) : info(Ainfo), next(nullptr), prev(nullptr) {}
	};
	QItem* front{ nullptr };
	QItem* rear{ nullptr };
	unsigned size{0};
	void clone(const Dequeue&q);
	void erase();

public:
	Dequeue() = default;
	Dequeue(const Dequeue&);
	void pushBack(InfoType a);
	void pushFront(InfoType a);
	~Dequeue();
	bool popBack();
	bool popFront();
	unsigned getSize() const;
	Dequeue& operator = (const Dequeue& q);
	void outFromBegin(ostream & os);
	void outFromEnd(ostream & os);
};

template<class  InfoType>
void Dequeue<InfoType>::pushBack(InfoType a)
{
	QItem* tmp = new QItem(a);
	if (size > 0) {
		rear->next = tmp;
		tmp->prev = rear;
	}
	else {
		front = tmp;
	}
	rear = tmp;
	size++;
}

template<class  InfoType>
void Dequeue<InfoType>::pushFront(InfoType a)
{
	QItem* tmp = new QItem(a);
	if (size > 0) {
		tmp->next = front;
		front->prev = tmp;
	}else {
		rear = tmp;
	}
	front = tmp;
	size++;

}

template<class InfoType>
Dequeue<InfoType>::~Dequeue()
{
	erase();
}

template<class  InfoType>
bool Dequeue<InfoType>::popBack()
{
	if (size == 0) {
		return false;
	}
	QItem *tmp = rear;
	rear = rear->prev;
	delete tmp;
	size--;
	if (size == 0) {
		rear = nullptr;
	}
	return true;
}

template<class  InfoType>
bool Dequeue<InfoType>::popFront()
{
	if (size == 0) {
		return false;
	}
	QItem *tmp = front;
	front = front->next;
	delete tmp;
	size--;
	if (size == 0) {
		rear = nullptr;
	}
	return true;
}

template<class  InfoType>
unsigned Dequeue<InfoType>::getSize() const
{
	return size;
}

template<class  InfoType>
Dequeue<InfoType>& Dequeue<InfoType>::operator=(const Dequeue<InfoType>& q)
{
	if (this != &q) {
		erase();
		clone(q);
	}
	return *this;
}

template<class  InfoType>
void Dequeue<InfoType>::outFromBegin(ostream& os)
{
	QItem *tmp = front;
	for (unsigned i = 0; i < size; i++) {
		os << (*tmp).info << ' ';
		tmp = tmp->next;
	}
	os << endl;
}

template<class  InfoType>
void Dequeue<InfoType>::outFromEnd(ostream & os)
{
	QItem *tmp = rear;
	for (unsigned i = 0; i < size; i++) {
		os << (*tmp).info << ' ';
		tmp = tmp->prev;
	}
	os << endl;
}

template<class  InfoType>
inline void Dequeue<InfoType>::clone(const Dequeue<InfoType> &q)
{
	QItem *tmp = q.front;
	for (int i = 0; i < q.size; i++) {
		pushBack(tmp->info);
		tmp = tmp->next;
	}
}

template<class  InfoType>
void Dequeue<InfoType>::erase()
{
	while (popBack());
	size = 0;
}

template<class  InfoType>
Dequeue<InfoType>::Dequeue(const Dequeue<InfoType> & q)
{
	clone(q);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <>
Dequeue < const char *>::QItem::QItem(const char * AInfo) :next(NULL), prev(NULL) {
	info = new char[strlen(AInfo) + 1];
	strcpy((char*)info, AInfo);
}

template <>
bool Dequeue<const char *>::popBack()
{
	if (size == 0) {
		return false;
	}
	QItem *tmp = rear;
	rear = rear->prev;
	delete[] tmp->info;
	delete tmp;
	--size;
	if (size == 0) {
		rear = nullptr;
		front = nullptr;
	}
	return true;
}

template<>
bool Dequeue<const char *>::popFront()
{
	if (size == 0) {
		return false;
	}
	QItem *tmp = front;
	front = front->next;
	delete[] tmp->info;
	delete tmp;
	size--;
	if (size == 0) {
		rear = nullptr;
		front = nullptr;
	}
	return true;
}
