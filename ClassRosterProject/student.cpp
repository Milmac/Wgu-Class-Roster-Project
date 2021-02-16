#include "student.h"
#include "degree.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

student::student()
{
	studentID = "";
	firstName = "";
	lastName = "";
	emailAddress = "";
	age = 0;

	//foreach numday in numday array, set it to 0
	for (int _nday : numDays)
	{
		_nday = 0;
	}
}

student::student(string _studentID, string _firstName, string _lastName,
	string _emailAddress, int _age, int* _numDays, degree _degree)
{
	studentID = _studentID;
	firstName = _firstName;
	lastName = _lastName;
	emailAddress = _emailAddress;
	age = _age;

	//for each number in numdays, store numdays
	int index = 0;
	for (int n : numDays)
	{
		numDays[index] = _numDays[index];
		index++;
	}
}

//Get Functions

#pragma region Get Student Data

string student::getStudentID()
{
	return studentID;
}
string student::getFirstName()
{
	return firstName;
}

string student::getLastName()
{
	return lastName;
}

string student::getEmailAddress()
{
	return emailAddress;
}

int student::getAge()
{
	return age;
}

int* student::getNumDays()
{
	return numDays;
}

degree student::getDegree()
{
	return degree::SOFTWARE;
}
#pragma endregion
	
#pragma region Set Student Data
void student::setStudentID(string _studentID)
{
	studentID = _studentID;
}

void student::setFirstName(string _firstName)
{
	firstName = _firstName;
}

void student::setLastName(string _lastName)
{
	lastName = _lastName;
}

void student::setEmailAddress(string _emailAddress)
{
	emailAddress = _emailAddress;
}

void student::setAge(int _age)
{
	age = _age;
}
void student::setNumDays(int _dayNum1, int _dayNum2, int _dayNum3)
{
	student::numDays[0] = _dayNum1;
	student::numDays[1] = _dayNum2;
	student::numDays[2] = _dayNum3;
}

void student::setDegree(degree _degree)
{
	sDegree = _degree;
}

#pragma endregion


void student::print()
{	

	
	//get the user's number of days	
	//prints the user details
	cout << "Student ID: " << getStudentID() << "\t";
	cout << "First Name: " << getFirstName() << "\t";
	cout << "Last Name: " << getLastName() << "\t";
	cout << "Email: " << getEmailAddress() << "\t";
	cout << "Age: " << getAge() << "\t";
	cout << "Days in Course: " << getNumDays()[0] << ", " << getNumDays()[1] << ", " << getNumDays()[2] << "\t";

	//get the degree
	degree _degree = getDegree();

	//if getDegree() returns a Network degree
	if (_degree == degree::NETWORK)
	{
		cout << "Degree: NETWORK" << "\t";
	}
	//if getDegree() returns a Security degree
	if (_degree == degree::SECURITY)
	{
		cout << "Degree: SECURITY" << "\t";
	}
	//if getDegree() returns a Software degree
	if (_degree == degree::SOFTWARE)
	{
		cout << "Degree: SOFTWARE" << "\t";
	}

	cout << endl;
}

student::~student()
{
	if (numDays != nullptr)
	{

		//delete numday
		delete[] numDays;
		//foreach number in numday, set to null
		for (int _nDay : numDays)
		{
			_nDay = NULL;
		}
	}
}
