#pragma once
#include "../Student.h"
#include "../sequence/LinkedListSequence.h"
#include <string>
class csvDataLoader
{
public:
	ShrdPtr<Sequence<int>> getIntegerDataFromCSV(std::string path);
	ShrdPtr<Sequence<float>> getFloatDataFromCSV(std::string path);
	ShrdPtr<Sequence<Student>> getStudentDataFromCSV(std::string path);

	csvDataLoader() = default;
};

