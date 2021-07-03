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
#include"projectmanagement.h"
using namespace std;

void projectCoordinator::getdata()
{
	cout << "Enter Group no: ";
	cin.getline(groupno, 40);
	cout << "Enter project status: ";
	cin.getline(projstatus, 40);
}
void student::getdata()
{
	cout << "Enter First Student Name: ";
	cin.getline(stuname1, 100);
	cout << "Enter Second Student Name: ";
	cin.getline(stuname2, 100);

	cout << "Enter Student Class: ";
	cin.getline(stuclass, 100);
	cout << "Enter First Student Enrollment: ";
	cin.getline(stuenroll1, 100);
	cout << "Enter Second Student Enrollment: ";
	cin.getline(stuenroll2, 100);

}
void supervisor::getdata()
{
	cout << "Enter Supervisor name: ";
	cin.getline(supname, 100);
	cout << "Enter Email: ";
	cin.getline(email, 100);
	cout << "Enter Project name: ";
	cin.getline(projname, 100);
	cout << "Enter Deadline for project: \n";
	cout << "Day: "; cin.getline(deadday, 40);
	cout << "Month: "; cin.getline(deadmonth, 40);
	cout << "Year: "; cin.getline(deadyear, 40);
}
void supervisor::writetopic()
{
	supervisor SO;

	ofstream wr("superlist.dat,ios::app|ios::out");
	if (!wr)
	{
		cout << "Error opening File!\n";
	}
	else
	{
		cin.ignore();
		cout << "Enter supervior name: ";
		cin.getline(SO.supname, 100);
		cout << "Enter First Topic: ";
		cin.getline(SO.topic1, 100);
		cout << "Enter Second Topic: ";
		cin.getline(SO.topic2, 100);
		cout << "Enter Third Topic: ";
		cin.getline(SO.topic3, 100);
		cout << "Enter Fourth Topic: ";
		cin.getline(SO.topic4, 100);
		wr.write((char*)&SO, sizeof(SO));
		cout << "Topic List File written succefully\n";
		wr.close();
	}
}
void supervisor::displaytoplist()
{
	char usname[100];
	cout << "Following Supervisors are available: \n";
	cout << "Aliya Amir - Sikandar Hayat\n";
	cin.getline(usname, 100);
	supervisor SM;
	ifstream ir;
	ir.open("suoerlist.dat");
	if (!ir)
	{
		cout << "Error opening requested File!\n";
	}
	else
	{
		while (ir.read((char*)&SM, sizeof(SM)))
		{
			if (strcmp(usname, SM.supname) == 0)
			{
				cout << "Topic 1: " << SM.topic1 << endl;
				cout << "Topic 2: " << SM.topic2 << endl;
				cout << "Topic 3: " << SM.topic3 << endl;
				cout << "Topic 4: " << SM.topic4 << endl;

			}
		}
		ir.close();
	}
}

void evaluator::getevalmarks()
{
	cout << "Evaluator! Kindly enter Marks for this Project\n";
	cin.getline(evalmarks, 100);
}

void projectmanagement::getdata()//get function which involves getter of all three base classes involved
{
	projectCoordinator::getdata();
	student::getdata();
	supervisor::getdata();
}
void projectmanagement::writefile()//function for creating a major Group object and writing it into Main File
{
	int n = 2;
	projectmanagement PM;
	ofstream wr("TestData.dat", ios::app | ios::out);
	if (!wr)
	{
		cout << "Error! Requested File could not be opened\n";

	}
	else
	{
		while (n == 2)
		{
			cin.ignore();
			PM.getdata();
			wr.write((char*)&PM, sizeof(PM));
			cout << "File written Succesfully \n";
			cout << "Press 2 if you want To enter another Record\n";
			cin >> n;

		}
		wr.close();

	}
}

