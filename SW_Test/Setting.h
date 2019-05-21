#pragma once
class Employee;
class CSWTestDlg;
class Patient;
class Setting
{
public:
	Setting(CSWTestDlg*);
	~Setting();

	Employee *emp;
	Patient *pat;
	CString wait[100];
	int wait_count;
};

