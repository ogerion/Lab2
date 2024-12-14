#pragma once
#include "ISorter.h"

template <class T>
class InsertionSort : public ISorter<T>
{
public:
	ShrdPtr<Sequence<T>> sort(ShrdPtr<Sequence<T>>, std::function<bool(T, T)>) override;
};

template <class T>
ShrdPtr<Sequence<T>> InsertionSort<T>::sort(ShrdPtr<Sequence<T>> seq, std::function<bool(T, T)> cmp)
{
    ShrdPtr<Sequence<T>> res = seq->GetSubSequence(0, seq->GetLenght());
    size_t n = seq->GetLenght();
    for (int i = 1; i < n; ++i) {
        T key = res->Get(i);
        int j = i - 1;

        while (j >= 0 && cmp(res->Get(j), key)) {
            res->Set(res->Get(j), j + 1);
            j = j - 1;
        }
        res->Set(key, j + 1);
    }
    return res;
}