#include "stdafx.h"
#include "pdata.h"


pdata::pdata()
{
}

pdata::pdata(char **a)
{
	for (int i = 0; i < 7; i++)
		this->p_data[i] = a[i];
}


pdata::~pdata()
{
}
