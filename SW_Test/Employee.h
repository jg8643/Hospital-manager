#pragma once
#include "SW_TestDlg.h"
#include "Setting.h"
#include "edata.h"
class Employee
{
public:
	Employee(Setting *);
	~Employee();

	int ecount;     // 총 직원 수
	int dcount;     // 의사 수
	int ncount;     // 간호사 수
	int scount;     // 기술스태프 수
	Setting *set;
	CSWTestDlg *myswdlg;
	edata *empdata[100];      // 직원 정보
	void ReadEmpFile();       // 직원 파일 읽기
	void WriteEmpFile();      // 직원 파일 쓰기
};

