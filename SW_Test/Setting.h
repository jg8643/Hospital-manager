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

	Employee *emp;
	Patient *pat;
	Prescription *pre;
	CString wait[100];
	CString complet[100];
	int wait_count;
	int complet_count;
};

