#pragma once
#include "SW_TestDlg.h"
#include "Setting.h"
#include "pdata.h"
class Patient
{
public:
	Patient(Setting *);
	~Patient();

	int pcount;     // ȯ�� ��
	Setting *set;
	CSWTestDlg *myswdlg;
	pdata *patdata[100];    // ȯ��
	void ReadPatFile();     // ȯ�� ���� �б�
	void WritePatFile();    // ȯ�� ���� ����
};

