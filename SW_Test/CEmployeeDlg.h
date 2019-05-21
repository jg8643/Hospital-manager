#pragma once


// CEmployeeDlg 대화 상자
class Setting;
class CSWTestDlg;
class CEmpTab1Dlg;
class CEmpTab2Dlg;
class CEmpTab3Dlg;
class CEmployeeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEmployeeDlg)

public:
	CEmployeeDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CEmployeeDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CEmployeeDlg(CEmployeeDlg*);
	Setting *set;
	CSWTestDlg *myswdlg;
	CEdit  *pedit[9];
	CTabCtrl m_tabctrl;
	CEmpTab1Dlg *cet1;
	CEmpTab2Dlg *cet2;
	CEmpTab3Dlg *cet3;
	void SetInformation(int);
	void Update();
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton10();
};
