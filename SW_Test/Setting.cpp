#include "stdafx.h"
#include "Setting.h"
#include "SW_TestDlg.h"
#include "Employee.h"
#include "Patient.h"
Setting::Setting(CSWTestDlg * p_mainFrm)
{
	emp = new Employee(this);
	pat = new Patient(this);
	wait_count = 0;
}


Setting::~Setting()
{
}
