#include "stdafx.h"
#include "Employee.h"
#include "Setting.h"
#include "SW_TestDlg.h"

Employee::Employee(Setting *set)
{
	this->set = set;
	ecount = 0;
	dcount = 0;
	ncount = 0;
	scount = 0;
	myswdlg = (CSWTestDlg*)::AfxGetMainWnd();
	ReadEmpFile();
}


Employee::~Employee()
{
}

void Employee::ReadEmpFile()
{
	char buf[1024];
	char *temp[10];
	FILE *fin = fopen("employee.txt", "r");


	while (!feof(fin)) {
		fgets(buf, sizeof(buf), fin);
		temp[0] = strtok(buf, "|");
		for (int i = 1; i < 10; i++) {
			// "ㅣ" 기준으로 단어 나누기
			temp[i] = strtok(NULL, "|");
		}
		empdata[ecount++] = new edata(temp);
		
	}

	fclose(fin);
}

void Employee::WriteEmpFile()
{
	CStringA charstr[10];

	FILE *fout = fopen("employee.txt", "w+");
	for (int i = 0; i < ecount; i++) {
		for (int j = 0; j < 10; j++) {
			charstr[j] = CStringA(empdata[i]->e_data[j]);
		}
		for (int i = 0; i < 9; i++) {
			fprintf(fout, "%s", charstr[i] + "|");
		}
		fprintf(fout, "%s", charstr[9]);
	}
	fclose(fout);
}
