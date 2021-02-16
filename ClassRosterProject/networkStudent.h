#pragma once

#include <string>
#include "student.h"

using namespace std;

class networkStudent : public student
{
public:

	//constructor for network student
	networkStudent();

	void print();

	degree getDegree() override;

	networkStudent(string _studentID, string _firstName, string _lastName,
		string _emailAddress, int _age, int* _numDays, degree _degree);

	//network deconstructor
	~networkStudent();
};

