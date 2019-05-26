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
// 환자 파일 읽기
void Patient::ReadPatFile() {
	char buf[1024];
	char *temp[10];
	FILE *fin = fopen("patient.txt", "r");


	while (!feof(fin)) {
		fgets(buf, sizeof(buf), fin);
		temp[0] = strtok(buf, "|");
		for (int i = 1; i < 10; i++) {
			// "ㅣ" 기준으로 단어 나누기
			temp[i] = strtok(NULL, "|\n");
		}
		patdata[pcount++] = new pdata(temp);

	}

	fclose(fin);
}
// 환자 파일 쓰기
void Patient::WritePatFile()
{
	CStringA charstr[7];
	FILE *fout = fopen("patient.txt", "w+");
	for (int i = 0; i < pcount - 1; i++) {
		for (int j = 0; j < 7; j++) {
			charstr[j] = CStringA(patdata[i]->p_data[j]);
		}
		for (int i = 0; i < 6; i++) {
			fprintf(fout, "%s", charstr[i] + "|");
		}
		fprintf(fout, "%s\n", charstr[6]);
	}
	for (int i = 0; i < 7; i++) {
		charstr[i] = CStringA(patdata[pcount - 1]->p_data[i]);
	}
	for (int i = 0; i < 6; i++) {
		fprintf(fout, "%s", charstr[i] + "|");
	}
	fprintf(fout, "%s", charstr[6]);
	fclose(fout);
}
