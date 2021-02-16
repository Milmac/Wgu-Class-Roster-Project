#pragma once

#ifndef STUDENT_H_
#define STUDENT_H_
#include "degree.h"
#include <string>
using namespace std;


class student
{
public:

	//the default constructor
	student();
	student(string _studentID, string _firstName, string _lastName,
		string _emailAddress, int _age, int* _numDays, degree _degree);

	//gets the student info
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	//gets number of days in the course
	int* getNumDays();

	//sets the student info
	void setStudentID(string _studentID);
	void setFirstName(string _firstName);
	void setLastName(string _lastName);
	void setEmailAddress(string _emailAddress);
	void setAge(int _age);
	//sets number of days in the course
	void setNumDays(int _numDay1, int _numDay2, int _numDay3);
	void setDegree(degree _degree);

	//prints the student data
	virtual void print();
	virtual degree getDegree();

	~student();


private:

	//private variables for each student
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	//number of days in course
	int numDays[3];
	//student degree
	degree sDegree;
};
#endif