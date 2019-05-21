#include "stdafx.h"
#include "Patient.h"
#include "Setting.h"
#include "SW_TestDlg.h"

Patient::Patient(Setting *set)
{
	this->set = set;
	pcount = 0;
	myswdlg = (CSWTestDlg*)::AfxGetMainWnd();
	ReadPatFile();
}


Patient::~Patient()
{
}
void Patient::ReadPatFile() {
	char buf[1024];
	char *temp[10];
	FILE *fin = fopen("patient.txt", "r");


	while (!feof(fin)) {
		fgets(buf, sizeof(buf), fin);
		temp[0] = strtok(buf, "|");
		for (int i = 1; i < 10; i++) {
			// "ㅣ" 기준으로 단어 나누기
			temp[i] = strtok(NULL, "|");
		}
		patdata[pcount++] = new pdata(temp);

	}

	fclose(fin);
}