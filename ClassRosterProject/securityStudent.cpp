#include "securityStudent.h"
#include <iostream>
#include <string>

using namespace std;

//softwre student constructor
securityStudent::securityStudent()
{
	getDegree();
}

securityStudent::securityStudent(string _studentID, string _firstName, string _lastName,
	string _emailAddress, int _age, int *_numDays, degree _degree)
	:student(_studentID, _firstName, _lastName,_emailAddress, _age, _numDays, _degree)
{
	_degree = getDegree();
}

void securityStudent::print()
{
	student::print();
}


degree securityStudent::getDegree()
{
	return degree::SECURITY;
}

securityStudent::~securityStudent()
{
	student::~student();
	delete this;
}

