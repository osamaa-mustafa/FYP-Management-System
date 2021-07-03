#pragma once
#pragma once
#include<iostream>//header file for input/output streams
#include<conio.h>
#include<string>//header file for string operations
#include<sstream>//header file for converting string - int
#include<fstream>//header file for using files 
#include<stdlib.h>
#include"projectCoordinator.h"
#include"student.h"
#include"supervisor.h"
#include"evaluator.h"
using namespace std;

class projectmanagement :public student, supervisor, projectCoordinator, evaluator {
public://initiazlizing class Data
	char submitday[100];
	char submitmonth[100];
	char submityear[100];
	int Totalx;
public:
	void getdata();//get function which involves getter of all three base classes involved
	
	void writefile();//function for creating a major Group object and writing it into Main File
	
	
	friend ostream& operator<<(ostream& output, projectmanagement PO)//overloading output operator
	{
		output << "Group no: " << PO.groupno << endl << "Project Status: " << PO.projstatus << endl << " 1st Student name: " << PO.stuname1 << endl << "2nd Student name: " << PO.stuname2 << endl << "Student class: " << PO.stuclass << endl << "1st Student Enrollment#" << PO.stuenroll1 << endl << "2nd Student Enrollment# " << PO.stuenroll2 << endl << "Supervisor name: " << PO.supervisor::supname << endl << "Supervisor email: " << PO.email << endl << "Project Deadline- " << PO.deadday << "/" << PO.deadmonth << "/" << PO.deadyear << endl;
		return output;
	}
	void display();//function for displaying the main group object present in the Main File
	
	void sviewsuper();//function by which student can view it'ssupervisor's information
	
	void studentedit();//function by which students can edit teir Profile
	

	void supervisoredits();//function by which supervisor can edit project profile
	
	void supervisortotalgroups();//function by which a supervisor can view Total no of Groups assigned to him/her
	
	void supdstupro();//function by which supervisor can view student&project profile
	
	void studentsubmits();//function by which student can submit their Final Year Project
	
	void displaysubmittedprojects();//function which displays all the submitted projects info
	
	void calculateresultsuper();//function which is used by supervisor for marking
	
	void calculateresulteval();//function which is used by evaluator for marking & It also calculates total
	

};
