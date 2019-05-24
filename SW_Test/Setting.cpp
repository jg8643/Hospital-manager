#include "stdafx.h"
#include "Setting.h"
#include "SW_TestDlg.h"
#include "Employee.h"
#include "Patient.h"
#include "Prescription.h"
Setting::Setting(CSWTestDlg * p_mainFrm)
{
	emp = new Employee(this);
	pat = new Patient(this);
	pre = new Prescription(this);
	wait_count = 0;
	complet_count = 0;
}


Setting::~Setting()
{
}
