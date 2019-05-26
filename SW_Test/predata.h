#pragma once
class predata
{
public:
	predata();
	predata(CString *, CString(*str)[2]);
	~predata();

	CString patnum;       // 진료 완료 환자 번호
	CString treat;        // 진료내용
	CString medication[100][2];    // 약재 처방
};

