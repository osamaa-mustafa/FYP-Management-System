#pragma once
#pragma once
#include<iostream>//header file for input/output streams
#include<conio.h>
#include<string>//header file for string operations
#include<sstream>//header file for converting string - int
#include<fstream>//header file for using files 
#include<stdlib.h>
using namespace std;

class supervisor {
protected://initializing supervisor class Data
	char supname[100];
	char email[100];
	char projname[100];
	char topic1[100];
	char topic2[100];
	char topic3[100];
	char topic4[100];
	char deadday[40];
	char deadmonth[40];
	char deadyear[40];
	char supermarks[100];

public:
	void getdata();//function for getting data from user

	void writetopic();//function by which supervisor can create its topic list in another file
	
	void displaytoplist();//function by which supervisor can display its own Topic list so students can see
	
};
