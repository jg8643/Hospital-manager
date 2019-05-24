#pragma once
class predata
{
public:
	predata();
	predata(CString *, CString(*str)[2]);
	~predata();

	CString patnum;
	CString treat;
	CString medication[100][2];
};

