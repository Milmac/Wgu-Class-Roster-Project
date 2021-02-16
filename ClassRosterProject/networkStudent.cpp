#include "networkStudent.h"
#include <iostream>
#include <string>

using namespace std;

//softwre student constructor
networkStudent::networkStudent()
{
	getDegree();
}

networkStudent::networkStudent(string _studentID, string _firstName, string _lastName,
	string _emailAddress, int _age, int* _numDays, degree _degree)
	:student(_studentID, _firstName, _lastName, _emailAddress, _age, _numDays, _degree)
{
	_degree = getDegree();
}

void networkStudent::print()
{
	student::print();
}


degree networkStudent::getDegree()
{
	return degree::NETWORK;
}

networkStudent::~networkStudent()
{
	student::~student();
	delete this;
}

