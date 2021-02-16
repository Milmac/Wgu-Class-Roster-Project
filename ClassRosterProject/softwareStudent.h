#pragma once

#include <string>
#include "student.h"

using namespace std;

class softwareStudent : public student
{
public:

	//constructor for software student
	softwareStudent();

	void print();

	degree getDegree() override;

	softwareStudent(string _studentID, string _firstName, string _lastName,
		string _emailAddress, int _age, int* _numDays, degree _degree);

	//software deconstructor
	~softwareStudent();
};