void projectmanagement::display()//function for displaying the main group object present in the Main File
{
	projectmanagement PO;
	ifstream ir;
	ir.open("TestData.dat");
	if (!ir)
	{
		cout << "Error Opening File!\n";
	}
	else
	{
		while (ir.read((char*)&PO, sizeof(PO)))
		{
			cout << PO;
			cout << endl;
		}
		ir.close();
	}
}
void projectmanagement::sviewsuper()//function by which student can view it'ssupervisor's information
{
	projectmanagement PI;

	char usenroll[100];
	cin.ignore();
	cout << "Dear Student enter your Group no: \n";
	cin >> usenroll;
	ifstream ir;
	ir.open("TestData.dat");
	while (ir.read((char*)&PI, sizeof(PI)))
	{
		if (strcmp(usenroll, PI.groupno) == 0)
		{
			cout << "Group no: " << PI.groupno << endl;
			cout << "Project Supervisor: " << PI.supname << endl;
			cout << "Supervisor Email: " << PI.email << endl;
		}

	}
	ir.close();


}
void projectmanagement::studentedit()//function by which students can edit teir Profile
{
	projectmanagement PI;

	char usgrouupno[100];
	cin.ignore();
	cout << "Dear Student enter your Group no: \n";
	cin.getline(usgrouupno, 100);



	fstream wr("TestData.dat", ios::in | ios::out);
	wr.seekg(0);
	while (wr.read((char*)&PI, sizeof(PI)))
	{
		if (strcmp(usgrouupno, PI.groupno) == 0)
		{
			cin.ignore();
			cout << "Enter new name for 1st Student: ";
			cin.getline(PI.stuname1, 100);
			cout << "Enter new name for 2nd Student: ";
			cin.getline(PI.stuname2, 100);
			cout << "Enter new Enrollment for 1st Student: ";
			cin.getline(PI.stuenroll1, 100);
			cout << "Enter new Enrollment for 2nd Student: ";
			cin.getline(PI.stuenroll2, 100);
			wr.seekp(-(long int)sizeof(PI), ios::cur);
			wr.write((char*)&PI, sizeof(PI));
			break;

		}

	}

	wr.close();
}

