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

	Employee *emp;            // ����
	Patient *pat;             // ȯ��
	Prescription *pre;        // ó��
	CString wait[100];        // ��⸮��Ʈ(ȯ��)
	CString complet[100];     // �ϷḮ��Ʈ(ȯ��)
	int wait_count;           // ��� ��
	int complet_count;        // �Ϸ� ��
};

