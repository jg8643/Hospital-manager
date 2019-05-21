#pragma once
#include "SW_TestDlg.h"
#include "Setting.h"
#include "pdata.h"
class Patient
{
public:
	Patient(Setting *);
	~Patient();

	int pcount;
	Setting *set;
	CSWTestDlg *myswdlg;
	pdata *patdata[100];
	void ReadPatFile();
};

