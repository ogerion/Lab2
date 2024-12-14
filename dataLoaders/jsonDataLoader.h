#pragma once
#include "../sequence/LinkedListSequence.h"
#include "../Student.h"
#include <nlohmann/json.hpp>
#include <string>
#include <fstream>
#include <iostream>
using json = nlohmann::json;

class jsonDataLoader
{
	public:
		ShrdPtr<Sequence<int>> getIntegerDataFromJSON(std::string path);
		ShrdPtr<Sequence<float>> getFloatDataFromJSON(std::string path);
		ShrdPtr<Sequence<Student>> getStudentDataFromJSON(std::string path);

		jsonDataLoader() = default;
};

