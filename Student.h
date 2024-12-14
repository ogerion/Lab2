#pragma once

#include <string>

class Student
{
	public:
		Student(std::string Name, std::string Surname, int age, float meanMark, int group)
		{
			this->Name = Name;
			this->Surname = Surname;
			this->age = age;
			this->meanMark = meanMark;
			this->group = group;
		}
		Student() {}
		std::string Name;
		std::string Surname;
		int age;
		float meanMark;
		int group;

};

//std::ostream& operator << (std::ostream& os, const Student& person)
//{
//	return os << "Student[Name: " << person.Name << " Surname : " << person.Surname <<" Age: "<<person.age<<" Mean mark: "<<person.meanMark <<" Group: "<<person.group<<"]";
//}