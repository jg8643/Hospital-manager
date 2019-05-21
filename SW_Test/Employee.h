#pragma once
#include "SW_TestDlg.h"
#include "Setting.h"
#include "edata.h"
class Employee
{
public:
	Employee(Setting *);
	~Employee();

	int ecount;
	Setting *set;
	CSWTestDlg *myswdlg;
	edata *empdata[100];
	void ReadEmpFile();
};

