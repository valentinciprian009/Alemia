#pragma once
#pragma warning(push)
#pragma warning(disable : 4250)

#include "iRectangle.h"
#include "myRectangle.h"
#include "BattleEntity.h"
#include "Plant.h"

template<class T>
class ContainerRectangle
	: public myRectangle
{
protected:
	T interEntity;

public:
	ContainerRectangle(int x, int y, T inter);
	ContainerRectangle(int x, int y);


	void addEntity(T toAdd);
	T getInterEntity() const;

	virtual void print() const override;
	virtual ~ContainerRectangle();
};

#pragma region Implems
template<class T>
void ContainerRectangle<T>::addEntity(T toAdd)
{
	this->interEntity = toAdd;
}


template<class T>
T ContainerRectangle<T>::getInterEntity() const
{
	return interEntity;
}


template<class T>
void ContainerRectangle<T>::print() const
{
	myRectangle::print();

	if (interEntity != nullptr)
	{
		std::cout << *interEntity;
	}
}

template<class T>
ContainerRectangle<T>::ContainerRectangle(int x, int y, T inter) : myRectangle(x, y), interEntity(inter), Entity(x, y) {}


template<class T>
ContainerRectangle<T>::ContainerRectangle(int x, int y) : myRectangle(x, y), interEntity(nullptr), Entity(x, y) {}

template<class T>
ContainerRectangle<T>::~ContainerRectangle()
{
	delete this->interEntity;
}

#pragma endregion

#pragma warning(pop)