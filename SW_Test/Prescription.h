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
	int tcount;            // 진료 완료 환자 수
	predata *pre_data[100];   // 진료 완료 환자 
	void CreatePre(CString *, CString (*str)[2]);
};

