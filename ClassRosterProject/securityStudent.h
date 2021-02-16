#pragma once

#include <string>
#include "student.h"

using namespace std;
class securityStudent : public student
{
public:
	//constructor for security student
	securityStudent();

	void print();

	degree getDegree() override;

	securityStudent(string _studentID, string _firstName, string _lastName,
		string _emailAddress, int _age, int* _numDays, degree _degree);

	//security deconstructor
	~securityStudent();
};

