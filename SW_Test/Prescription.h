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
	int tcount;            // ���� �Ϸ� ȯ�� ��
	predata *pre_data[100];   // ���� �Ϸ� ȯ�� 
	void CreatePre(CString *, CString (*str)[2]);
};

