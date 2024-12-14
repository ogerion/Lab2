#pragma once
#include "dataLoaders/csvDataLoader.h"
#include <cassert>
void testCSVDataLoader()
{
	ShrdPtr<Sequence<int>> res = csvDataLoader().getIntegerDataFromCSV("tests/testCSV.csv");
	assert(res->Get(0) == 7);
	assert(res->Get(1) == 6);
	assert(res->Get(2) == 5);
	assert(res->Get(3) == 4);
	assert(res->Get(4) == 3);
	assert(res->Get(5) == 2);
	assert(res->Get(6) == 1);
	assert(res->GetLenght() == 7);
}