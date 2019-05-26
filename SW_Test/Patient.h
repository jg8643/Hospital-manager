#pragma once
#include "SW_TestDlg.h"
#include "Setting.h"
#include "pdata.h"
class Patient
{
public:
	Patient(Setting *);
	~Patient();

	int pcount;     // 환자 수
	Setting *set;
	CSWTestDlg *myswdlg;
	pdata *patdata[100];    // 환자
	void ReadPatFile();     // 환자 파일 읽기
	void WritePatFile();    // 환자 파일 쓰기
};

