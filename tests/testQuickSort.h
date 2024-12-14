#pragma once

#include "sorters/QuickSort.h"
#include "sorters/Compare.h"
#include <cassert>
void testQuickSort()
{
	ShrdPtr<Sequence<int>> res(new LinkedListSequence<int>());
	for (int i = 7; i > 0; i--)
	{
		res->Append(i);
	}
	res = QuickSort<int>().sort(std::move(res),compareIntegersAscending);
	assert(res->Get(0) == 1);
	assert(res->Get(1) == 2);
	assert(res->Get(2) == 3);
	assert(res->Get(3) == 4);
	assert(res->Get(4) == 5);
	assert(res->Get(5) == 6);
	assert(res->Get(6) == 7);
	assert(res->GetLenght() == 7);
}