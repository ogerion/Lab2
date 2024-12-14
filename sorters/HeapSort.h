#pragma once
#include "ISorter.h"

template <class T>
class HeapSort : public ISorter<T>
{
public:
	ShrdPtr<Sequence<T>> sort(ShrdPtr<Sequence<T>>, std::function<bool(T, T)>) override;
private:
	void heapify(ShrdPtr<Sequence<T>>, size_t n, size_t i, std::function<bool(T, T)>);
};

template <class T>
ShrdPtr<Sequence<T>> HeapSort<T>::sort(ShrdPtr<Sequence<T>> seq, std::function<bool(T, T)> cmp)
{
	ShrdPtr<Sequence<T>> res = seq->GetSubSequence(0, seq->GetLenght());
	size_t n = seq->GetLenght() + 1;
	for (size_t i = n / 2 - 1; i > 0; i--)
	{
		this->heapify(std::move(res), n, i, cmp);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		res->Swap(0, i);
		heapify(std::move(res), i, 0, cmp);
	}
	return res;
}

template <class T>
void HeapSort<T>::heapify(ShrdPtr<Sequence<T>> seq, size_t n, size_t i, std::function<bool(T, T)> cmp)
{
	int largest = i;

	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && cmp(seq->Get(l), seq->Get(largest)))
		largest = l;

	if (r < n && cmp(seq->Get(r), seq->Get(largest)))
		largest = r;

	if (largest != i)
	{
		seq->Swap(i, largest);

		heapify(std::move(seq), n, largest, cmp);
	}
}