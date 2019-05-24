#include "stdafx.h"
#include "Prescription.h"
#include "SW_TestDlg.h"
#include "Setting.h"

Prescription::Prescription(Setting *set)
{
	this->set = set;
	myswdlg = (CSWTestDlg*)::AfxGetMainWnd();
	tcount = 0;
}


Prescription::~Prescription()
{
}

void Prescription::CreatePre(CString *temp, CString (*str)[2])
{
	pre_data[tcount++] = new predata(temp, str);
}
