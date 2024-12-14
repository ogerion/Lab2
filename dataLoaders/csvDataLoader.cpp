#include "dataLoaders/csvDataLoader.h"
//#include "../LinkedListSequence.h"
//#include "../ShrdPtr.h"
//#include "../Student.h"
//#include "../Sequence.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

ShrdPtr<Sequence<int>> csvDataLoader::getIntegerDataFromCSV(std::string path)
{
	std::ifstream f(path);
	std::string line;
	LinkedListSequence<int>* res = new LinkedListSequence<int>();
	while (std::getline(f, line))
	{
		std::string Name;
		std::string Surname;
		int num;

		std::stringstream ss(line);

		ss >> num;

		res->Append(num);
	}
	return ShrdPtr<Sequence<int>>(res);
}

ShrdPtr<Sequence<float>> csvDataLoader::getFloatDataFromCSV(std::string path)
{
	std::ifstream f(path);
	std::string line;
	LinkedListSequence<float>* res = new LinkedListSequence<float>();
	while (std::getline(f, line))
	{
		std::string Name;
		std::string Surname;
		float num;

		std::stringstream ss(line);

		ss >> num;

		res->Append(num);
	}
	return ShrdPtr<Sequence<float>>(res);
}

ShrdPtr<Sequence<Student>> csvDataLoader::getStudentDataFromCSV(std::string path)
{
	std::ifstream f(path);
	std::string line;
	LinkedListSequence<Student>* res = new LinkedListSequence<Student>();
	while (std::getline(f, line))
	{
		std::string Name;
		std::string Surname;
		int Age;
		float MeanMark;
		int Group;

		std::stringstream ss(line);
		std::string item;

		ss >> Name;
		ss >> Surname;

		ss >> Age;

		ss >> MeanMark;

		ss >> Group;


		res->Append(Student(Name, Surname, Age, MeanMark, Group));
	}
	return ShrdPtr<Sequence<Student>>(res);
}