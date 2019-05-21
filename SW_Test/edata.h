#pragma once
class edata
{
public:
	edata();
	edata(char **);
	edata(CString *);
	~edata();

	CString e_data[10];
};

