#pragma once
#include "ISorter.h"
#include <QtWidgets/QPlainTextEdit>

template <class T>
class QuickSort : public ISorter<T>
{
public:
	ShrdPtr<Sequence<T>> sort(ShrdPtr<Sequence<T>>, std::function<bool(T, T)>) override;
	ShrdPtr<Sequence<T>> sortAnimated(ShrdPtr<Sequence<T>>,
		std::function<bool(T, T)>,
		QPlainTextEdit** labels,
		std::function<void(ShrdPtr<Sequence<T>>,QPlainTextEdit **, int, int)>);
private:
	int partition(ShrdPtr<Sequence<T>>, int, int, std::function<bool(T, T)>);

	void quickSort(ShrdPtr<Sequence<T>>, int, int, std::function<bool(T, T)>);

	int partitionAnimated(ShrdPtr<Sequence<T>>,
		int,
		int,
		std::function<bool(T, T)>,
		QPlainTextEdit** labels,
		std::function<void(ShrdPtr<Sequence<T>>, QPlainTextEdit**, int, int)>);

	void quickSortAnimated(ShrdPtr<Sequence<T>>,
		int,
		int,
		std::function<bool(T, T)>,
		QPlainTextEdit** labels,
		std::function<void(ShrdPtr<Sequence<T>>, QPlainTextEdit**, int, int)>);
};

template <class T>
ShrdPtr<Sequence<T>> QuickSort<T>::sort(ShrdPtr<Sequence<T>> seq, std::function<bool(T, T)> cmp)
{
	ShrdPtr<Sequence<T>> res = seq->GetSubSequence(0, seq->GetLenght());
	this->quickSort(std::move(res), 0, seq->GetLenght() - 1, cmp);
	return res;
}

template <class T>
ShrdPtr<Sequence<T>> QuickSort<T>::sortAnimated(ShrdPtr<Sequence<T>> seq,
	std::function<bool(T, T)> cmp,
	QPlainTextEdit** labels,
	std::function<void(ShrdPtr<Sequence<T>>, QPlainTextEdit**, int, int)> render)
{
	ShrdPtr<Sequence<T>> res = seq->GetSubSequence(0, seq->GetLenght());
	this->quickSortAnimated(std::move(res), 0, seq->GetLenght() - 1, cmp, labels, render);
	return res;
}

template <class T>
void QuickSort<T>::quickSort(ShrdPtr<Sequence<T>> seq, int low, int high, std::function<bool(T, T)> cmp)
{

	int n = seq->GetLenght();

	if (low < high) {

		int pi = partition(std::move(seq), low, high, cmp);

		quickSort(std::move(seq), low, pi - 1, cmp);
		quickSort(std::move(seq), pi + 1, high, cmp);
	}
}

template <class T>
void QuickSort<T>::quickSortAnimated(ShrdPtr<Sequence<T>> seq,
	int low,
	int high,
	std::function<bool(T, T)> cmp, QPlainTextEdit** labels,
	std::function<void(ShrdPtr<Sequence<T>>, QPlainTextEdit**, int, int)> render)
{

	int n = seq->GetLenght();

	if (low < high) {

		int pi = partitionAnimated(std::move(seq), low, high, cmp, labels, render);

		quickSortAnimated(std::move(seq), low, pi - 1, cmp, labels, render);
		quickSortAnimated(std::move(seq), pi + 1, high, cmp, labels, render);
	}
}

template <class T>
int QuickSort<T>::partition(ShrdPtr<Sequence<T>> seq,
	int low,
	int high,
	std::function<bool(T, T)> cmp) {

	T pivot = seq->Get(high);

	int i = low - 1;

	for (int j = low; j <= high - 1; j++) {
		if (cmp(pivot, seq->Get(j))) {
			i++;
			seq->Swap(i, j);
		}
	}

	seq->Swap(i + 1, high);
	return i + 1;
}

template <class T>
int QuickSort<T>::partitionAnimated(ShrdPtr<Sequence<T>> seq,
	int low,
	int high,
	std::function<bool(T, T)> cmp,
	QPlainTextEdit** labels,
	std::function<void(ShrdPtr<Sequence<T>>, QPlainTextEdit**, int, int)> render) {

	T pivot = seq->Get(high);

	int i = low - 1;

	for (int j = low; j <= high - 1; j++) {
		if (cmp(pivot, seq->Get(j))) {
			i++;
			seq->Swap(i, j);
			render(std::move(seq), labels, i, j);
		}
	}

	seq->Swap(i + 1, high);
	render(std::move(seq), labels, i + 1, high);
	return i + 1;
}