void projectmanagement::supervisoredits()//function by which supervisor can edit project profile
{
	projectmanagement PI;

	char usgroupno[100];
	cin.ignore();
	cout << "Enter Group No for which you want To Edit: \n";
	cin.getline(usgroupno, 100);



	fstream wr("TestData.dat", ios::in | ios::out);
	wr.seekg(0);
	while (wr.read((char*)&PI, sizeof(PI)))
	{
		if (strcmp(usgroupno, PI.groupno) == 0)
		{
			cin.ignore();
			cout << "Enter new Deadline: \n";
			cout << "Day: "; cin.getline(PI.deadday, 40);
			cout << "Month: "; cin.getline(PI.deadmonth, 40);
			cout << "Year: "; cin.getline(PI.deadyear, 40);
			cout << "Enter project Status: ";
			cin.getline(PI.projstatus, 100);
			wr.seekp(-(long int)sizeof(PI), ios::cur);
			wr.write((char*)&PI, sizeof(PI));
			break;

		}

	}

	wr.close();
}
void projectmanagement::supervisortotalgroups()//function by which a supervisor can view Total no of Groups assigned to him/her
{
	projectmanagement PI;
	int total = 0;
	char ussupnamee[100];
	cin.ignore();
	cout << "Dear Supervisor - Enter your Full Name: \n";
	cin.getline(ussupnamee, 100);
	ifstream ir;
	ir.open("TestData.dat");
	while (ir.read((char*)&PI, sizeof(PI)))
	{
		if (strcmp(ussupnamee, PI.supname) == 0)
		{
			total++;
		}
	}
	ir.close();
	cout << "Total no of Groups assigned to Mr/Ms " << ussupnamee << " is " << total << endl;

}
void projectmanagement::supdstupro()//function by which supervisor can view student&project profile
{
	projectmanagement PI;
	char usgroupNo[100];
	cin.ignore();
	cout << "Dear Supervisor! Enter the Group No for which you want to see the Student + Project Details\n";
	cin.getline(usgroupNo, 100);
	ifstream ir;
	ir.open("TestData.dat");
	if (!ir)
	{
		cout << "Error opening requested File\n";

	}
	else
	{
		while (ir.read((char*)&PI, sizeof(PI)))
		{
			if (strcmp(usgroupNo, PI.groupno) == 0)
			{
				cout << "Group no: " << PI.groupno << endl;
				cout << "Project: " << PI.projname << endl;
				cout << "Project Status: " << PI.projstatus << endl;
				cout << "1st Student name: " << PI.stuname1 << endl;
				cout << "2nd Student name: " << PI.stuname2 << endl;
				cout << "Class & Sec: " << PI.stuclass << endl;
				cout << "1st Student Enrollment# " << PI.stuenroll1 << endl;
				cout << "2nd Student Enrollment# " << PI.stuenroll2 << endl;
				cout << "Project Deadline: " << PI.deadday << "/" << PI.deadmonth << "/" << PI.deadyear << endl;
				cout << "\t\t\t*******Thank You!*******\t\t\t\n";
			}
		}
		ir.close();
	}
}
void projectmanagement::studentsubmits()//function by which student can submit their Final Year Project
{
	projectmanagement PI;
	char usGroupno[100];
	cout << "\t\t\t**Welcome To Projet Submission portal!...\n";
	cin.ignore();
	cout << "Enter your Group No: ";
	cin.getline(usGroupno, 100);
	ofstream wr("SubmittedProjects.dat");
	ifstream ir;
	ir.open("TestData.dat");
	if (!ir)
	{
		cout << "Error Opening Requested File!\n";
	}
	else
	{
		while (ir.read((char*)&PI, sizeof(PI)))
		{
			if (strcmp(usGroupno, PI.groupno) == 0)
			{
				int endline = (atoi(PI.deadyear) * 10000) + (atoi(PI.deadmonth) * 100) + (atoi(PI.deadday));

				cout << "For confirmation! Enter Submitted button\n";
				cin.getline(PI.projstatus, 100);
				cout << "Enter Submission Date: \n";
				cout << "Day: "; cin.getline(PI.submitday, 100);
				cout << "Month: "; cin.getline(PI.submitmonth, 100);
				cout << "Year: "; cin.getline(PI.submityear, 100);
				strcpy_s(PI.supermarks, "nil");
				strcpy_s(PI.evalmarks, "nil");
				PI.Totalx = 0;
				int submitdate = (atoi(PI.submityear) * 10000) + (atoi(PI.submitmonth) * 100) + (atoi(PI.submitday));
				if (submitdate <= endline)
				{
					cout << "\t***Submitted***\t\t\n";
					wr.write((char*)&PI, sizeof(PI));
					cout << "Written in seperate File - Succesfully!\n";
				}
				else
				{
					cout << "Deadline exceeded - You'r Late.../\n";
				}


			}
		}
	}
	ir.close();
	wr.close();

}
void projectmanagement::displaysubmittedprojects()//function which displays all the submitted projects info
{
	projectmanagement PI;
	int i = 1;
	ifstream ir;
	ir.open("SubmittedProjects.dat");
	while (ir.read((char*)&PI, sizeof(PI)))
	{
		cout << "Project no: " << i++ << endl << endl;
		cout << "Supervisor Marks: " << PI.supermarks << endl;
		cout << "Evaluator Marks: " << PI.evalmarks << endl;
		cout << "Total Marks of This Project: " << PI.Totalx << endl;
		cout << "Submission Date: " << PI.submitday << "/" << PI.submitmonth << "/" << PI.submityear << endl;
		cout << PI << endl;

	}
	ir.close();
}
void projectmanagement::calculateresultsuper()//function which is used by supervisor for marking
{
	projectmanagement PI;
	char sugroupno[100];
	cin.ignore();
	cout << "\t\t\t***Supervisor Marking Portal***\t\t\t\n\n";
	fstream obj;
	obj.open("SubmittedProjects.dat", ios::in | ios::out);
	cout << "Enter Group No for which you want to Mark:\n ";
	cin.getline(sugroupno, 100);
	while (obj.read((char*)&PI, sizeof(PI)))
	{
		if (strcmp(sugroupno, PI.groupno) == 0)
		{
			cout << "Supervisor! Kindly enter Marks for this Project\n";
			cin.getline(PI.supermarks, 100);
			obj.seekp(-(long int)sizeof(PI), ios::cur);
			obj.write((char*)&PI, sizeof(PI));
			break;
		}
		else
		{
			cout << "Group No Not Found!!\n";
		}
	}
	obj.close();

}
void projectmanagement::calculateresulteval()//function which is used by evaluator for marking & It also calculates total
{

	projectmanagement PI;
	char sugroupno[100];
	cin.ignore();

	cout << "\t\t\t***Evaluator Marking Portal***\t\t\t\n\n";
	fstream obj;
	obj.open("SubmittedProjects.dat", ios::in | ios::out);
	cout << "Enter Group No for which you want to Mark:\n ";
	cin.getline(sugroupno, 100);
	while (obj.read((char*)&PI, sizeof(PI)))
	{
		if (strcmp(sugroupno, PI.groupno) == 0)
		{
			PI.getevalmarks();
			PI.Totalx = (atoi(PI.supermarks) + atoi(PI.evalmarks));
			obj.seekp(-(long int)sizeof(PI), ios::cur);
			obj.write((char*)&PI, sizeof(PI));
			break;
		}
		else
		{
			cout << "Group No Not Found!!\n";
		}
	}
	obj.close();
}
