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

int main()
{
g:	system("cls");
	int choice1, choice2, choice3, choice4, choice5, choice6, choice7, choice8;
	cout << "          *****************************************************\n  ";
	cout << "          *******************************************************\n  ";
	cout << "          ************** BAHRIA FYP Management System.() ******\n";
	cout << "          *******************************************************\n  ";
	cout << "          *******************************************************\n  ";
	cout << "          *****************************************************\n  ";
	cout << "1)Press 1 To Enter Project Administrater Portal\n";
	cout << "2)Press 2 To Enter Student Portal\n";
	cout << "3)Press 3 To Enter Supervisor Portal\n";
	cout << "4)Press 4 To Enter Marking Portal(Only For Evaluators&Supervisors)\n";
	cout << "5) Press 5 To Display Marks Sheet on Board\n";
	cout << "6)Press 6 to Exit...\n";
	cin >> choice1;
	switch (choice1)
	{
	case 1:
	{
		system("cls");
		cout << "\t\t\t***Project Administrator Portal\t\t\t***\n\n";
		cout << "Press 1 To Register Groups for Final Year Project...\n";
		cout << "Press 2 To GOTO Main Menu...\n";
		cin >> choice2;
		if (choice2 == 1)
		{
			projectmanagement PM;
			PM.writefile();
			cout << "\n\n";
			PM.display();
			system("pause");
			goto g;
		}
	    if(choice2==2)
		{
			goto g;
		}
	}
	case 2:
	{
h:		system("cls");
		cout << "\t\t\t***((Student Portal))***\t\t\t\n\n";
		cout << "1)Press 1 if you want to see your Supervisor's profile>\n";
		cout << "2)Press 2 if you want to Edit your profile>\n";
		cout << "3)Press 3 to Submit your Final Project>\n";
		cout << "4)Press 4 to Display Supervisors Topics List>\n";
		cout << "4)Press 9 to GOTO Main Menu>\n";
		cin >> choice3;
		if (choice3 == 1)
		{
			projectmanagement PM;
			PM.sviewsuper();
			system("pause");
			cout << "\n\n";
			goto h;
		}
		if (choice3 == 2)
		{
			projectmanagement PM;
			PM.studentedit();
			system("pause");

			cout << "\n\n";
			goto h;
		}
		if (choice3 == 3)
		{
			projectmanagement PM;
			PM.studentsubmits();
			system("pause");

			cout << endl<<endl;
			goto h;
		}
		if (choice3 == 4)
		{
			supervisor SO;
			SO.displaytoplist();
			system("pause");

			cout << endl << endl;
			goto h;
		}
		if (choice3 == 9)
		{
			goto g;
		}
	}
	case 3:
	{
		system("cls");
i:		cout << "\t\t\t**********(((Supervisor Portal)))***********\t\t\t\n\n";
		cout << "1)Pressing 1 - You can Edit Project Status and Deadline by Entering Group no>\n";
		cout << "2)Pressing 2 - You can View Total no: of Groups assigned to you by Entering your Name>\n";
		cout << "3)Pressing 3 - You can view Student & Project Profile by Entering Group no>\n";
		cout << "4)Pressing 4 - You can view the Total Projects Submitted by Students>\n";
		cout << "6)Pressing 6 - To Add your Topics List>\n";
		cout << "5)Pressing 5 - Will Take you To Main Menu>\n";
		cin >> choice4;
		if (choice4 == 1)
		{
			projectmanagement PM;
			PM.supervisoredits();
			cout << endl << endl;
			PM.display();
			system("pause");

			cout << endl;
			goto i;
		}
		if (choice4 == 2)
		{
			projectmanagement PM;
			PM.supervisortotalgroups();
			system("pause");

			cout << endl << endl;
			goto i;
		}
		if (choice4 == 3)
		{
			projectmanagement PM;
			PM.supdstupro();
			system("pause");

			cout << endl << endl;
			goto i;
		}
		if (choice4 == 4)
		{
			projectmanagement PM;
			PM.displaysubmittedprojects();
			system("pause");

			cout << "\n\n";
			goto i;
		}
		if (choice4 == 6)
		{
			supervisor SM;
			SM.writetopic();
			system("pause");

			cout << "\n\n";
			goto i;
		}
		if(choice4==5)
		{
			goto g;
		}
	}
	case 4:
	{
	j:      system("cls");
		cout << "\t\t\t*******MARKING PORTAL.********\t\t\t\n\n";
		cout << "1)Press 1 if you are a supervisor and wants To Mark a Project>\n";
		cout << "2)Press 2 if you are a Evaluator and wants To Mark a Project>\n";
		cout << "3)Pressing 3 will Take you To Main Menu>\n";
		cin >> choice5;
		if (choice5 == 1)
		{
			projectmanagement PLD;
			PLD.calculateresultsuper();
			cout << "\n\n";
			PLD.displaysubmittedprojects();
			system("pause");

			cout << "\n";
			goto j;
		}
		if (choice5 == 2)
		{
			projectmanagement PLD;
			PLD.calculateresulteval();
			cout << "\n\n";
			PLD.displaysubmittedprojects();
			system("pause");

			cout << "\n";
			goto j;
		}
		if (choice5 == 3)
		{
			goto g;
		}

	}
	case 5:
	{
		system("cls");
		projectmanagement resultlist;
		cout << "\t\t\t<<<Results Display Board>>>\t\t\t\n\n";
		cout << "Intructions...\n";
		cout << ">>Nil shows that you have not been marked by that person yet...|\n";
		cout << ">>Supervisor Marks are given by your Internal supervisor...|\n";
		cout << ">>Evaluator Marks are given by External Evaluator\n";
		cout << ">>>Total Marks are your Final Result...|Thank You!<> ) \n";
		cout << endl;
		resultlist.displaysubmittedprojects();
		system("pause");
		cout << "\n\n";
		goto g;
		
	}
	case 6:
		cout << "Thank You Bye! Bye!\n\n\n";
		system("pause");
		exit(0);
	default:
		cout << "Invalid Selection Made...|\n";
		goto g;
	}


	
	
    system("pause");
	return 0;
}