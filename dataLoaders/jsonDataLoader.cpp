#include "jsonDataLoader.h"
ShrdPtr<Sequence<int>> jsonDataLoader::getIntegerDataFromJSON(std::string path)
{
	std::ifstream f(path);
	LinkedListSequence<int>* res = new LinkedListSequence<int>();
	json data = json::parse(f);
	for (auto& el : data.items()) {
		res->Append(int(el.value()));
	}
	return ShrdPtr<Sequence<int>>(res);
}

ShrdPtr<Sequence<float>> jsonDataLoader::getFloatDataFromJSON(std::string path)
{
	std::ifstream f(path);
	LinkedListSequence<float>* res = new LinkedListSequence<float>();
	json data = json::parse(f);
	for (auto& el : data.items()) {
		res->Append(float(el.value()));
	}
	return ShrdPtr<Sequence<float>>(res);
}

ShrdPtr<Sequence<Student>> jsonDataLoader::getStudentDataFromJSON(std::string path)
{
	std::ifstream f(path);
	LinkedListSequence<Student>* res = new LinkedListSequence<Student>();
	json data = json::parse(f);
	for (auto& el : data.items()) {
		res->Append(
			Student(
				std::string(el.value()["Name"]),
				std::string(el.value()["Surname"]),
				int(el.value()["Age"]),
				float(el.value()["Mean mark"]),
				int(el.value()["Group"])
			)
		);
	}
	return ShrdPtr<Sequence<Student>>(res);
}