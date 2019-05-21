#include "stdafx.h"
#include "edata.h"


edata::edata()
{
}


edata::edata(char **a)
{
	for (int i = 0; i < 10; i++)
		this->e_data[i] = a[i];
}
edata::edata(CString *a) {
	for (int i = 0; i < 10; i++)
		this->e_data[i] = a[i];
}

edata::~edata()
{
}
