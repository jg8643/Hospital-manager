#include "stdafx.h"
#include "predata.h"


predata::predata()
{
}

predata::predata(CString *temp, CString(*str)[2])
{
	this->patnum = temp[0];
	this->treat = temp[1];
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 2; j++) {
			this->medication[i][j] = str[i][j];
		}
	}
}

predata::~predata()
{
}
