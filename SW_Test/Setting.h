#pragma once
class Employee;
class CSWTestDlg;
class Patient;
class Prescription;
class Setting
{
public:
	Setting(CSWTestDlg*);
	~Setting();

	Employee *emp;            // 직원
	Patient *pat;             // 환자
	Prescription *pre;        // 처방
	CString wait[100];        // 대기리스트(환자)
	CString complet[100];     // 완료리스트(환자)
	int wait_count;           // 대기 수
	int complet_count;        // 완료 수
};

