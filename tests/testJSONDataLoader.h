#pragma once
#include "../dataLoaders/jsonDataLoader.h"
#include <cassert>
void testJSONDataLoader()
{
	ShrdPtr<Sequence<int>> res = jsonDataLoader().getIntegerDataFromJSON("tests/testJSON.json");
	assert(res->Get(0) == 18);
	assert(res->Get(1) == 19);
	assert(res->Get(2) == 312);
	assert(res->Get(3) == 213);
	assert(res->Get(4) == 543);
	assert(res->Get(5) == 657);
	assert(res->GetLenght() == 14);
}