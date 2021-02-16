
#ifndef ROSTER_H
#define ROSTER_H
#include <string>
#include "degree.h"
#include "student.h"

using namespace std;
#pragma once
class roster
{
public:

	//initial string data
	const string studentData[5] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Milan,Macura,mmacur1@my.wgu.edu,19,45,53,42,SOFTWARE",
	};

	//constructor
	roster();

	//add roster
	void add(string _studentID, string _firstName, string _lastName, string _emailAddress,
		int _age, int _numday1, int _numday2, int _numday3, degree _degree);
	//remove roster
	void remove(string _studentID);
	//loop through and print every roster info
	void printAll();
	//print the days in course
	void printAverageDaysInCourse(string _studentID);
	//print all invalid 
	void printInvalidEmails();
	void printByDegreeProgram(degree _degree);
	//prints my school info and other things
	void printMyInfo();

	//destructor
	~roster();

private :

	student *classrosterArray[5];
	int rosterIndex = 0;
};

#endif