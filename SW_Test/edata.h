#pragma once
class edata
{
public:
	edata(char **);
	edata(CString *);
	~edata();

	CString e_data[10];   // ���� �� ����
};

