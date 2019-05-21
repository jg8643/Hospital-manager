#pragma once


// CEmpTab2Dlg 대화 상자
class CSWTestDlg;
class Setting;
class CEmployeeDlg;
class CEmpTab2Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEmpTab2Dlg)

public:
	CEmpTab2Dlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CEmpTab2Dlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CEmpTab2Dlg(CEmployeeDlg *);  // 생성자
	int select;
	CEmployeeDlg *cempdlg;
	Setting *set;
	CSWTestDlg *myswdlg;
	CListCtrl m_listctrl;
	void Update();
	virtual BOOL OnInitDialog();
	afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
};
