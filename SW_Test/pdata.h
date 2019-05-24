#pragma once
class pdata
{
public:
	pdata();
	pdata(char**);
	pdata(CString *);
	~pdata();

	CString p_data[7];
};

