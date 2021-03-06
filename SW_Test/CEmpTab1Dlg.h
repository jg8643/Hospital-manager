﻿#pragma once


// CEmpTab1Dlg 대화 상자
class CSWTestDlg;
class Setting;
class CEmployeeDlg;
class CEmpTab1Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEmpTab1Dlg)

public:
	CEmpTab1Dlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CEmpTab1Dlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CEmpTab1Dlg(CEmployeeDlg *);  // 생성자
	CEmployeeDlg *cempdlg;
	Setting *set;
	CSWTestDlg *myswdlg;
	CListCtrl m_listctrl;
	int select;      // 더블클릭 시 인덱스 
	int mark;        // 클릭 시 인덱스
	void Update();
	void Delete();
	virtual BOOL OnInitDialog();
	afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
