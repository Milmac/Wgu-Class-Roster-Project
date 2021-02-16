#include "roster.h"
#include <string>
#include <iostream>
#include "student.h"
#include <array>
#include <vector>
#include <sstream>
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"


using namespace std;

roster::roster()
{

}

//add roster
void roster::add(string _studentID, string _firstName, string _lastName, string _emailAddress,
	int _age, int _numday1, int _numday2, int _numday3, degree _degree)
{
	//store the numdays in an array
	int numDays[] = { _numday1, _numday2, _numday3 };
	
	//add a networking student to the roster
	if (_degree == degree::NETWORK) 
	{
		classrosterArray[rosterIndex++] = new networkStudent(_studentID, _firstName, _lastName,
			_emailAddress, _age, numDays, _degree);
	}
	//add a security student to the roster
	if (_degree == degree::SECURITY) 
	{
		classrosterArray[rosterIndex++] = new securityStudent(_studentID, _firstName, _lastName,
			_emailAddress, _age, numDays, _degree);
	}
	//add a software student to the roster
	if (_degree == degree::SOFTWARE) 
	{
		classrosterArray[rosterIndex++] = new softwareStudent(_studentID, _firstName, _lastName,
			_emailAddress, _age, numDays, _degree);
	}

}
//remove roster
void roster::remove(string _studentID)
{
	cout << "Attempting to remove student: " << _studentID << endl;
	bool userIsFound = false;
	// for each student in classarray
	for (int i = 0; i < 5; i++) {
		//if the student info is not empty and it matches the string parameter
		if (classrosterArray[i] != NULL && _studentID == classrosterArray[i]->getStudentID())
		{
			classrosterArray[i] = nullptr;
			userIsFound = true;
			cout << "Student: " << _studentID << " has been successfully removed" << endl;
		}
	}

	if (userIsFound == false)
	{
		cout << "404: Student with ID: " << _studentID << " Not Found" << endl;
	}

	cout << endl;
}

//loop through and print every roster info
void roster::printAll()
{
	//for each student in classarray
	for (student *_student : classrosterArray)
	{
		_student->print();
	}

	cout << '\n';
}

//print the days in course
void roster::printAverageDaysInCourse(string _studentID)
{
	cout << "Showing Average Days In Course for student: " << _studentID << endl;

	for (student* _student : classrosterArray)
	{
		// if the student id matches
		if (_student->getStudentID() == _studentID)
		{
			int avg = 0;
			avg = (_student->getNumDays()[0] + _student->getNumDays()[1] + _student->getNumDays()[2]) / 3;

			cout << "Student with ID: " << _studentID << " has a course average of: " << avg << " day(s)." << endl;
		}
	}

	cout << endl;
}

//print all invalid emails
void roster::printInvalidEmails()
{

	cout << "Showing invalid emails:" << endl;

	for (student* _student : classrosterArray)
	{
		//if the email does not contain a @, does not contain a period, or contains a space
		if (!(_student->getEmailAddress().find("@") != string::npos) ||
			!(_student->getEmailAddress().find(".") != string::npos) || 
			_student->getEmailAddress().find(" ") != string::npos)
		{
			//print the invalid emails
			cout << _student->getEmailAddress() << endl;
		}
		
	}

	cout << endl;
	
}

void roster::printByDegreeProgram(degree _degree)
{
	string degreeResult;

	if (_degree == degree::NETWORK)
	{
		degreeResult = "NETWORK";
	}
	if (_degree == degree::SECURITY)
	{
		degreeResult = "SECURITY";
	}
	if (_degree == degree::SOFTWARE)
	{
		degreeResult = "SOFTWARE";
	}

	cout << "Showing students with the degree: " <<  degreeResult << endl;
	for (student* _student : classrosterArray)
	{
		// if the student id matches
		if (_student->getDegree() == _degree)
		{
			_student->print();
		}
	}

	cout << endl;
}

//print my student info, language used, etc
void roster::printMyInfo()
{
	cout << "Application: Microsoft Visual Studio 2019" << endl;
	cout << "Course: Scripting and Programming - Applications - C867" << endl;
	cout << "Language Used: C++" << endl;
	cout << "Student ID: #000989289" << endl;
	cout << "Name: Milan Macura" << endl;
	cout << endl;
}

int main()
{
	//store a class roster instance
	roster classRosterInstance;


	#pragma region Seed StudentData
	//for each student in student data
	for (string _sDataString : classRosterInstance.studentData)
	{
		//string stream to edit
		stringstream ss(_sDataString);
		//where the result of the splitting goes to
		vector<string> sDataArray;
		degree degInstance;

		while (ss.good())
		{
			string splitedString;
			getline(ss, splitedString, ',');
			sDataArray.push_back(splitedString);

		}

		if (sDataArray[8] == "NETWORK")
		{
			degInstance = degree::NETWORK;
		}
		if (sDataArray[8] == "SECURITY")
		{
			degInstance = degree::SECURITY;
		}
		if (sDataArray[8] == "SOFTWARE")
		{
			degInstance = degree::SOFTWARE;
		}

		//create the roster using the vector and degree
		classRosterInstance.add(sDataArray[0], sDataArray[1], sDataArray[2], sDataArray[3],
			atoi(sDataArray[4].c_str()), atoi(sDataArray[5].c_str()), atoi(sDataArray[6].c_str()),
			atoi(sDataArray[7].c_str()), degInstance);

	}
	#pragma endregion

	classRosterInstance.printMyInfo();

	classRosterInstance.printAll();
	classRosterInstance.printInvalidEmails();
	classRosterInstance.printAverageDaysInCourse("A1");
	classRosterInstance.printByDegreeProgram(degree::SECURITY);
	classRosterInstance.remove("A3");
	classRosterInstance.remove("A3");		

	return 0;

}
//Roster destroyer
roster::~roster()
{

}