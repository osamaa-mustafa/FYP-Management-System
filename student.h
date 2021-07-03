#pragma once
#pragma once
#include<iostream>//header file for input/output streams
#include<conio.h>
#include<string>//header file for string operations
#include<sstream>//header file for converting string - int
#include<fstream>//header file for using files 
#include<stdlib.h>
using namespace std;

class student {
protected:
	char stuname1[100];//intializing student class data
	char stuname2[100];
	char stuclass[100];
	char stuenroll1[100];
	char stuenroll2[100];

	char sstuprojname[100];
public:
	void getdata();//function for getting Data from user
	
};
