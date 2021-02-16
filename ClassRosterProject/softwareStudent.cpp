#include "softwareStudent.h"
#include <iostream>
#include <string>

using namespace std;

//softwre student constructor
softwareStudent::softwareStudent()
{
	getDegree();
}

softwareStudent::softwareStudent(string _studentID, string _firstName, string _lastName,
	string _emailAddress, int _age, int* _numDays, degree _degree)
	:student(_studentID, _firstName, _lastName, _emailAddress, _age, _numDays, _degree)
{
	_degree = getDegree();
}

void softwareStudent::print()
{
	student::print();
}


degree softwareStudent::getDegree()
{
	return degree::SOFTWARE;
}

softwareStudent::~softwareStudent()
{
	student::~student();
	delete this;
}

