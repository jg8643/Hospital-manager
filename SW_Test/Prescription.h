#pragma once
#include "SW_TestDlg.h"
#include "Setting.h"
#include "predata.h"
class Prescription
{
public:
	Prescription(Setting *);
	~Prescription();
	Setting *set;
	CSWTestDlg *myswdlg;
	int tcount;
	predata *pre_data[100];
	void CreatePre(CString *, CString (*str)[2]);
};

