#pragma once
#include "../sequence/LinkedListSequence.h"
#include <functional>
#include <iostream>
template <class T>
class ISorter
{
public:
	virtual ShrdPtr<Sequence<T>> sort(ShrdPtr<Sequence<T>>, std::function<bool(T, T)>) = 0;
};

template <class T>
void printSeq(ShrdPtr<Sequence<T>> seq)
{
	for (int i = 0; i < seq->GetLenght(); i++)
	{
		std::cout << seq->Get(i) << " ";
	}
	std::cout << "\n";
}